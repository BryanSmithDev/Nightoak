#ifndef H_GameActor
#define H_GameActor
/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Actor Class
*/

#include <iostream>
#include <string>
#include "unorderedLinkedList.h"
#include "GameContainer.h"
#include "GameObject.h"
#include "GameItem.h"


using namespace std;

class GameRoom;

class GameActor : public GameObject{
	public:

		//Constructor w/ parameters
		GameActor(int i, string b, string c, GameRoom* l = NULL, int h=1);

		//getHealth
		int getHealth();

		//setHealth
		void setHealth(int h);

		//getStrength
		int getStrength();

		//setStrength
		void setStrength(int s);

		//getDefense
		int getDefense();

		//setDefense
		void setDefense(int d);

		//getLocation
		GameRoom* getLocation();

		//setlocation
		void setLocation(GameRoom* l);

		//Returns what the actor says
		string getSpeach();

		//Sets the actors talk message
		void setSpeach(string s);

		//Sets the inventory of the actor
		void setInventory(GameContainer i);

		//Returns the inventory of the actor
		GameContainer* getInventory();

		//sets the max health of the actor
		void setMaxHealth(int m);

		//gets the max health of the actor
		int getMaxHealth();

		//Actor has specified item?
		bool hasItem(GameItem* i);

		//Actor drops an item on the ground.
		void dropItem(GameItem* i);

		//Actor drops all held items
		void dropAllItems();

		//Actor attacks another
		void attack(GameActor* p);

		//Return the item in the sword hand
		GameItem* getSwordHandItem();

		//Return the item in the shield hand
		GameItem* getShieldHandItem();

		//Set the sword item
		void setSwordHandItem(GameItem* i);

		//Set the shield item
		void setShieldHandItem(GameItem* i);

		//Equip an item in the sword hand.
		void equipInSwordHand(GameItem* i);

		//Equip an item in the shield hand
		void equipInShieldHand(GameItem* i);

		//Remove the item from the sword hand and add it to the inventory
		void unEquipSwordHand();

		//Remove the item from the shield hand and add it to the inventory
		void unEquipShieldHand();

		//Actions to preform on death
		void dead();

		//Get the hostility of the actor
		bool getHostile();

		//Set the hostility of the actor
		void setHostile(bool l);

		//Output their speach
		void talk();

		//Take all items in a container
		void GameActor::takeAll(GameContainer* c);

		//Print out the actor info
		void GameActor::print();

	protected:
		int health;
		int maxHealth;
		bool hostile;
		int defense;
		int strength;
		string speach;
		GameContainer inv;
		GameItem* swordHand;
		GameItem* shieldHand;
		GameRoom* location;
};

#endif
