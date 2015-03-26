#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"

using namespace std;

class Potion: public GameItem{
	public:
		//Constructor
		Potion(int a, string b, string c, bool d, bool e, bool p, int f):GameItem(a, b, c,d,e,p,f){
			setDrop(d);
			setEquipable(e);
			setStatValue(f);
			setPick(p);
			setDeleteOnUse(true);
		}

		//Use potion
		void use(GameActor* t1=NULL,GameActor* t2=NULL){
			if (target != NULL) {
				target->setHealth(target->getHealth()+getStatValue());
				cout << "Healed "<<target->getName()<<" for "<<getStatValue()<<endl;
				if (getDeleteOnUse()) {
					if (target->getInventory()->hasItem(this)){
						target->getInventory()->removeItem(this);
					}
				}
			}
		}

		//Set actor using item
		void setTarget(GameActor* p){
			target =p;
		}
		
		//Get actor using item
		GameActor* getTarget(){
			return target;
		}

		//Set if the item is delete on use
		void setDeleteOnUse(bool p){
			deleteOnUse =p;
		}
		
		//Get if the item is deleted on use
		bool getDeleteOnUse(){
			return deleteOnUse;
		}

	private:
		GameActor* target;	//Actor using item
		bool deleteOnUse;	//Delete item on use?
};