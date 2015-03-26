/*################################################
 Name: Bryan Smith
 Course: CSC 2180-02 Data Structures
 Date: 4/22/13
 Assignment: Programming Assignment #6
 Description: PA6_main contains a main function to
			  drive the Game.
###############################################*/

#include <iostream>
#include <string>

#include "Game.h"


using namespace std;

Game loadGame();

int main() {
	Game NightOak = loadGame();
	NightOak.run();

	return 0;
}


//Load all the NightOak specific Items
Game loadGame() {
	  //GAME ITEMS
     Weapon* sword = new Weapon(1,"Sword","A masterfully crafted long sword sits atop the mantle. It isn't your usual style, but it could be useful.",true,true,true,20);
     GameItem* portrait = new GameItem(2,"Portrait","The portrait is quite lovely.",false,false,false,0);
     TurnInItem* antidote = new TurnInItem(3,"Antidote","It's the antidote!",true,false,true,0);
     Potion* potion = new Potion(4,"Potion","This potion fully restores HP",true,false,true,100);
     GameItem* map = new GameItem(5,"Map","South of Courtyard is a fountain. Further South of that is a road that leads\ninto town. To the East is Nightoak Forest. Your cabin is in the southern part\nof the Nightoak Forest.",true,false,true,0);
     TurnInItem* ham = new TurnInItem(6,"Ham","This plate looks completely untouched.",true,false,true,0);
		 ham->setMessage("\"Oh, I'm so hungry! Maybe you're not so bad after all, Bogey. I'm still \nmad about what happened between you and my wife, Hilde!\" \nThe guard drops a key as he runs to the dining room to eat the ham.");
	 Armor* shield = new Armor(7,"Shield","Well, it's a rusty old shield..Nothing worth bragging about. \n Still, it should help keep you safe.",true,true,true,10);
     Potion* fountain = new Potion(8,"Fountain","An ornate, marble fountain with beautiful etchings of wolves around the rim.",false,false,false,100);
     GameItem* bed = new GameItem(9,"Bed","You don't have time to sleep right now.",false,false,false,0);
     ContainerKey* key = new ContainerKey(10,"Key","What could this key open?",true,false,true,0);
     GameContainer* pack = new GameContainer(11,"Pack","Contains a potion.",false,false,true,0);
     GameContainer* chest = new GameContainer(12,"Chest","The chest is locked up tight with a large padlock. There's nothing in your usual \nlockpicking kit that could grant you access past such an intricate lock.",false,false,false,0);
	 GameItem* crown = new GameItem(13,"Crown","The King's Golden Crown",false,false,false,0);
	 GameItem* gbKey = new GameItem(14,"Guest Bedroom Key","Key to the Guest Bedroom",false,false,true,0);

  //GAME ROOMS
  
  //Queens Private Chambers
     GameRoom* QueensChambers = new GameRoom(1,"Queen's Private Chambers",
        "They call you 'Bogey' an ex-thief from the dusky woods of the South Nightoak. \nYou now work as a tracker for the King and his council at Castle Nightoak,\nusually apprehending lesser criminals. You work alone and rely on wit. If all\nelse fails, your blade always gets the job done."
        "\n\nThe Queen had recently sent for you with urgency. You have just arrived at \nnher chambers. \n\nShe is looking at a portrait of her mother on the wall.");
     Player* player = new Player(0,"Bogey","Player",QueensChambers,60);
	 player->setStrength(10);
	 player->setHostile(true);
     GameActor* queen = new GameActor(1,"Queen","The Queen. You have many 'fantasies' about her...",QueensChambers);
	 queen->setSpeach("The Queen sits on a chair, crying. She explains to you that your services are \nneeded, for the King has been poisoned and will die very soon without an \nantidote. She tells you that you must find and apprehend the culprit and also \nhopefully find the antidote, as well. She offers you to use her father's sword \non the mantle below the portrait of her mother. She suggests you check on the \nKing, who is in his chambers.");
     QueensChambers->addActor(queen);
     QueensChambers->addItem(sword);
     QueensChambers->addItem(portrait);
     
  //Castle Foyer
     GameRoom* CastleFoyer = new GameRoom(2,"Castle Foyer","There is a royal red carpet with gold trim that lies between big columns that \nlead up to the Throne Room. \nTwo guards stand watch at the castle exit.");
     GameActor* guards = new GameActor(5,"Guards","Some guards standing watch of the Castle exit.",CastleFoyer);
	 guards->setSpeach("Guards: \"Hey, Bogey. Pretty crazy stuff, huh? Ivarr must have been pretty upset, he just went riding East through the courtyard on his horse. Maybe he went \nlooking for the fiend!\"");
     CastleFoyer->addActor(guards);
  
  //Master Chambers
     GameRoom* MasterChambers = new GameRoom(3,"Master Chambers","The King lies on his bed, obviously ill. The Prince sits at his bedside.");
     GameActor* king = new GameActor(2,"King","The King of Nightoak.",MasterChambers);
	 king->getInventory()->addItem(crown);
     GameActor* prince = new GameActor(3,"Prince","The Prince of Nightoak.",MasterChambers);
     MasterChambers->addActor(king);
	 antidote->setTarget(king);
	 antidote->setMessage("\"Thank you..., Bogey.\" You pour the antidote into the King's mouth. He \nloses his strength and falls back into a deep sleep."
		"\n\nA few hours pass. You, the Queen, and the Prince sit at the King's bedside. The Queen tells stories to the Prince about his father's time on the throne. "
		"The \nKing had to make many hard decisions under his rule and it led to a poor \npublic opinion of him. So much so, that even his brother saw himself fit to be \na better king."
		"\n\nAnother couple of hours pass. The King's head slowly begins to turn, and you \nhear the rustling of his pillow."
		"\"I.. I feel much better. I'm sorry to have \nhad you all so worried..\" \n\nThe Queen speaks:"
		"\"Thank goodness, you're awake! Bogey, we can't begin to express our gratitude for your heroics. Thank you for bringing my husband back to his \nfamily. Take this crown as a sign of our gratitude, it is very valuable.\"" );
	 antidote->setDeleteActorTargetOnUse(true);
	 antidote->setDeleteItemOnUse(true);
	 prince->setSpeach("Prince: \"Please, Bogey. Find who did this. You should check my pack on the \ntable; it has a potion in it, if you need.\"");
     MasterChambers->addActor(prince);
	 pack->addItem(potion);
     MasterChambers->addItem(pack);

  
  //Throne Room
     GameRoom* ThroneRoom = new GameRoom(4,"Throne Room","Two luxurious thrones sit in the back, one larger than the other. \nThis is usually one of the most active areas of the castle, but it's \neerily quiet today.");
       
  //Entertainment Area
     GameRoom* EntertainmentArea = new GameRoom(5,"Entertainment Area","This is where guests would be humored. There is a large table in the center of \nthe room and fanciful decorations hung upon the wall. \nA map sits on the edge of the table. A guard who is none too fond of you \nsuspiciously guards the door to the Guest Bedroom. \nHe is quite fat.");
     GameActor* guard = new GameActor(4,"Guard","Fat guard. You had a fling with his wife.",EntertainmentArea);
     EntertainmentArea->addItem(map);
	 guard->getInventory()->addItem(gbKey);
	 ham->setTarget(guard);
	 ham->setDeleteActorTargetOnUse(true);
	 ham->setDeleteItemOnUse(true);
	 guard->setSpeach("Guard: \"What do you want?! Ivarr was visiting when this tragedy struck and he \nwould not like to be bothered. Now get the Hell out of here before I cut you \ndown, you worthless rapscallion!\"");
     EntertainmentArea->addActor(guard);
  
  //Guest Bedroom
     GameRoom* GuestBedroom = new GameRoom(6,"Guest Bedroom","The King's brother Ivarr has been staying here for the past couple of nights. \nThere is a large chest in the corner and it appears locked. Ivarr is nowhere to be found, though.");
     chest->addItem(antidote);
	 chest->setLock(true);
	 GuestBedroom->addItem(chest);
  
  //Dining Hall
     GameRoom* DiningHall = new GameRoom(7,"Dining Hall","A huge, long wooden table stretches from each end of the room. The table is all disheveled; the King and his \ncompany must have been dining when his sickness became apparent. \nThere are many full plates still on the table; looks like they were having ham.");
     DiningHall->addItem(ham);
	
  //Kitchen
     GameRoom* Kitchen = new GameRoom(8,"Kitchen","The servants are working feverishly to clean up after what \nwas supposed to be a grand feast. Hilde is one of the servants you \nare 'familiar' with.");
     GameActor* hilde = new GameActor(6,"Hilde","Guards wife that you had a one-night-stand with.",Kitchen);
	 hilde->setSpeach("Hilde: \"I LOVED YOU!  WHY DID YOU LEAVE?!\" She smacks you.... This is awkward. \nYou better just go.");
     Kitchen->addActor(hilde);
  
  //Courtyard
     GameRoom* Courtyard = new GameRoom(9,"Courtyard","In all of Nightoak Forest, this may be the one place that \nisn't quite as dusky as the rest. \nSeveral more guards are on watch than usual, probably due to the \nrecent events around the castle. \nThey stand dutifully, not to be disturbed. A guard, Brundir (who you would \nalmost call a friend,) stands at the entrance to the castle.");
     GameActor* brundir = new GameActor(8,"Brundir","The guard Brundir, he is a pretty nice fellow.",Courtyard);
	 brundir->setSpeach("Brundir: \"'Ay, mate. So I imagine the Queen's got you going after the bastard \nwho did this, eh? Here, take my shield. It'll keep you a lot safer than that \npuny dagger you pack around.\"");
     Courtyard->addActor(brundir);
     Courtyard->addItem(shield);
  
  //Fountain
     GameRoom* Fountain = new GameRoom(10,"Fountain","The water runs crisp and cool");
     Fountain->addItem(fountain);
  
  //Castle Road
     GameRoom* CastleRoad = new GameRoom(11,"Castle Road","The road leads down into the town of Nightoak, \nbut it has been blocked off by a large barricade. \nApparently, the guards don't want townsfolk around the castle at this time. \nYou do notice a cheery looking cat, though.");
     GameActor* cat = new GameActor(7,"Cat","Stupid cat",CastleRoad);
	 cat->setHostile(true);
	 cat->setSpeach("Cat: HISSSS!");
     CastleRoad->addActor(cat);
  
  //Nightoak Forest
     GameRoom* NightoakForest = new GameRoom(12,"Nightoak Forest","Tall, dead trees hang their limbs above your head.");
  
  
  //Your Cabin
     GameRoom* YourCabin = new GameRoom(13,"Your Cabin","It's small and cozy, and off the trail a little bit. \nYou only have a bed and a stove, and that's all you really want.");
     YourCabin->addItem(bed);
   
  //Ivarr's Hideout
     GameRoom* IvarrsHideout = new GameRoom(14,"Ivarr's Hideout","You step forward towards a little cabin, even smaller than your own. \nYou see a scared man through the window. It looks like Ivarr... \nHe approaches you, with a sigh of relief.");
     GameActor* ivarr = new GameActor(9,"Ivarr","Crafty individual.",IvarrsHideout, 100);
	 ivarr->setHostile(true);
	 ivarr->getInventory()->addItem(key);
	 key->setContainer(chest);
	 ivarr->setSpeach("Ivarr: \"Oh, it's you Bogey. This..this is my little cabin, I had to get away for a while.\"\n\n\"Wait, what? What do you mean 'I know it was you?' Have you learned \nof my so-called 'jealousy?' The throne should never have been his to begin with; he could never be the leader that Nightoak needs!  When he dies, I'm next \nin line and I will lead our people to prosper! But.. now you stand in my way.\"");
     IvarrsHideout->addActor(ivarr);
	 ivarr->setStrength(25);
     
  
  //Broom Closet
     GameRoom* BroomCloset = new GameRoom(15,"Broom Closet","You and Hilde certainly have made some memories here.");
  
  
  //SET DEM ROOM POINTERS!
	 sword->setTarget(player);
	 shield->setTarget(player);
	 potion->setTarget(player);
	 fountain->setTarget(player);
     QueensChambers->setWestRoom(CastleFoyer);
     CastleFoyer->setNorthRoom(ThroneRoom);
     CastleFoyer->setSouthRoom(Courtyard);
     CastleFoyer->setEastRoom(QueensChambers);
     CastleFoyer->setWestRoom(MasterChambers);
     MasterChambers->setEastRoom(CastleFoyer);
     ThroneRoom->setSouthRoom(CastleFoyer);
     ThroneRoom->setEastRoom(EntertainmentArea);
     ThroneRoom->setWestRoom(DiningHall);
     EntertainmentArea->setNorthRoom(GuestBedroom);
	 EntertainmentArea->setNorthRoomRequiredItem(gbKey);
     EntertainmentArea->setWestRoom(ThroneRoom);
     GuestBedroom->setSouthRoom(EntertainmentArea);
     DiningHall->setEastRoom(ThroneRoom);
     DiningHall->setWestRoom(Kitchen);
     Kitchen->setEastRoom(DiningHall);
     Kitchen->setSouthRoom(BroomCloset);
     BroomCloset->setNorthRoom(Kitchen);
     Courtyard->setNorthRoom(CastleFoyer);
     Courtyard->setSouthRoom(Fountain);
     Courtyard->setEastRoom(NightoakForest);
     Fountain->setNorthRoom(Courtyard);
     Fountain->setSouthRoom(CastleRoad);
     CastleRoad->setNorthRoom(Fountain);
     NightoakForest->setNorthRoom(IvarrsHideout);
     NightoakForest->setSouthRoom(YourCabin);
	 NightoakForest->setWestRoom(Courtyard);
     YourCabin->setNorthRoom(NightoakForest);
     IvarrsHideout->setSouthRoom(NightoakForest);

	string title = (
		"  _   _  _         _      _      ____          _    "
		"\n | \\ | |(_)       | |    | |    / __ \\        | |   "
		"\n |  \\| | _   __ _ | |__  | |_  | |  | |  __ _ | | __"
		"\n | . ' || | / _' || '_ \\ | __| | |  | | / _' || |/ /"
		"\n | |\\  || || (_| || | | || |_  | |__| || (_| ||   < "
		"\n |_| \\_||_| \\__, ||_| |_| \\__|  \\____/  \\__,_||_|\\_\\"
		"\n             __/ |                                  "
		"\n            |___/                                   ");

	Game game = Game(title,player,"Congratulations! You saved the King of Nightoak!","Game Over! The King is doomed!");
	game.setEndGameItem(crown);
	return game;
}