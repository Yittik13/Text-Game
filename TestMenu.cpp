#include <ncurses.h>

#include "TestMenu.hpp"

void TestMenu::clearDisplay(unsigned int start, unsigned int numLines) {
    int i;
    
    if (start > numLines) {
	return;
    }
    else {
	for (i = start; i < numLines; i++) {
	    mvprintw(i, 0, "\n");
	}
    }
}

void TestMenu::printMenuOptions() {
    mvprintw(0, 0, "TEST MENU\n");
    mvprintw(2, 0, "1 - Create Player Party\n");
    mvprintw(3, 0, "2 - Create Enemy Party\n");
    mvprintw(4, 0, "3 - Simulate Battle\n");
    mvprintw(5, 0, "q - Quit\n");
}

void TestMenu::printCreatePartyOptions() {
    mvprintw(0, 0, "CREATING A PARTY\n");
    mvprintw(2, 0, "1 - Edit a unit\n");
    mvprintw(3, 0, "2 - Add a member\n");
    mvprintw(4, 0, "3 - Remove a member\n");
    mvprintw(5, 0, "b - Back\n");
}

void TestMenu::printUnitEditOptions() {
    mvprintw(2, 0, "0 - Edit Health\n");
    mvprintw(3, 0, "1 - Edit Strength\n");
    mvprintw(4, 0, "2 - Edit Speed\n");
    mvprintw(5, 0, "b - Back\n");
}

void TestMenu::updateMemberInfo() {
    int i;
    
    mvprintw(20, 0, "Current Units\n");
    mvprintw(21, 0, "%s: Health: %d, Strength: %d, Speed: %d\n", member0 -> getName(), member0 -> getHealth(), member0 -> getStrength(), member0 -> getSpeed());
    mvprintw(22, 0, "%s: Health: %d, Strength: %d, Speed: %d\n", member1 -> getName(), member1 -> getHealth(), member1 -> getStrength(), member1 -> getSpeed());
    mvprintw(23, 0, "%s: Health: %d, Strength: %d, Speed: %d\n", member2 -> getName(), member2 -> getHealth(), member2 -> getStrength(), member2 -> getSpeed());
    mvprintw(24, 0, "%s: Health: %d, Strength: %d, Speed: %d\n", member3 -> getName(), member3 -> getHealth(), member3 -> getStrength(), member3 -> getSpeed());

    mvprintw(27, 0, "Current Party\n");
    for (i = 0; i < playerParty -> getNumMembers(); i++) {
	mvprintw(28 + i, 0, "%s: Health: %d, Strength: %d, Speed: %d\n", playerParty -> members[i] -> getName(), playerParty -> members[i] -> getHealth(), playerParty -> members[i] -> getStrength(), playerParty -> members[i] ->getSpeed());
    }
}

void TestMenu::editMembers() {
    int userInput;
    int memberSelection;
    int healthInput;
    int strengthInput;
    int speedInput;
    
    clearDisplay(1, 30);
    mvprintw(1, 0, "EDITING UNITS\n");
    mvprintw(2, 0, "0 - Edit Member 0\n");
    mvprintw(3, 0, "1 - Edit Member 1\n");
    mvprintw(4, 0, "2 - Edit Member 2\n");
    mvprintw(5, 0, "3 - Edit Member 3\n");
    mvprintw(6, 0, "b - Back\n");
	    
    updateMemberInfo();
	

    while ((memberSelection = getch()) != 'b') {

	
	switch(memberSelection - '0') {

	case 0:
	    clearDisplay(0, 50);
	    mvprintw(0, 0, "EDITING MEMBER 0\n");
	    printUnitEditOptions();
	    updateMemberInfo();
	    
	    while ((userInput = getch()) != 'b') {
		switch (userInput - '0') {

		case 0: /* Edit Health */
		    mvprintw(7, 0, "Enter a Health Value (0 - 9999)\n");
		    scanw((char *) "%d", &healthInput);
		    if (healthInput < 0 || healthInput > 9999) {
			mvprintw(7, 0, "Incorrect Health Range\n");
		    }
		    else {
			member0 -> setHealth(healthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Health set to: %d\n", healthInput);
		    }
		    break;
		    
		case 1: /* Edit Strength */
		    mvprintw(7, 0, "Enter a Strength Value (0 - 99)\n");
		    scanw((char *) "%d", &strengthInput);
		    if (strengthInput < 0 || strengthInput > 99) {
			mvprintw(7, 0, "Incorrect Strength Range\n");
		    }
		    else {
			member0 -> setStrength(strengthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Strength set to: %d\n", strengthInput);
		    }
		    break;
		    
		case 2: /*Edit Speed */
		    mvprintw(7, 0, "Enter a Speed Value (0 - 99)\n");
		    scanw((char *) "%d", &speedInput);
		    if (speedInput < 0 || speedInput > 99) {
			mvprintw(7, 0, "Incorrect Speed Range\n");
		    }
		    else {
			member0 -> setSpeed(speedInput);
			updateMemberInfo();
			mvprintw(7, 0, "Speed set to: %d\n", speedInput);
		    }
		    break;

		default:
		    
		    break;
		}
	    }
	    clearDisplay(0, 30);
	    mvprintw(1, 0, "EDITING UNITS\n");
	    mvprintw(2, 0, "0 - Edit Member 0\n");
	    mvprintw(3, 0, "1 - Edit Member 1\n");
	    mvprintw(4, 0, "2 - Edit Member 2\n");
	    mvprintw(5, 0, "3 - Edit Member 3\n");
	    mvprintw(6, 0, "b - Back\n");
	    
	    updateMemberInfo();
	    break;

	case 1:
	    clearDisplay(0, 50);
	    mvprintw(0, 0, "EDITING MEMBER 1\n");
	    printUnitEditOptions();
	    updateMemberInfo();
	    
	    while ((userInput = getch()) != 'b') {
		switch (userInput - '0') {

		case 0: /* Edit Health */
		    mvprintw(7, 0, "Enter a Health Value (0 - 9999)\n");
		    scanw((char *) "%d", &healthInput);
		    if (healthInput < 0 || healthInput > 9999) {
			mvprintw(7, 0, "Incorrect Health Range\n");
		    }
		    else {
			member1 -> setHealth(healthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Health set to: %d\n", healthInput);
		    }
		    break;
		    
		case 1: /* Edit Strength */
		    mvprintw(7, 0, "Enter a Strength Value (0 - 99)\n");
		    scanw((char *) "%d", &strengthInput);
		    if (strengthInput < 0 || strengthInput > 99) {
			mvprintw(7, 0, "Incorrect Strength Range\n");
		    }
		    else {
			member1 -> setStrength(strengthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Strength set to: %d\n", strengthInput);
		    }
		    break;
		    
		case 2: /*Edit Speed */
		    mvprintw(7, 0, "Enter a Speed Value (0 - 99)\n");
		    scanw((char *) "%d", &speedInput);
		    if (speedInput < 0 || speedInput > 99) {
			mvprintw(7, 0, "Incorrect Speed Range\n");
		    }
		    else {
			member1 -> setSpeed(speedInput);
			updateMemberInfo();
			mvprintw(7, 0, "Speed set to: %d\n", speedInput);
		    }
		    break;

		default:
		    
		    break;
		}
	    }
	    clearDisplay(0, 30);
	    mvprintw(1, 0, "EDITING UNITS\n");
	    mvprintw(2, 0, "0 - Edit Member 0\n");
	    mvprintw(3, 0, "1 - Edit Member 1\n");
	    mvprintw(4, 0, "2 - Edit Member 2\n");
	    mvprintw(5, 0, "3 - Edit Member 3\n");
	    mvprintw(6, 0, "b - Back\n");
	    
	    updateMemberInfo();
	    break;
	    
	case 2:
	    clearDisplay(0, 50);
	    mvprintw(0, 0, "EDITING MEMBER 2\n");
	    printUnitEditOptions();
	    updateMemberInfo();
	    
	    while ((userInput = getch()) != 'b') {
		switch (userInput - '0') {

		case 0: /* Edit Health */
		    mvprintw(7, 0, "Enter a Health Value (0 - 9999)\n");
		    scanw((char *) (char *) "%d", &healthInput);
		    if (healthInput < 0 || healthInput > 9999) {
			mvprintw(7, 0, "Incorrect Health Range\n");
		    }
		    else {
			member2 -> setHealth(healthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Health set to: %d\n", healthInput);
		    }
		    break;
		    
		case 1: /* Edit Strength */
		    mvprintw(7, 0, "Enter a Strength Value (0 - 99)\n");
		    scanw((char *) "%d", &strengthInput);
		    if (strengthInput < 0 || strengthInput > 99) {
			mvprintw(7, 0, "Incorrect Strength Range\n");
		    }
		    else {
			member2 -> setStrength(strengthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Strength set to: %d\n", strengthInput);
		    }
		    break;
		    
		case 2: /*Edit Speed */
		    mvprintw(7, 0, "Enter a Speed Value (0 - 99)\n");
		    scanw((char *) "%d", &speedInput);
		    if (speedInput < 0 || speedInput > 99) {
			mvprintw(7, 0, "Incorrect Speed Range\n");
		    }
		    else {
			member2 -> setSpeed(speedInput);
			updateMemberInfo();
			mvprintw(7, 0, "Speed set to: %d\n", speedInput);
		    }
		    break;

		default:
		    
		    break;
		}
	    }
	    clearDisplay(0, 30);
	    mvprintw(1, 0, "EDITING UNITS\n");
	    mvprintw(2, 0, "0 - Edit Member 0\n");
	    mvprintw(3, 0, "1 - Edit Member 1\n");
	    mvprintw(4, 0, "2 - Edit Member 2\n");
	    mvprintw(5, 0, "3 - Edit Member 3\n");
	    mvprintw(6, 0, "b - Back\n");
	    
	    updateMemberInfo();
	    break;
	    
	case 3:
	    clearDisplay(0, 50);
	    mvprintw(0, 0, "EDITING MEMBER 3\n");
	    printUnitEditOptions();
	    updateMemberInfo();
	    
	    while ((userInput = getch()) != 'b') {
		switch (userInput - '0') {

		case 0: /* Edit Health */
		    mvprintw(7, 0, "Enter a Health Value (0 - 9999)\n");
		    scanw((char *) "%d", &healthInput);
		    if (healthInput < 0 || healthInput > 9999) {
			mvprintw(7, 0, "Incorrect Health Range\n");
		    }
		    else {
			member3 -> setHealth(healthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Health set to: %d\n", healthInput);
		    }
		    break;
		    
		case 1: /* Edit Strength */
		    mvprintw(7, 0, "Enter a Strength Value (0 - 99)\n");
		    scanw((char *) "%d", &strengthInput);
		    if (strengthInput < 0 || strengthInput > 99) {
			mvprintw(7, 0, "Incorrect Strength Range\n");
		    }
		    else {
			member3 -> setStrength(strengthInput);
			updateMemberInfo();
			mvprintw(7, 0, "Strength set to: %d\n", strengthInput);
		    }
		    break;
		    
		case 2: /*Edit Speed */
		    mvprintw(7, 0, "Enter a Speed Value (0 - 99)\n");
		    scanw((char *) "%d", &speedInput);
		    if (speedInput < 0 || speedInput > 99) {
			mvprintw(7, 0, "Incorrect Speed Range\n");
		    }
		    else {
			member3 -> setSpeed(speedInput);
			updateMemberInfo();
			mvprintw(7, 0, "Speed set to: %d\n", speedInput);
		    }
		    break;

		default:
		    
		    break;
		}
	    }
	    clearDisplay(0, 30);
	    mvprintw(1, 0, "EDITING UNITS\n");
	    mvprintw(2, 0, "0 - Edit Member 0\n");
	    mvprintw(3, 0, "1 - Edit Member 1\n");
	    mvprintw(4, 0, "2 - Edit Member 2\n");
	    mvprintw(5, 0, "3 - Edit Member 3\n");
	    mvprintw(6, 0, "b - Back\n");
	    
	    updateMemberInfo();
	    break;

	default:
	    
	    break;
	}
    }
    clearDisplay(0, 100);
    printCreatePartyOptions();
}

void TestMenu::addMembers() {
    int memberSelection;

    clearDisplay(1, 100);
    mvprintw(1, 0, "ADDING MEMBERS TO PARTY\n");
    mvprintw(2, 0, "0 - Add Member 0 to Party\n");
    mvprintw(3, 0, "1 - Add Member 1 to Party\n");
    mvprintw(4, 0, "2 - Add Member 2 to Party\n");
    mvprintw(5, 0, "3 - Add Member 3 to Party\n");
    mvprintw(6, 0, "b - Back\n");
    updateMemberInfo();

    while ((memberSelection = getch()) != 'b') {
	switch (memberSelection - '0') {

	case 0:
	    if (member0 -> partyPosition == -1) {
		member0 -> partyPosition = playerParty -> getNumMembers();
		playerParty -> addMember(member0);
		mvprintw(10, 0, "Added member 0 to the party\n");
		updateMemberInfo();
	    }
	    else {
		mvprintw(10, 0, "This member is already in the party\n");
	    }
	    break;

	case 1:
	    if (member1 -> partyPosition == -1) {
		member1 -> partyPosition = playerParty -> getNumMembers();
		playerParty -> addMember(member1);
		mvprintw(10, 0, "Added member 1 to the party\n");
		updateMemberInfo();
	    }
	    else {
		mvprintw(10, 0, "This member is already in the party\n");
	    }
	    break;

	case 2:
	    if (member2 -> partyPosition == -1) {
		member2 -> partyPosition = playerParty -> getNumMembers();
		playerParty -> addMember(member2);
		mvprintw(10, 0, "Added member 2 to the party\n");
		updateMemberInfo();
	    }
	    else {
		mvprintw(10, 0, "This member is already in the party\n");
	    }
	    break;

	case 3:
	    if (member3 -> partyPosition == -1) {
		member3 -> partyPosition = playerParty -> getNumMembers();
		playerParty -> addMember(member3);
		mvprintw(10, 0, "Added member 3 to the party\n");
		updateMemberInfo();
	    }
	    else {
		mvprintw(10, 0, "This member is already in the party\n");
	    }
	    break;

	default:

	    break;
	}
    }
    clearDisplay(1, 100);
    printCreatePartyOptions();
}

void TestMenu::removeMembers() {
    int memberSelection;

    clearDisplay(1, 100);

    mvprintw(2, 0, "REMOVING UNITS FROM PARTY\n");
    mvprintw(3, 0, "0 - Remove Member from position 0 from Party\n");
    mvprintw(4, 0, "1 - Remove Member from position 1 from Party\n");
    mvprintw(5, 0, "2 - Remove Member from position 2 from Party\n");
    mvprintw(6, 0, "3 - Remove Member from position 3 from Party\n");
    mvprintw(7, 0, "b - Back\n");
    updateMemberInfo();

    while ((memberSelection = getch() - '0') != 'b') {
	switch (memberSelection) {
	case 0:
	    //mvprintw(8, 0, "MembersSelection: %d\n", memberSelection);
	    //mvprintw(9, 0, "Num Members: %d\n", playerParty -> getNumMembers());
	    if (memberSelection >= playerParty -> getNumMembers()) {
		mvprintw(10, 0, "There is not a Party Member at that position\n");
	    }
	    else {
		playerParty -> members[0] -> partyPosition = -1;
		playerParty -> removeMember(0);
		clearDisplay(27, 100);
		updateMemberInfo();
	    }
	    break;

	case 1:
	    if (memberSelection >= playerParty -> getNumMembers()) {
		mvprintw(10, 0, "There is not a Party Member at that position\n");
	    }
	    else {
		playerParty -> members[1] -> partyPosition = -1;
		playerParty -> removeMember(1);
		clearDisplay(27, 100);
		updateMemberInfo();
	    }
	    break;

	case 2:
	    if (memberSelection >= playerParty -> getNumMembers()) {
		mvprintw(10, 0, "There is not a Party Member at that position\n");
	    }
	    else {
		playerParty -> members[2] -> partyPosition = -1;
		playerParty -> removeMember(2);
		clearDisplay(27, 100);
		updateMemberInfo();
	    }
	    break;

	case 3:
	    if (memberSelection >= playerParty -> getNumMembers()) {
		mvprintw(10, 0, "There is not a Party Member at that position\n");
	    }
	    else {
		playerParty -> members[3] -> partyPosition = -1;
		playerParty -> removeMember(3);
		clearDisplay(27, 100);
		updateMemberInfo();
	    }
	    break;

	default:

	    break;
	}
    }
    clearDisplay(1, 100);
    printCreatePartyOptions();
}

void TestMenu::createPlayerParty() {
    int userInput;

    clearDisplay(0, 10);

    printCreatePartyOptions();

    if (this -> playerParty == nullptr) {
	this -> playerParty = new Party();
	//mvprintw(11, 0, "Party instantiated\n");
    }
    else {
	//mvprintw(11, 0, "Party already Created\n");
    }

    while ((userInput = getch()) != 'b') {
	
	switch(userInput - '0') {
	    
	case 1: /* Edit a unit's stats */
	    editMembers();
	    break;

	case 2: /* Add a unit to the party */
	    addMembers();
	    break;

	case 3: /* Remove a unit from the party */
	    removeMembers();
	    break;
	    
	default:

	    break;
	}
    }
    clearDisplay(0, 30);
    printMenuOptions();
}

void TestMenu::createEnemyParty() {
    this -> enemyParty = new class enemyParty();
}

void TestMenu::simulateBattle(Party *playerParty, class enemyParty *enemyParty) {
    Battle *battle = new Battle("BATTLE", playerParty, enemyParty);
    battle -> runBattle();
}

void TestMenu::runMenu() {
    int userInput;

    initscr();
    noecho();
    curs_set(FALSE);
    refresh();

    printMenuOptions();

    while ((userInput = getch()) != 'q') {
	switch (userInput - '0') {
	case 1:
	    createPlayerParty();
	    break;

	case 2:
	    createEnemyParty();
	    break;

	case 3:
	    if (this -> playerParty == nullptr || this -> enemyParty == nullptr) {
		break;
	    }
	    
	    if ((this -> playerParty -> getNumMembers()) <= 0 || (enemyParty -> getNumEnemies()) <= 0) {
		break;
	    }
	    
	    simulateBattle(playerParty, enemyParty);
	    break;

	default:

	    break;
	}
    }
    endwin();
}
