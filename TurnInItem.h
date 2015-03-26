#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"
#include "GameRoom.h"

using namespace std;

class TurnInItem: public GameItem{
	public:
		//Constructor
		TurnInItem(int a, string b, string c, bool d, bool e, bool p, int f):GameItem(a, b, c,d,e,p,f){
			setDrop(d);
			setEquipable(e);
			setStatValue(f);
			setPick(p);
		}

		//Turn in item
		void use(GameActor* t1=NULL,GameActor* t2=NULL){
			if (t1 != NULL && target != NULL) {
				if (t1->getLocation()->hasActor(target)){
					cout<<target->getName()<<": "<<getMessage()<<endl;
					if (getDeleteItemOnUse()){
						if(t1->getInventory()->hasItem(this)) t1->getInventory()->removeItem(this);
					}
					if (getDeleteActorTargetOnUse()) {
						cout<<endl<<"You pick up: "<<endl;
						t1->takeAll(target->getInventory());
						t1->getLocation()->removeActor(target);
					}

				} else {
					cout<<"Don't see how I can use that here."<<endl;
				}
			}
		}

		//Set actor to turn into
		void setTarget(GameActor* p){
			target =p;
		}
		
		//Get actor to turn into
		GameActor* getTarget(){
			return target;
		}

		//Set meesage to say on turn in
		void setMessage(string m){
			message=m;
		}

		//Get message to say on turn in
		string getMessage(){
			return message;
		}

		//Set delete on item use
		void setDeleteItemOnUse(bool m){
			deleteItemOnUse=m;
		}

		//Get delete on item use
		bool getDeleteItemOnUse(){
			return deleteItemOnUse;
		}

		//Set delete actor on turn in
		void setDeleteActorTargetOnUse(bool m){
			deleteActorTargetOnUse=m;
		}

		//Get delete actor on turn in
		bool getDeleteActorTargetOnUse(){
			return deleteActorTargetOnUse;
		}

		//unlock room doors on turn in?
		void setTrigger(GameRoom* i=NULL,GameItem* n=NULL,GameItem* s=NULL,GameItem* e=NULL,GameItem* w=NULL){
			trigger=i;
			nI=n;
			sI=s;
			eI=e;
			wI=w;
		}

	private:
		GameActor* target;	//Actor to turn item into
		string message;
		bool deleteItemOnUse;
		bool deleteActorTargetOnUse;
		GameRoom* trigger;
		GameItem* nI,*sI,*eI,*wI;


};