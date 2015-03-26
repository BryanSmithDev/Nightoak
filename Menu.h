#ifndef H_Menu
#define H_Menu
/*################################################
 Name: Bryan Smith
 Course: CSC 2180-02 Data Structures
 Date: 4/22/13
 Assignment: Programming Assignment #6
 Description: Menu class provides a simple way to output
			  menus.
###############################################*/

#include <iostream>
#include <string>

using namespace std;

class Menu {
	private:
		string menuText;		//The 'title' of the menu. Diplayed above the options.
		string* menuOptions;	//The menu's options.
		int numbOfOptions;		//The number of menu options.

	public:
		//Construtor
		Menu(string mT,int numb, string mO[]) {
			menuText = mT;
			numbOfOptions=numb;
			menuOptions=mO;
		}

		//Will print the menu to the screen
		int show() {
			int option=-1;
			cout<<getMenuText()<<endl<<endl;
			for (int i=0;i<getNumberOfOptions();i++){
				cout<<"     "<<i+1<<")  "<<getMenuOption(i)<<endl;
			}
			cout<<endl<<"Please select an option: ";
			cin>>option;
			 return option;
		}

		//Setter for the number of menu options
		void setNumberOfOptions(int x) {
			numbOfOptions = x;
		}

		//Getter for the number of menu options
		int getNumberOfOptions() {
			return numbOfOptions;
		}
		
		//Getter of the menu text
		string getMenuText() {
			return menuText;
		}

		//Setter of the menu text
		void setMenuText(string t){
			menuText = t;
		}

		//Setter of the menu options
		void setMenuOptions(string t[]){
			setNumberOfOptions(10);
			for(int i=0;i<getNumberOfOptions();i++){
				setMenuOption(i,t[i]);
			}
		}

		//Setter of individual menu options
		void setMenuOption(int i, string d){
			menuOptions[i]=d;
		}

		//Getter of individual menu options
		string getMenuOption(int i) {
			return menuOptions[i];
		}
};
#endif
