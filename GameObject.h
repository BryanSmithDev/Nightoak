#ifndef H_GameObject
#define H_GameObject
/*
Name: Cory Elswick
Section: 2
Date: 4/23/13
Assignment 6: Object Class
*/

#include <iostream>
#include <string>


using namespace std;

  class GameObject{
   public:
   //Default Constructor
      GameObject(){
         id = 0;
         name = " ";
         description = " ";
      }
   
   //Constructor w/ parameters
      GameObject(int a, string b, string c){
         id = a;
         name = b;
         description = c;
      }
   
   //getID
      int getID(){
         return id;
      }
   //setID
      void setID(int a){
         id = a;
      }
   //getName
      string getName(){
         return name;
      }
   //setName
      void setName(string b){
         name = b;
      }
   //getDescription
      string getDescription(){
         return description;
      }
   //setDescription
      void setDescription(string c){
         description = c;
      }

	//Print out info
	  void print() {
		  cout << getDescription() <<endl;
	  }
   
   protected:
      int id;
      string name;
      string description;
   
   };

#endif