#include<iostream>
#include<string>
#include"GameItem.h"
#include "GameActor.h"
#include "GameRoom.h"

using namespace std;

class ContainerKey: public GameItem{
	public:
		//Constructor
		ContainerKey(int a, string b, string c, bool d, bool e, bool p, int f):GameItem(a, b, c,d,e,p,f){
			setDrop(d);
			setEquipable(e);
			setStatValue(f);
			setPick(p);
		}

		//use the key
		void use(GameActor* t1 = NULL,GameActor* t2 = NULL){
			setTarget(t1);
			if (target != NULL && target2 != NULL) {
				if (target->getInventory()->hasItem(this)){
					if (target2->getLock()) {
						if (target->getInventory()->hasItem(target2) || target->getLocation()->hasItem(target2)){
							target2->setLock(false);
							target->getInventory()->removeItem(this);
							cout << target2->getName() << " is now unlocked."<<endl;
							cout << target->getName() << " opens the " << target2->getName() << " and takes: "<<endl;
							target->takeAll(target2);
							target->getLocation()->removeItem(target2);
						} else {
							cout << "Nothing to unlock."<<endl;
						}
					} else {
						cout << target2->getName() << " is already unlocked."<<endl;
					}
				}
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

		//Set what container the key opens
		void setContainer(GameContainer* p){
			target2 =p;
		}
		
		//Get what container the key opens
		GameContainer* getContainer(){
			return target2;
		}

	private:
		GameActor* target;			//Actor that uses the key
		GameContainer* target2;		//Container the key opens
};