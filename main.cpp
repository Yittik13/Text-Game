#include <stdio.h>
#include <string.h>

#include "Character.hpp"
#include "Enemy.hpp"
#include "Gamestate.hpp"
#include "Debug.hpp"
#include "Stack.hpp"
#include "Party.hpp"
#include "Battle.hpp"
#include "PriorityQueue.hpp"
#include "TestMenu.hpp"

Debug debugger;
Stack stack;

int main(int argc, char **argv) {
    if (argc == 1) {
	printf("\nStarted in non-debug mode\n\n");
	//printf("Run with -help for how to run in debug mode and for a list of debugging types\n\n");
    }
    else if (argc == 2) {
	if (strcmp(argv[1], "-help") == 0) {
	    //printf("\nHelp Information\n");
	    //printf("To run in debug mode, use './main -debug <Level of Debugging>'\n");
	    //printf("Debugging Levels:\n0 - Off\n1 - Character Stats\n2 - Enemy Stats\n3 - Character and Enemy Stats\n4 - Character Damage\n5 - Enemy Damage\n6 - Character and Enemy Damage\n7 - Gamestate\n");
	    return 0;
	}
	else {
	    printf("Usage: './main -help' OR './main -debug <Debug Type>\n");
	    return -1;
	}
    }
    else if (argc == 3) {
	if (strcmp(argv[1], "-debug") == 0) {
	    int types = atoi(argv[2]);
	    if (!(types & ~DEBUG_TYPE_MASK)) {
		debugger.setDebugTypes(types);
	    }
	    else {
		printf("Usage: './main -debug <Debug TYPES (0x%0x)>'\n", DEBUG_TYPE_MASK);
		return -1;
	    }
	}
    }
    //char tilith_n[] = "Tilith";
    //char lucius_n[] = "Lucius";

    Character *tilith = new Character("Tilith", 1000, 99, 100);
    Character *avant = new Character("Avant", 2000, 99, 110);
    Character *eze = new Character("Eze", 3000, 99, 120);
    Character *selena = new Character("Selena", 3000, 99, 130);

	tilith -> partyPosition = 0;
	avant -> partyPosition = 1;
	eze -> partyPosition = 2;
	selena -> partyPosition = 3;
    //Character *griff = new Character("Griff", 3000, 20);
    Enemy *lucius = new Enemy("Lucius", 1000000, 10, 90);
	
    //lucius -> attack(tilith -> health);
    //lucius -> attack(tilith -> health);
    //printf("%d\n", tilith -> getHealth());
    //debugger.debug(DEBUG_TYPE_CHARACTER_STATS, "Character Info\nName: %s\nHealth: %d\n", tilith -> getName(), tilith -> getHealth());
    //tilith -> getInfo();
    //printf("\nName: %s\n", tilith -> getName());
    //printf("\nHealth: %d\n\n", tilith -> getHealth());

    //lucius -> getInfo();
    //printf("\nName: %s\n", lucius -> getName());
    //printf("\nHealth: %d\n\n", lucius -> getHealth());

    //int i;
    //printf("\nTilith Attacks Test\n");
    //for (i = 0; i < 50; i++) {
    //printf("Attack %d: %d\n", i + 1, tilith -> attack());
    //}

    //printf("\nLucius Attacks Test\n");
    //for (i = 0; i < 50; i++) {
    //printf("Attack %d: %d\n", i + 1, lucius -> attack());
    //}
    //Gamestate *battle = new Gamestate("Battle");
    //stack.push(battle);
    //stack.print();
    //stack.pop();
    //stack.print();
    //printf("%s\n", (stack.peek()) -> getType());

    Party *party = new Party();
    enemyParty *enemy_party = new enemyParty();

    party -> addMember(tilith);
    party -> addMember(avant);
    party -> addMember(eze);
    party -> addMember(selena);

    enemy_party -> addEnemy(lucius);
    //party -> addMember(griff);
    //party -> getInfo();
    //enemy_party -> getEnemyPartyInfo();
    //party -> swapMembers(0, 3);
    //party -> removeMember(-1);
    //party -> getInfo();

    //Battle *battle = new Battle("BATTLE", party, enemy_party);	
    //battle -> getInfo();
	//battle -> runBattle();

	TestMenu *testMenu = new TestMenu();
	testMenu -> runMenu();
	
/*
	PriorityQueue *pqueue = new PriorityQueue(party, enemy_party);
	//pqueue -> print();
	//pqueue -> execute();
	//pqueue -> print();

	Action one;
	Action two;
	Action three;
	Action four;
	Action five;
	
	one.speed = 100;
	one.type = PLAYER_ATTACK_ACTION;
	one.unit = 0;
	one.target = 0;
	one.executed = false;

	two.speed = 100;
	two.type = PLAYER_ATTACK_ACTION;
	two.unit = 1;
	two.target = 0;
	two.executed = false;

	three.speed = 50;
	three.type = PLAYER_ATTACK_ACTION;
	three.unit = 2;
	three.target = 0;
	three.executed = false;

	four.speed = 300;
	four.type = PLAYER_ATTACK_ACTION;
	four.unit = 3;
	four.target = 0;
	four.executed = false;

	five.speed = 1000;
	five.type = ENEMY_ATTACK_ACTION;
	five.unit = 0;
	five.target = 0;
	five.executed = false;

	//pqueue -> print();
	pqueue -> enqueue(one);
	pqueue -> enqueue(two);
	pqueue -> enqueue(three);
	pqueue -> enqueue(four);
	pqueue -> enqueue(five);
	pqueue -> print();
	tilith -> getInfo();
	lucius -> getInfo();
	pqueue -> execute();
	pqueue -> print();
	tilith -> getInfo();
	lucius -> getInfo();
*/
}
