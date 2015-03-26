/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Player Class
*/

class Player : public GameActor {

	public:
		//Constructor
		Player(int i=-1,string name="", string desc="", GameRoom* l=NULL, int h=0):GameActor(i,name,desc,l,h){

		}

		//Actor attacks another
		void attack(GameActor* p){
			if (p!= NULL){
				if (p->getHostile()) {
					int damage2 = (strength-(p->getDefense()))>=0?(strength-(p->getDefense())):0;
					p->setHealth(p->getHealth()-damage2);
					cout << getName() << " attacks " << p->getName() << " dealing " << damage2 << " damage!  -  "<<p->getName()<<"'s health: "<<p->getHealth()<<endl;
		
					if (health<=0){
						dead();
					} else {
						p->attack(this);
					}
				} else {
					cout << "I have no reason to attack them."<<endl;
				}
			} else {
				cout << "I can't attack that!"<<endl;
			}
		}

		//Move actor output
		void move(int i){
			switch(i){
				case -1:
					cout<<"It seems you may need something to gain access to this area."<<endl;
					break;
				case 0:
					cout<<"You cannot go that direction."<<endl;
					break;
				case 1:
					getLocation()->print();
					break;
				default:
					cout<<"I'm lost"<<endl;
					break;
			}
		}

		//Attempt to move player north
		void moveNorth(){
			move(getLocation()->moveNorth(this));
		}

		//Attempt to move player south
		void moveSouth(){
			move(getLocation()->moveSouth(this));
		}

		//Attempt to move player east
		void moveEast(){
			move(getLocation()->moveEast(this));
		}

		//Attempt to move player west
		void moveWest(){
			move(getLocation()->moveWest(this));
		}

		//Pick up game item
		void pickUpItem(GameItem* i){
			if (getLocation()->hasItem(i)){
				if(i->getPick()){
					getLocation()->removeItem(i);
					getInventory()->addItem(i);
					if (getInventory()->hasItem(i)) cout<<"You take the "<<i->getName()<<endl;
					else cout<<"There was a problem picking up the "<<i->getName()<<endl;
				} else {
					cout<<"You cannot take the "<<i->getName()<<"."<<endl;
				}
			} else {
				cout << "Nothing there to take to take."<<endl;
			}
		}

		//Pick up game item
		void pickUpItem(int id){
			pickUpItem(getLocation()->findItem(id));
		}

		//Pick up game item
		void pickUpItem(string name){
			pickUpItem(getLocation()->findItem(name));
		}

		//Drop item
		void dropItem(GameItem* i){
			if (getInventory()->getCount() >0){
				if (getInventory()->hasItem(i)){
					if (i->getDrop()){
						getLocation()->addItem(i);
						getInventory()->removeItem(i);
						if (getLocation()->hasItem(i)) cout<<"You drop the "<<i->getName()<<endl;
						else cout<<"There was a problem picking up the "<<i->getName()<<endl;
					} else {
						cout << "You cannot drop the "<<i->getName()<<endl;
					}
				} else {
					cout << "You do not have one to drop."<<endl;
				}
			} else {
				cout << "You have no items!"<<endl;
			}
		}

		//Drop item
		void dropItem(int id){
			dropItem(getInventory()->findItem(id));
		}

		//Drop item
		void dropItem(string name){
			dropItem(getInventory()->findItem(name));
		}

		//Equip an item in the sword hand.
		void equipInSwordHand(GameItem* i){
			if(getInventory()->hasItem(i)){
				if (i->getEquipable()){
					setSwordHandItem(i);
					getInventory()->removeItem(i);
					cout<< i->getName() << " equipped."<<endl;
				} else {
					cout<< i->getName() << " is not able to be equipped in that hand."<<endl;
				}
			}
		}

		//Equip an item in the shield hand
		void equipInShieldHand(GameItem* i){
			if(getInventory()->hasItem(i)){
				if (i->getEquipable()){
					setShieldHandItem(i);
					getInventory()->removeItem(i);
					cout<< i->getName() << " equipped."<<endl;
				} else {
					cout<< i->getName() << " is not able to be equipped in that hand."<<endl;
				}
			}
		}

		//Remove the item from the sword hand and add it to the inventory
		void unEquipSwordHand(){
			if (getSwordHandItem() != NULL){
				getInventory()->addItem(getSwordHandItem());
				cout<< getSwordHandItem()->getName() << " unequipped."<<endl;
				setSwordHandItem(NULL);
			} else {
				cout << "There is nothing equipped."<<endl;
			}
		}

		//Remove the item from the shield hand and add it to the inventory
		void unEquipShieldHand(){
			if (getShieldHandItem() != NULL){
				getInventory()->addItem(getShieldHandItem());
				cout<< getShieldHandItem()->getName() << " unequipped."<<endl;
				setShieldHandItem(NULL);
			} else {
				cout << "There is nothing equipped."<<endl;
			}
		}

		//Print out player info
		void print(){
			cout<<endl<<getName()<<endl;
			cout<<"-----------------"<<endl;
			cout<<"   Health: "<<getHealth()<<endl;
			cout<<"   Strength: "<<getStrength()<<endl;
			cout<<"   Defense: "<<getDefense()<<endl<<endl;
		}

		//Print out the items
		void printInv(){
			cout << "Inventory:"<<endl;
			cout << "-----------"<<endl;
			getInventory()->print();
		}

};