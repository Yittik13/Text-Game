#include <stdlib.h>
#include <ncurses.h>

#include "Battle.hpp"

#define NUM_BATTLE_COMMANDS 3
#define BATTLE_COMMAND_START_YCOOR 20

Battle::Battle(const char *type, Party *playerParty, class enemyParty *enemyParty) {
    setType(type);
    this -> playerParty = playerParty;
    this -> enemyParty = enemyParty;
    this -> totalPlayerHealth = 0;
    this -> totalEnemyHealth = 0;
}

/*
 * DISPLAY THE POSSIBLE ACTIONS THAT CAN BE PERFORMED
 * THIS NEEDS TO BE CHANGED
 */
void Battle::displayBattleCommands() {
    mvprintw(19, 0, "PLAYER ACTION");
    mvprintw(20, 0, "1 - Attack");
    //mvprintw(21, 0, "2 - Test");
    //mvprintw(22, 0, "3 - Test");
}

void Battle::clearDisplay() {
    int i = 0;
    int y = BATTLE_COMMAND_START_YCOOR;
    move(20, 0);
    while (i <= /* NUM_BATTLE_COMMANDS */ 15) {
	clrtoeol();
	move(y++, 0);
	i++;
    }
}

/*
 * UPDATE THE CURRENT STATUS OF EACH PARTY
 */
void Battle::updateInfo() {

    int i;
    for (i = 0; i < enemyParty -> getNumEnemies(); i++) {
	if (enemyParty -> enemies[i] -> health <= 0) {
	    enemyParty -> enemies[i] -> isAlive = false;
	}
    }

    for (i = 0; i < playerParty -> getNumMembers(); i++) {
	if (playerParty -> members[i] -> health <= 0) {
	    playerParty -> members[i] -> isAlive = false;
	}
    }
    
    mvprintw(0, 0, "ENEMY PARTY\n");
	switch(this -> enemyParty -> getNumEnemies()) {
	case 1:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth); 
	    break;

	case 2:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth);

	    mvprintw(2, 0, "1: %s: HP: %d / %d\n", enemyParty -> enemies[1] -> getName(), enemyParty -> enemies[1] -> getHealth(), enemyParty -> enemies[1] -> maxHealth);
	    break;
	    
	case 3:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth);

	    mvprintw(2, 0, "1: %s: HP: %d / %d\n", enemyParty -> enemies[1] -> getName(), enemyParty -> enemies[1] -> getHealth(), enemyParty -> enemies[1] -> maxHealth);

            mvprintw(3, 0, "2: %s: HP: %d / %d\n", enemyParty -> enemies[2] -> getName(), enemyParty -> enemies[2] -> getHealth(), enemyParty -> enemies[2] -> maxHealth);
	    break;

	case 4:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth);	    

	    mvprintw(2, 0, "1: %s: HP: %d / %d\n", enemyParty -> enemies[1] -> getName(), enemyParty -> enemies[1] -> getHealth(), enemyParty -> enemies[1] -> maxHealth);

	    mvprintw(3, 0, "2: %s: HP: %d / %d\n", enemyParty -> enemies[2] -> getName(), enemyParty -> enemies[2] -> getHealth(), enemyParty -> enemies[2] -> maxHealth);

            mvprintw(4, 0, "3: %s: HP: %d / %d\n", enemyParty -> enemies[3] -> getName(), enemyParty -> enemies[3] -> getHealth(), enemyParty -> enemies[3] -> maxHealth);
	    break;

	case 5:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth);	    

	    mvprintw(2, 0, "1: %s: HP: %d / %d\n", enemyParty -> enemies[1] -> getName(), enemyParty -> enemies[1] -> getHealth(), enemyParty -> enemies[1] -> maxHealth);

	    mvprintw(3, 0, "2: %s: HP: %d / %d\n", enemyParty -> enemies[2] -> getName(), enemyParty -> enemies[2] -> getHealth(), enemyParty -> enemies[2] -> maxHealth);

            mvprintw(4, 0, "3: %s: HP: %d / %d\n", enemyParty -> enemies[3] -> getName(), enemyParty -> enemies[3] -> getHealth(), enemyParty -> enemies[3] -> maxHealth);

	    mvprintw(5, 0, "4: %s: HP: %d / %d\n", enemyParty -> enemies[4] -> getName(), enemyParty -> enemies[4] -> getHealth(), enemyParty -> enemies[4] -> maxHealth);
	    break;

	case 6:
	    mvprintw(1, 0, "0: %s: HP: %d / %d\n", enemyParty -> enemies[0] -> getName(), enemyParty -> enemies[0] -> getHealth(), enemyParty -> enemies[0] -> maxHealth);	    

	    mvprintw(2, 0, "1: %s: HP: %d / %d\n", enemyParty -> enemies[1] -> getName(), enemyParty -> enemies[1] -> getHealth(), enemyParty -> enemies[1] -> maxHealth);

	    mvprintw(3, 0, "2: %s: HP: %d / %d\n", enemyParty -> enemies[2] -> getName(), enemyParty -> enemies[2] -> getHealth(), enemyParty -> enemies[2] -> maxHealth);

            mvprintw(4, 0, "3: %s: HP: %d / %d\n", enemyParty -> enemies[3] -> getName(), enemyParty -> enemies[3] -> getHealth(), enemyParty -> enemies[3] -> maxHealth);

	    mvprintw(5, 0, "4: %s: HP: %d / %d\n", enemyParty -> enemies[4] -> getName(), enemyParty -> enemies[4] -> getHealth(), enemyParty -> enemies[4] -> maxHealth);

	    mvprintw(6, 0, "5: %s: HP: %d / %d\n", enemyParty -> enemies[5] -> getName(), enemyParty -> enemies[5] -> getHealth(), enemyParty -> enemies[5] -> maxHealth);
	    break;
	}


	
    mvprintw(10, 0, "PLAYER PARTY\n");
	switch(this -> playerParty -> getNumMembers()) {
	case 1:
	    mvprintw(11, 0, "0: %s: HP: %d / %d\n", playerParty -> members[0] -> getName(), playerParty -> members[0] -> getHealth(), playerParty -> members[0] -> maxHealth);
	    break;

	case 2:
	    mvprintw(11, 0, "0: %s: HP: %d / %d\n", playerParty -> members[0] -> getName(), playerParty -> members[0] -> getHealth(), playerParty -> members[0] -> maxHealth);
	    
	    mvprintw(12, 0, "1: %s: HP: %d / %d\n", playerParty -> members[1] -> getName(), playerParty -> members[1] -> getHealth(), playerParty -> members[1] -> maxHealth);
	    break;

	case 3:
	    mvprintw(11, 0, "0: %s: HP: %d / %d\n", playerParty -> members[0] -> getName(), playerParty -> members[0] -> getHealth(), playerParty -> members[0] -> maxHealth);
	    
	    mvprintw(12, 0, "1: %s: HP: %d / %d\n", playerParty -> members[1] -> getName(), playerParty -> members[1] -> getHealth(), playerParty -> members[1] -> maxHealth);
	    
	    mvprintw(13, 0, "2: %s: HP: %d / %d\n", playerParty -> members[2] -> getName(), playerParty -> members[2] -> getHealth(), playerParty -> members[2] -> maxHealth);
	    break;

	case 4:
	    mvprintw(11, 0, "0: %s: HP: %d / %d\n", playerParty -> members[0] -> getName(), playerParty -> members[0] -> getHealth(), playerParty -> members[0] -> maxHealth);
	    
	    mvprintw(12, 0, "1: %s: HP: %d / %d\n", playerParty -> members[1] -> getName(), playerParty -> members[1] -> getHealth(), playerParty -> members[1] -> maxHealth);
	    
	    mvprintw(13, 0, "2: %s: HP: %d / %d\n", playerParty -> members[2] -> getName(), playerParty -> members[2] -> getHealth(), playerParty -> members[2] -> maxHealth);
	    
	    mvprintw(14, 0, "3: %s: HP: %d / %d\n", playerParty -> members[3] -> getName(), playerParty -> members[3] -> getHealth(), playerParty -> members[3] -> maxHealth);
	    break;
	}
}

/*
 * UPDATE THE HEALTH TOTALS OF EACH PARTY
 */
void Battle::updateTotalHealth() {
    int i;
    this -> totalPlayerHealth = 0;
    this -> totalEnemyHealth = 0;
    for (i = 0; i < this -> playerParty -> getNumMembers(); i++) {
	this -> totalPlayerHealth += playerParty -> members[i] -> getHealth();
    }
    //printf("TPH: %d\n", this -> totalPlayerHealth);
    
    for (i = 0; i < this -> enemyParty -> getNumEnemies(); i++) {
	this -> totalEnemyHealth += enemyParty -> enemies[i] -> getHealth();
    }
    //printf("TEH: %d\n", totalEnemyHealth);
}



void Battle::runBattle() {
    PriorityQueue *pqueue = new PriorityQueue(playerParty, enemyParty);

    Action member0_action;
    Action member1_action;
    Action member2_action;
    Action member3_action;

    Action enemy0_action;
    Action enemy1_action;
    Action enemy2_action;
    Action enemy3_action;
    Action enemy4_action;
    Action enemy5_action;
    
    int userInput;
    int userTarget;
    //int partyMember;

    int i;
    int ch;
    int currentUnitTurn = 0;
    int numPartyMembers = this -> playerParty -> getNumMembers();
    int numEnemies = this -> enemyParty -> getNumEnemies();

    initscr();
    noecho();
    curs_set(FALSE);
    refresh();

    //displayBattleCommands();
    updateTotalHealth();
    updateInfo();
    //while ((ch = getch()) != 'q') {}
    //endwin();


    /*
     * While loop that runs the battle. 
     * Needs to be updated eventually to support unique abilities of party members
     */
    while (totalPlayerHealth > 0 && totalEnemyHealth > 0) { 
	
	switch(currentUnitTurn) {
	case 0: /* Unit 0's turn */
	    if (!(playerParty -> members[currentUnitTurn] -> isAlive)) {
		currentUnitTurn++;
		break;
	    }
	    
	    mvprintw(19, 0, "%s's Action\n", playerParty -> members[currentUnitTurn] -> getName());
	    mvprintw(20, 0, "1 - Attack\n");
	    mvprintw(25, 0, "Current Unit Turn: %d\n", currentUnitTurn);
	    userInput = getch() - '0';
	    
	    if (userInput == PLAYER_ATTACK_ACTION) { /* Attack Selected */
		mvprintw(20, 0, "Target Enemy (Use Number Keys to Select Enemy)\n");
		userTarget = getch() - '0';

		switch (userTarget) {
		case 0: 
		    
		    if (userTarget > numEnemies) {
			mvprintw(21, 0, "userTarget > numEnemies\n");
			userTarget = getch();
			break;
		    }

		    if (!(enemyParty -> enemies[userTarget] -> isAlive)) {
			mvprintw(21, 0, "enemy is dead\n");
			userTarget = getch();
			break;
		    }
		    
		    else {
			member0_action.speed = playerParty -> members[currentUnitTurn] -> speed;
			member0_action.type = PLAYER_ATTACK_ACTION;
			member0_action.unit = currentUnitTurn;
			member0_action.target = userTarget;
			member0_action.executed = false;
			pqueue -> enqueue(member0_action);
			currentUnitTurn++;
			mvprintw(21, 0, "Action queued, Type: %d, Acting Unit: %d, Target: %d\n", PLAYER_ATTACK_ACTION, currentUnitTurn, userTarget);
			break;
		    }

		default:
		    userTarget = getch();
		    break;
		}
	    }
	    
	    else {
		userInput = getch();
	    }
	    break;

	case 1:

	    if (!(playerParty -> members[currentUnitTurn] -> isAlive)) {
		currentUnitTurn++;
		break;
	    }
	    
	    mvprintw(19, 0, "%s's Action\n", playerParty -> members[currentUnitTurn] -> getName());
	    mvprintw(20, 0, "1 - Attack\n");
	    mvprintw(25, 0, "Current Unit Turn: %d\n", currentUnitTurn);
	    userInput = getch() - '0';
	    
	    if (userInput == PLAYER_ATTACK_ACTION) {
		mvprintw(20, 0, "Target Enemy (Use Number Keys to Select Enemy)\n");
		userTarget = getch() - '0';

		switch (userTarget) {
		case 0:
		    
		    if (userTarget > numEnemies) {
			userTarget = getch();
			break;
		    }

		    if (!(enemyParty -> enemies[userTarget] -> isAlive)) {
			userTarget = getch();
			break;
		    }
		    
		    else {
			member1_action.speed = playerParty -> members[currentUnitTurn] -> speed;
			member1_action.type = PLAYER_ATTACK_ACTION;
			member1_action.unit = currentUnitTurn;
			member1_action.target = userTarget;
			member1_action.executed = false;
			pqueue -> enqueue(member1_action);
			currentUnitTurn++;
			mvprintw(21, 0, "Action queued, Type: %d, Acting Unit: %d, Target: %d\n", PLAYER_ATTACK_ACTION, currentUnitTurn, userTarget);
			break;
		    }

		default:
		    userTarget = getch();
		    break;
		}
	    }
	    
	    else {
		userInput = getch();
	    }
	    break;

	case 2:

	    if (!(playerParty -> members[currentUnitTurn] -> isAlive)) {
		currentUnitTurn++;
		break;
	    }

	    mvprintw(19, 0, "%s's Action\n", playerParty -> members[currentUnitTurn] -> getName());
	    mvprintw(20, 0, "1 - Attack\n");
	    mvprintw(25, 0, "Current Unit Turn: %d\n", currentUnitTurn);
	    userInput = getch() - '0';
	    
	    if (userInput == PLAYER_ATTACK_ACTION) {
		mvprintw(20, 0, "Target Enemy (Use Number Keys to Select Enemy)\n");
		userTarget = getch() - '0';

		switch (userTarget) {
		case 0:
		    
		    if (userTarget > numEnemies) {
			userTarget = getch();
			break;
		    }

		    if (!(enemyParty -> enemies[userTarget] -> isAlive)) {
			userTarget = getch();
			break;
		    }
		    
		    else {
			member2_action.speed = playerParty -> members[currentUnitTurn] -> speed;
			member2_action.type = PLAYER_ATTACK_ACTION;
			member2_action.unit = currentUnitTurn;
			member2_action.target = userTarget;
			member2_action.executed = false;
			pqueue -> enqueue(member2_action);
			currentUnitTurn++;
			mvprintw(21, 0, "Action queued, Type: %d, Acting Unit: %d, Target: %d\n", PLAYER_ATTACK_ACTION, currentUnitTurn, userTarget);
			break;
		    }

		default:
		    userTarget = getch();
		    break;
		}
	    }
	    
	    else {
		userInput = getch();
	    }
	    break;

	case 3:
	    
	    if (!(playerParty -> members[currentUnitTurn] -> isAlive)) {
		currentUnitTurn++;
		break;
	    }
	    
	    mvprintw(19, 0, "%s's Action\n", playerParty -> members[currentUnitTurn] -> getName());
	    mvprintw(20, 0, "1 - Attack\n");
	    mvprintw(25, 0, "Current Unit Turn: %d\n", currentUnitTurn);
	    userInput = getch() - '0';
	    
	    if (userInput == PLAYER_ATTACK_ACTION) {
		mvprintw(20, 0, "Target Enemy (Use Number Keys to Select Enemy)\n");
		userTarget = getch() - '0';

		switch (userTarget) {
		case 0:
		    
		    if (userTarget > numEnemies) {
			userTarget = getch();
			break;
		    }

		    if (!(enemyParty -> enemies[userTarget] -> isAlive)) {
			userTarget = getch();
			break;
		    }
		    
		    else {
			member3_action.speed = playerParty -> members[currentUnitTurn] -> speed;
			member3_action.type = PLAYER_ATTACK_ACTION;
			member3_action.unit = currentUnitTurn;
			member3_action.target = userTarget;
			member3_action.executed = false;
			pqueue -> enqueue(member3_action);
			currentUnitTurn++;
			mvprintw(21, 0, "Action queued, Type: %d, Acting Unit: %d, Target: %d\n", PLAYER_ATTACK_ACTION, currentUnitTurn, userTarget);
			break;
		    }

		default:
		    userTarget = getch() - '0';
		    break;
		}
	    }
	    
	    else {
		userInput = getch();
	    }
	    break;

	default:
	    for (i = 0; i < numEnemies; i++) {
		pqueue -> enqueue(enemyParty -> enemies[i] -> generateAction(playerParty, numPartyMembers));
	    }
	    pqueue -> execute();
	    pqueue -> reset();
	    currentUnitTurn = 0;
	    updateTotalHealth();
	    updateInfo();
	    break;
	}
    }
    
    if (this -> totalEnemyHealth <= 0) {
	mvprintw(19, 0, "Enemy Defeated, 'q' to continue\n");
    }

    else if (this -> totalPlayerHealth <= 0) {
	mvprintw(19, 0, "Game Over, 'q' to restart\n");
    }
    while ((ch = getch()) != 'q') {}
    endwin();
}
