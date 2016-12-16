#ifndef BATTLE_H
#define BATTLE_H

#include "Gamestate.hpp"
#include "Party.hpp"
#include "Enemy.hpp"
#include "PriorityQueue.hpp"

class Battle: public Gamestate {
	public:
		Battle(const char* type, Party *playerParty, class enemyParty *enemyParty);
		void runBattle();
		int endBattle();
		void getInfo() {
			printf("\nBATTLE INFO\n");
			playerParty -> getInfo();
			enemyParty -> getEnemyPartyInfo();
		}
	
		void displayBattleCommands();
		void clearDisplay();
		void updateTotalHealth();
		void updateInfo();	

	private:
		Party *playerParty;
		enemyParty *enemyParty;
		int totalPlayerHealth;
		int totalEnemyHealth;

		//int curs_x;
		//int curs_y;
};

#endif
