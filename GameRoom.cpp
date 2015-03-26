/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Room Class
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "GameRoom.h"
#include "GameActor.h"

using namespace std;

//Constructor
GameRoom::GameRoom(int id, string n, string desc, 
	GameRoom* nR, GameRoom* sR, GameRoom* eR, GameRoom* wR, 
	GameItem* nI, GameItem* sI, GameItem* eI, GameItem* wI):GameObject(id,n,desc){
		northRoom = nR;
		southRoom = sR;
		eastRoom = eR;
		westRoom = wR;
		northRoomReqItem = nI;
		southRoomReqItem = sI;
		eastRoomReqItem = eI;
		westRoomReqItem = wI;
}

//Print out room name and description
void GameRoom::print() {
	cout<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"          "<<getName()<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<getDescription()<<endl<<endl;
}

//Does the room contain this item?
bool GameRoom::hasItem(GameItem* i) {
	return items.hasItem(i);
}

//Return the spcified item if in the room.
GameItem* GameRoom::findItem(int id){
	return items.findItem(id);
}

//Return the spcified item if in the room.
GameItem* GameRoom::findItem(string name){
	return items.findItem(name);
}


//Check if spcified item is in the room.
bool GameRoom::hasActor(GameActor* i){
	actorIterator = actors.begin();
	for(int x=0;x<actors.length();x++){
		if ((*actorIterator) == i) return true;
		++actorIterator;
	}
	return false;
}

//Find an actor by id
GameActor* GameRoom::findActor(int id){
	actorIterator = actors.begin();					
	for(int x=0;x<actors.length();x++){				
		if ((**actorIterator).getID() == id) return (*actorIterator);
		++actorIterator;
	}
	return NULL;		
}


//Find an actor by name
GameActor* GameRoom::findActor(string name){
	string n1;
	actorIterator = actors.begin();	
	for(int x=0;x<actors.length();x++){
		n1 = (**actorIterator).getName();
		transform(n1.begin(), n1.end(), n1.begin(), tolower);
		if (n1 == name) return (*actorIterator);
		++actorIterator;
	}
	return NULL;	
}

//Set the north room pointer
void GameRoom::setNorthRoom(GameRoom* r){
	northRoom=r;
}

//Return the north room pointer
GameRoom* GameRoom::getNorthRoom() {
	return northRoom;
}

//Set the south room pointer
void GameRoom::setSouthRoom(GameRoom* r){
	southRoom=r;
}

//Return the south room pointer
GameRoom* GameRoom::getSouthRoom() {
	return southRoom;
}

//Set the east room pointer
void GameRoom::setEastRoom(GameRoom* r){
	eastRoom=r;
}

//Return the east room pointer
GameRoom* GameRoom::getEastRoom() {
	return eastRoom;
}

//Set the west room pointer
void GameRoom::setWestRoom(GameRoom* r){
	westRoom=r;
}

//Return th west room pointer
GameRoom* GameRoom::getWestRoom() {
	return westRoom;
}

//Set the item required to enter the north room
void GameRoom::setNorthRoomRequiredItem(GameItem* i) {
	northRoomReqItem = i;
}

//Return the item required to enter the north room
GameItem* GameRoom::getNorthRoomRequiredItem() {
	return northRoomReqItem;
}

		//Set the item required to enter the south room
void GameRoom::setSouthRoomRequiredItem(GameItem* i) {
	southRoomReqItem = i;
}

//Return the item required to enter the south room
GameItem* GameRoom::getSouthRoomRequiredItem() {
	return southRoomReqItem;
}

		//Set the item required to enter the east room
void GameRoom::setEastRoomRequiredItem(GameItem* i) {
	eastRoomReqItem = i;
}

//Return the item required to enter the east room
GameItem* GameRoom::getEastRoomRequiredItem() {
	return eastRoomReqItem;
}

//Set the item required to enter the west room
void GameRoom::setWestRoomRequiredItem(GameItem* i) {
	westRoomReqItem = i;
}

//Return the item required to enter the west room
GameItem* GameRoom::getWestRoomRequiredItem() {
	return westRoomReqItem;
}

//Move player to room
int  GameRoom::move(GameActor* p, GameRoom* l,GameItem* i){
	if (l==NULL){
		return 0;
	}
	if (i != NULL){
		if (p->hasItem(i)){
			p->setLocation(l);
			return 1;
		} else {
			return -1;
		}
	} else {
		p->setLocation(l);
		return 1;
	}
}

//Attempt to move player north
int GameRoom::moveNorth(GameActor* p){
	return move(p,getNorthRoom(), getNorthRoomRequiredItem());
}

//Attempt to move player south
int GameRoom::moveSouth(GameActor* p){
	return move(p,getSouthRoom(), getSouthRoomRequiredItem());
}

//Attempt to move player east
int GameRoom::moveEast(GameActor* p){
	return move(p,getEastRoom(), getEastRoomRequiredItem());
}

//Attempt to move player west
int GameRoom::moveWest(GameActor* p){
	return move(p,getWestRoom(), getWestRoomRequiredItem());
}

//Return the linked list of items in the room
unorderedLinkedList<GameItem*> GameRoom::getItems(){
	return items.getItems();
}

//Return the linked list of actors in the room
unorderedLinkedList<GameActor*> GameRoom::getActors(){
	return actors;
}

//Add item to the room
void GameRoom::addItem(GameItem* i){
	items.addItem(i);
}

//Remove item from the room
void GameRoom::removeItem(GameItem* i){
	items.removeItem(i);
}
		
//Add item to the room
void GameRoom::addActor(GameActor* i){
	actors.insertLast(i);
}
//Remove item from the room
void GameRoom::removeActor(GameActor* i){
	actors.deleteNode(i);
}

//Print out all items in the room
void GameRoom::printItems(){
	items.print();
}