/*
Name: Scott Arnette
Date: 4/24/13
Section: 2
Assignment 6: Interactive Fiction Game: Game Item Class
*/

#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"

//Constructors
GameItem::GameItem(){
}
GameItem::GameItem(int a, string b, string c, bool d, bool e, bool p, int f):GameObject(a, b, c){
	setDrop(d);
	setEquipable(e);
	setStatValue(f);
	setPick(p);
}

//Sets if the item is droppable
void GameItem::setDrop(bool d){
	drop = d;
}

//Gets if the item is droppable
bool GameItem::getDrop(){
	return drop;
}

//Sets if the item can be picked up
void GameItem::setPick(bool p){
	pickUp = p;
}

//Gets if the item can be picked up
bool GameItem::getPick(){
	return pickUp;
}

//Sets if the item can be equiped
void GameItem::setEquipable(bool e){
	equipable = e;
}

//Gets if the item can be equipped
bool GameItem::getEquipable(){
	return equipable;
}

//Sets a value for the item
void GameItem::setStatValue(int f){
	stat = f;
}

//Gets the value of the item
int GameItem::getStatValue(){
	return stat;
}

//Use the item
void GameItem::use(GameActor* t1,GameActor* t2) {
	cout<<"Not sure how to use this. I'll examine it."<<endl;
	cout<<getDescription()<<endl;
}
