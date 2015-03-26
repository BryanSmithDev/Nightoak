#ifndef H_GameContainer
#define H_GameContainer
/*
Name: Scott Arnette
Date: 4/24/13
Section: 2
Assignment 6: Interactive Fiction Game: Game Container Class
*/

#include<iostream>
#include<string>
#include <algorithm>
#include"GameItem.h"
#include"unorderedLinkedList.h"

using namespace std;

class GameActor;

class GameContainer: public GameItem{
	
public:
	//Constructors
	GameContainer();
	GameContainer(int a, string b, string c, bool d=true, bool e=false,bool p=true, int f=0);

	//Return the number of items in the container
	int getCount();
	
	//Check if container has item
	bool hasItem(GameItem* i);

	//Find an item by id
	GameItem* findItem(int id);


	//Find an item by name
	GameItem* findItem(string name);

	//Return the unoderedLinked list of items
	unorderedLinkedList<GameItem*> getItems();

	//Return the item linked list iterator
	linkedListIterator<GameItem*> getItemsIterator();
	//Add an item to the list
	void addItem(GameItem* i);

	//Remove an item from the list.
	void removeItem(GameItem* i);

	//Print out the name of all the items in the container
	void print();

	//Is container locked?
	bool getLock();

	//Set the lock on the container
	void setLock(bool l);

	//Use the container
	void use(GameActor* t1=NULL, GameActor* t2=NULL);
	
	
protected:
	unorderedLinkedList<GameItem*> items;
	linkedListIterator<GameItem*> itemsIterator;
	bool locked;



};
#endif