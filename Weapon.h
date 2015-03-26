#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"

using namespace std;

class Weapon: public GameItem{
	public:
		//Constructor
		Weapon(int a, string b, string c, bool d, bool e, bool p, int f):GameItem(a, b, c,d,e,p,f){
			setDrop(d);
			setEquipable(e);
			setStatValue(f);
			setPick(p);
		}

		//Equip weapon
		void use(GameActor* t1=NULL,GameActor* t2=NULL){
			if (target != NULL) {
				if (target->getSwordHandItem() != NULL){
					cout << "Unequipped "<<target->getSwordHandItem()->getName()<<".  Damage is now: ";
					target->unEquipSwordHand();
					cout << target->getStrength()<<endl;
				}
				cout << "Equipped "<<this->getName()<<".  Damage is now: ";
				target->equipInSwordHand(this);
				cout << target->getStrength()<<endl;
			}
		}

		//Set who is using item
		void setTarget(GameActor* p){
			target =p;
		}
		
		//get who is using item
		GameActor* getTarget(){
			return target;
		}

	private:
		GameActor* target; //Actor who is using item
};