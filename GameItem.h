#ifndef H_GameItem
#define H_GameItem
/*
Name: Scott Arnette
Date: 4/24/13
Section: 2
Assignment 6: Interactive Fiction Game: Game Item Class
*/

#include<iostream>
#include<string>
#include"GameObject.h"



using namespace std;

class GameActor;

class GameItem: public GameObject{
public:
	//Constructors
	GameItem();
	GameItem(int a, string b, string c, bool d, bool e, bool p, int f);

	//Sets if the item is droppable
	void setDrop(bool d);

	//Gets if the item is droppable
	bool getDrop();

	//Sets if the item can be picked up
	void setPick(bool p);

	//Gets if the item can be picked up
	bool getPick();

	//Sets if the item can be equiped
	void setEquipable(bool e);

	//Gets if the item can be equipped
	bool getEquipable();

	//Sets a value for the item
	void setStatValue(int f);

	//Gets the value of the item
	int getStatValue();

	//Use the item
	virtual void use(GameActor* t1 = NULL,GameActor* t2 = NULL);


protected:
	bool drop, equipable, pickUp;
	int stat,slot;
};
#endif