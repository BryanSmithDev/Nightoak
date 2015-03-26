/*
Name: Scott Arnette
Date: 4/24/13
Section: 2
Assignment 6: Interactive Fiction Game: Game Container Class
*/

#include"GameContainer.h"
#include "GameActor.h"

using namespace std;

//Constructors
GameContainer::GameContainer(){}
GameContainer::GameContainer(int a, string b, string c, bool d, bool e,bool p, int f):GameItem(a, b, c, d, e, p,f){
	items.initializeList();
	setLock(false);
}

//Return the number of items in the container
int GameContainer::getCount(){
	return items.length();
}
	
//Check if container has item
bool GameContainer::hasItem(GameItem* i){
	itemsIterator = items.begin();					//Link the item list to the iterator and start at the begining
	for(int x=0;x<items.length();x++){				//Go through all the items
		if ((*itemsIterator) == i) return true;		//And if they are equal (i.e the ids are the same) then the items is in the room
		++itemsIterator;								//Iterate to the next item
	}
	return false;			
}

//Find an item by id
GameItem* GameContainer::findItem(int id){
	itemsIterator = items.begin();					
	for(int x=0;x<items.length();x++){				
		if ((**itemsIterator).getID() == id) return (*itemsIterator);
		++itemsIterator;
	}
	return NULL;		
}


//Find an item by name
GameItem* GameContainer::findItem(string name){
	string n1;
	itemsIterator = items.begin();					
	for(int x=0;x<items.length();x++){
		n1 = (**itemsIterator).getName();
		transform(n1.begin(), n1.end(), n1.begin(), tolower);
		if (n1 == name) return (*itemsIterator);
		++itemsIterator;
	}
	return NULL;		
}

//Return the unoderedLinked list of items
unorderedLinkedList<GameItem*> GameContainer::getItems(){
	return items;
}

//Return the item linked list iterator
linkedListIterator<GameItem*> GameContainer::getItemsIterator(){
	return items.begin();
}

//Add an item to the list
void GameContainer::addItem(GameItem* i){
	items.insertLast(i);
}

//Remove an item from the list.
void GameContainer::removeItem(GameItem* i){
	items.deleteNode(i);
}

//Print out the name of all the items in the container
void GameContainer::print(){
	itemsIterator = items.begin();					
	for(int x=0;x<items.length();x++){				
		cout<<"   "<<(**itemsIterator).getName()<<endl;
		++itemsIterator;
	}
}

//Is container locked?
bool GameContainer::getLock() {
	return locked;
}

//Set the lock on the container
void GameContainer::setLock(bool l){
	locked = l;
}

//use container
void GameContainer::use(GameActor* t1, GameActor* t2){
	if (getLock()){
		cout<< getName() << " is locked!"<<endl;
	} else {
		cout<<"Items added to inventory from the "<<getName()<<": "<<endl;
		t1->takeAll(this);
		t1->getInventory()->removeItem(this);
	}
}
	