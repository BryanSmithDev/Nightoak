/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Actor Class
*/

#include "GameActor.h"
#include "GameRoom.h"


//Constructor w/ parameters
GameActor::GameActor(int i, string b, string c, GameRoom* l, int h):GameObject(i, b, c){
	location = l;
	health = h;
	maxHealth=h;
	strength=1;
	defense=0;
	inv = GameContainer(i,b+"'s Inventory",b+"'s Inventory");
	setSwordHandItem(NULL);
	setShieldHandItem(NULL);
	setHostile(false);
}

//getHealth
int GameActor::getHealth(){
	return health;
}

//setHealth
void GameActor::setHealth(int h){
	health = h;
	if (health>getMaxHealth()) health=getMaxHealth();
}

//getStrength
int GameActor::getStrength(){
	return strength;
}

//setStrength
void GameActor::setStrength(int s){
	strength = s;
}

//getDefense
int GameActor::getDefense(){
	return defense;
}

//setDefense
void GameActor::setDefense(int d){
	defense = d;
}

//getLocation
GameRoom* GameActor::getLocation(){
	return location;
}

//setlocation
void GameActor::setLocation(GameRoom* l){
	location = l;
}

//Returns what the actor says
string GameActor::getSpeach(){
		return speach;
}

//Sets the actors talk message
void GameActor::setSpeach(string s){
		speach=s;
}

//Sets the inventory of the actor
void GameActor::setInventory(GameContainer i){
	inv = i;
}

//Returns the inventory of the actor
GameContainer* GameActor::getInventory(){
	return &inv;
}

//sets the max health of the actor
void GameActor::setMaxHealth(int m){
	maxHealth=m;
}

//gets the max health of the actor
int GameActor::getMaxHealth(){
	return maxHealth;
} 

//Actor has specified item?
bool GameActor::hasItem(GameItem* i){
	return getInventory()->hasItem(i);
}

//Drop item
void  GameActor::dropItem(GameItem* i){
	if (getInventory()->getCount() >0){
		if (getInventory()->hasItem(i)){
			if (i->getDrop()){
				getLocation()->addItem(i);
				getInventory()->removeItem(i);
				if (getLocation()->hasItem(i)) cout<<"     "<<i->getName()<<endl;
			}
		}
	}
}



//Actor drops all held items
void GameActor::dropAllItems() {
	if (getInventory()->getCount() >0){
		linkedListIterator<GameItem*> it;
		it = getInventory()->getItemsIterator();
		for(int i =0; i<getInventory()->getCount();i++){
			dropItem((*it));
			++it;
		}
	}
}

//Actor attacks another
void GameActor::attack(GameActor* p){
	
		int damage2 = (strength-(p->defense))>=0?(strength-(p->defense)):0;
		p->setHealth(p->getHealth()-damage2);
		cout << getName() << " attacks " << p->getName() << " dealing " << damage2 << " damage!  -  "<<p->getName()<<"'s health: "<<p->getHealth()<<endl;
		
		if (health<=0){
			dead();
		}
	
}

//Return the item in the sword hand
GameItem* GameActor::getSwordHandItem() {
	return swordHand;
}

//Return the item in the shield hand
GameItem* GameActor::getShieldHandItem() {
	return shieldHand;
}

//Return the item in the sword hand
void GameActor::setSwordHandItem(GameItem* i) {
	swordHand=i;
	if (i==NULL) strength=0;
	else strength=i->getStatValue();
}

//Return the item in the shield hand
void GameActor::setShieldHandItem(GameItem* i) {
	shieldHand=i;
	if (i==NULL) defense=0;
	else defense=i->getStatValue();
}

//Equip an item in the sword hand.
void GameActor::equipInSwordHand(GameItem* i){
	if(getInventory()->hasItem(i)){
		if (i->getEquipable()){
			setSwordHandItem(i);
			setStrength(i->getStatValue());
			getInventory()->removeItem(i);
		}
	}
}

//Equip an item in the shield hand
void GameActor::equipInShieldHand(GameItem* i){
	if(getInventory()->hasItem(i)){
		if (i->getEquipable()){
			setShieldHandItem(i);
			defense=i->getStatValue();
			getInventory()->removeItem(i);
		}
	}
}

//Remove the item from the sword hand and add it to the inventory
void GameActor::unEquipSwordHand(){
	if (swordHand != NULL){
		getInventory()->addItem(swordHand);
		swordHand=NULL;
		strength=0;
	}
}

//Remove the item from the shield hand and add it to the inventory
void GameActor::unEquipShieldHand(){
	if (shieldHand != NULL){
		getInventory()->addItem(shieldHand);
		shieldHand=NULL;
		defense=0;
	}
}

//Actions to preform on death
void GameActor::dead(){
	cout << getName() << " dies."<<endl;
	if (inv.getCount() >0) {
		cout <<endl<< getName() << " Drops:"<<endl;
		dropAllItems();
	}
	if (getLocation()->hasActor(this)) getLocation()->removeActor(this);
}


//Get the hostility of the actor
bool GameActor::getHostile(){
	return hostile;
}

//Set the hostility of the actor
void GameActor::setHostile(bool l){
	hostile=l;
}

void GameActor::talk(){
	if (getSpeach() != "")	cout<<getSpeach()<<endl;
	else cout<<"They do not seem to be very talkative."<<endl;
}

//Print the actor info.
void GameActor::print(){
	GameObject::print();
	if (getHostile()) cout<<"  "<<getName()<<"'s Health: "<<getHealth()<<endl;
}

//Take all items in a container
void GameActor::takeAll(GameContainer* c){
	if (c!=NULL){
		if(!(c->getLock())){
			//cout<<"You open the "<<c->getName()<<" and take:"<<endl;
			linkedListIterator<GameItem*> itemsIterator = c->getItemsIterator();					
			for(int x=0;x<c->getCount();x++){
				if ((*itemsIterator)!= NULL) {
					getInventory()->addItem(*itemsIterator);
					cout<<"    "<<(*itemsIterator)->getName()<<endl;
					c->removeItem(*itemsIterator);
					++itemsIterator;
				}
			}
		}
	}
}