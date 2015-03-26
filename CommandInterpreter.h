#ifndef H_CommandInterpreter
#define H_CommandInterpreter

/*################################################
 Name: Bryan Smith
 Course: CSC 2180-02 Data Structures
 Date: 4/22/13
 Assignment: Programming Assignment #6
 Description: CommandInterpreter class takes in a string,
			 that is entered by the user and breaks it up,
			 seeing if there is a pre-programmed action for
			 what the user specified.
###############################################*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CommandInterpreter {
	private:
		string verb;		//The Verb part of the command i.e 'go'
		string noun;		//The noun part of the command i.e 'north'
		Player* player;
	public:
		//Defaultcontructor
		CommandInterpreter(Player* p){
			verb="";
			noun="";
			player=p;
		}

		//Prompt player for the command
		int enterCommand(){
			char s[50];
			cout<<endl<<"--> ";
			cin.getline(s,50);
			cout<<endl;
			return parseCommand(s);
		}

		//Perfrom actions based on the command given
		int parseCommand(string s){
			transform(s.begin(), s.end(), s.begin(), tolower);
			split(s,' ');
			if(verb== "go"){
				if (noun == "north" || noun=="up"){
					player->moveNorth();
					return 1;
				} else if (noun == "south" || noun=="down"){
					player->moveSouth();
					return 1;
				}else if (noun == "east" || noun=="right"){
					player->moveEast();
					return 1;
				}else if (noun == "west" || noun=="left"){
					player->moveWest();
					return 1;
				} else {
					cout << "You cannot go " << noun <<endl;
				}
			} else if (verb=="take") {
				player->pickUpItem(noun);
			} else if (verb=="drop") {
				player->dropItem(noun);
			} else if (verb=="inventory" || verb=="inv") {
				player->printInv();
			} else if (verb=="talk") {
					GameActor* temp;
					temp = player->getLocation()->findActor(noun);
					if (temp != NULL) temp->talk();
					else cout<<"No one by that name here to talk too."<<endl;
			} else if (verb=="look"){
				cout<<endl<<"Items:"<<endl;
				cout<<"------"<<endl;
				player->getLocation()->printItems();
			} else if (verb=="examine") {
				if(noun==""){
					player->getLocation()->print();
					cout<<endl<<"Items:"<<endl;
					cout<<"------"<<endl;
					player->getLocation()->printItems();
				} else if (noun == "player" || noun == player->getName()){
					player->print();
				} else if (noun!="") {
					GameObject* temp;
					temp = player->getLocation()->findActor(noun);
					if (temp != NULL) {
						temp->print();
					} else {
						temp = 	player->getInventory()->findItem(noun);
						if (temp != NULL) {
							temp->print();
						} else {
							temp = 	player->getLocation()->findItem(noun);
							if (temp != NULL) {
								temp->print();
							} else {
								cout << "Nothing by than name to examine."<<endl;
							}
						}
					}
				}
			} else if (verb=="use") {
				GameItem* temp;
				temp = 	player->getInventory()->findItem(noun);
				if (temp != NULL) {
					temp->use(player);
				} else {
					temp = 	player->getLocation()->findItem(noun);
					if (temp != NULL && temp->getPick() == false) {
						temp->use(player);
					} else {
						cout << "There is not one to use."<<endl;
					}
				}
			} else if(verb=="attack"){
				player->attack(player->getLocation()->findActor(noun));
			} else if (verb=="help") {
				cout<<endl;
				cout<<"Command List:"<<endl;
				cout<<"--------------"<<endl;
				cout<<"   attack <person>"<<endl;
				cout<<"   drop <item>"<<endl;
				cout<<"   examine <object>"<<endl;
				cout<<"   exit  - Exits Game"<<endl;
				cout<<"   go <direction>"<<endl;
				cout<<"   help"<<endl;
				cout<<"   look"<<endl;
				cout<<"   take <item>"<<endl;
				cout<<"   talk <person>"<<endl;
				cout<<"   use <item>"<<endl;
				cout<<endl;
			} else if(verb=="exit") {
				if(noun=="") return -1;
			} else {
				cout << "What?"<<endl;
			}
			return 0;
		}

		//Splits a string based on a delimiter and places
		// the pieces in the verb and noun variables
		void split(string s, char del){
			int delPos = s.find(del);
			verb=s.substr(0,delPos);
			noun=s.substr(delPos+1);
			if(verb==noun) noun="";
			//print();
		}

		//Prints out the verb and noun to the screen
		void print(){
			cout<<"|"<<verb<<"|"<<endl;
			cout<<"|"<<noun<<"|"<<endl;
		}

};
#endif
