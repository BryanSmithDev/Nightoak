#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"

using namespace std;

class Armor: public GameItem{
	public:
		//Constructor
		Armor(int a, string b, string c, bool d, bool e, bool p, int f):GameItem(a, b, c,d,e,p,f){
			setDrop(d);
			setEquipable(e);
			setStatValue(f);
			setPick(p);
		}

		//Equip the armor
		void use(GameActor* t1=NULL,GameActor* t2=NULL){
			if (target != NULL) {
				if (target->getShieldHandItem() != NULL){
					cout << "Unequipped "<<target->getShieldHandItem()->getName()<<".  Defense is now: ";
					target->unEquipShieldHand();
					cout << target->getDefense()<<endl;
				}
				cout << "Equipped "<<this->getName()<<".  Defense is now: ";
				target->equipInShieldHand(this);
				target->setDefense(this->getStatValue());
				cout << target->getDefense()<<endl;
			}
		}

		//Set the actor using the item
		void setTarget(GameActor* p){
			target =p;
		}
		
		//Get the actor using the item
		GameActor* getTarget(){
			return target;
		}

	private:
		GameActor* target;	//Actor using the item
};