#ifndef H_GameRoom
#define H_GameRoom
/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Room Class
*/


#include <iostream>
#include <string>
#include "unorderedLinkedList.h"
#include "GameObject.h"
#include "GameItem.h"
#include "GameContainer.h"



using namespace std;

class GameActor;

class GameRoom : public GameObject{
	private:
		//Room pointers for each direction
		GameRoom* northRoom;
		GameRoom* southRoom;
		GameRoom* eastRoom;
		GameRoom* westRoom;

		//GameItem pointers for each direction indicating the required item to go that direction
		GameItem* northRoomReqItem;
		GameItem* southRoomReqItem;
		GameItem* eastRoomReqItem;
		GameItem* westRoomReqItem;

		
		//List of items on the "ground" in the room
		GameContainer items;

		//List of actors in the room
		unorderedLinkedList<GameActor*> actors;
		linkedListIterator<GameActor*> actorIterator;




	public:

		//Constructor
		GameRoom(int id, string n, string desc, 
			GameRoom* nR=NULL, GameRoom* sR=NULL, GameRoom* eR=NULL, GameRoom* wR=NULL, 
			GameItem* nI=NULL, GameItem* sI=NULL, GameItem* eI=NULL, GameItem* wI=NULL);

		//Print out room name and description
		void print();

		//Check if spcified item is in the room.
		bool hasItem(GameItem* i);

		//Return the spcified item if in the room.
		GameItem* findItem(int id);

		//Return the spcified item if in the room.
		GameItem* findItem(string name);

		//Check if spcified item is in the room.
		bool hasActor(GameActor* i);

		//Find an actor by id
		GameActor* findActor(int id);

		//Find an actor by name
		GameActor* findActor(string name);

		//Set the north room pointer
		void setNorthRoom(GameRoom* r);

		//Return the north room pointer
		GameRoom* getNorthRoom();

		//Set the south room pointer
		void setSouthRoom(GameRoom* r);

		//Return the south room pointer
		GameRoom* getSouthRoom();

		//Set the east room pointer
		void setEastRoom(GameRoom* r);
		//Return the east room pointer
		GameRoom* getEastRoom();

		//Set the west room pointer
		void setWestRoom(GameRoom* r);

		//Return th west room pointer
		GameRoom* getWestRoom();

		//Set the item required to enter the north room
		void setNorthRoomRequiredItem(GameItem* i);

		//Return the item required to enter the north room
		GameItem* getNorthRoomRequiredItem();

		//Set the item required to enter the south room
		void setSouthRoomRequiredItem(GameItem* i);

		//Return the item required to enter the south room
		GameItem* getSouthRoomRequiredItem();

		//Set the item required to enter the east room
		void setEastRoomRequiredItem(GameItem* i);

		//Return the item required to enter the east room
		GameItem* getEastRoomRequiredItem();

		//Set the item required to enter the west room
		void setWestRoomRequiredItem(GameItem* i);

		//Return the item required to enter the west room
		GameItem* getWestRoomRequiredItem();

		//Move player to room
		int move(GameActor* p, GameRoom* l,GameItem* i);

		//Attempt to move player north
		int moveNorth(GameActor* p);

		//Attempt to move player south
		int moveSouth(GameActor* p);

		//Attempt to move player east
		int moveEast(GameActor* p);

		//Attempt to move player west
		int moveWest(GameActor* p);

		//Return the linked list of items in the room
		unorderedLinkedList<GameItem*> getItems();

		//Return the linked list of actors in the room
		unorderedLinkedList<GameActor*> getActors();

		//Add item to the room
		void addItem(GameItem* i);

		//Remove item from the room
		void removeItem(GameItem* i);
		
		//Add item to the room
		void addActor(GameActor* i);

		//Remove item from the room
		void removeActor(GameActor* i);

		//Print out all room items
		void printItems();
};

#endif
