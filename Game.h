/*################################################
 Name: Bryan Smith
 Course: CSC 2180-02 Data Structures
 Date: 4/22/13
 Assignment: Programming Assignment #6
 Description: The Game class brings together all the
			  instances of the GameRooms, Menus, Items,
			  and actors, to create the whole game.
###############################################*/

#include <iostream>
#include <string>
#include "unorderedLinkedList.h"
#include "Menu.h"
#include "TurnInItem.h"
#include "ContainerKey.h"
#include "Potion.h"
#include "Weapon.h"
#include "Armor.h"
#include "GameRoom.h"
#include "Player.h"
#include "GameContainer.h"
#include "CommandInterpreter.h"


using namespace std;

class Game {

	public:
		//Constructor
		Game(string t,Player* p,string win="You win!",string lose="You lose! Game Over!"){
			title=t;
			player =p;
			cmd = new CommandInterpreter(p);
			setWinMessage(win);
			setGameOverMessage(lose);
		}

		//Runs the game loop
		void run() {
			string os[]={"Play","Quit"};
			Menu menu(title,2,os);
			int option = menu.show();
			switch(option) {
				case 1:
					for(int i=0;i<50;i++){
						cout<<endl;
					}
					loop();
					break;
				case 2:
					break;
				default:
					cout<<endl<<"Please enter a valid option."<<endl<<endl;
					option = menu.show();
					break;
			}
			
		}

		//Sets the item that the player has to get to win
		void setEndGameItem(GameItem* i){
			endGame=i;
		}

		//Gets the item that the player has to get to win
		GameItem* getEndGameItem(){
			return endGame;
		}

		//Sets the message when the game ends due to death
		void setGameOverMessage(string g){
			gameOverM=g;
		}

		//Gets the message shown when the game ends due to death
		string getGameOvernMessage(){
			return gameOverM;
		}

		//Sets the message shown when the player wins the game
		void setWinMessage(string g){
			winM=g;
		}

		//Gets the message shown when the player wins the game
		string getWinMessage(){
			return winM;
		}



	private:
		string title,gameOverM,winM;	//Game Title, Game Over Message, and Win Message
		CommandInterpreter* cmd;		//Game's command interpretor
		Player* player;					//The player
		GameItem* endGame;				//Item player needs to get to beat the game

	
		//The Games loop
		int loop() {
			cin.clear();
			cin.sync();
				player->move(1);
				int ret=0;
				string command="";
				while (ret!=-1){
					if (player->getInventory()->hasItem(endGame)) {
						ret=-1;
						win();
						break;
					}

					if (player->getHealth() <=0) {
						ret=-1;
						gameOver();
						break;
					}
					ret=cmd->enterCommand();
				}
				return ret;
				system("PAUSE");

		}

		//Game over you lose
		void gameOver() {
			cout<<endl;
			cout<<endl;
			cout<<gameOverM<<endl;
			cout<<endl;
			cout<<endl;
			system("PAUSE");
		}

		//Game over you win
		void win(){
			cout<<endl;
			cout<<endl;
			cout<<winM<<endl;
			cout<<endl;
			cout<<endl;
			system("PAUSE");
		}

};
