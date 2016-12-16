#ifndef TESTMENU_H
#define TESTMENU_H

#include "Battle.hpp"

class TestMenu {
	public:
		//Menu();
		void printMenuOptions();
		void printCreatePartyOptions();
		void printUnitEditOptions();
		void updateMemberInfo();
		void clearDisplay(unsigned int start, unsigned int numLines);
		void createPlayerParty();
		void createEnemyParty();
		void editMembers();
		void addMembers();
		void removeMembers();
		void simulateBattle(Party *playerParty, enemyParty *enemyParty);

		void runMenu();

	private:
		Party *playerParty = nullptr;
		enemyParty *enemyParty = nullptr;

		Character *member0 = new Character("Member 0", 0, 0, 0);
    	Character *member1 = new Character("Member 1", 0, 0, 0);
    	Character *member2 = new Character("Member 2", 0, 0, 0);
    	Character *member3 = new Character("Member 3", 0, 0, 0);
};

#endif
