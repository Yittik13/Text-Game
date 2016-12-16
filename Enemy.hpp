#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Action.hpp"
#include "Party.hpp"

#define MAX_ENEMY_COUNT 6

class Enemy {
	public:
		const char *name;
		int health;
		int maxHealth;
		int strength;
		int speed;
		int partyPosition;
		bool isAlive;

		Enemy(const char *name, int health, int strength, int speed);
		//virtual ~Enemy();

		void getInfo() {
			printf("\nENEMY INFO\n");
			printf("Name: %s\nHealth: %d\nStrength: %d\n", name, health, strength);
		}

		const char *getName() {
			return name;
		}

		int getHealth() {
			return health;
		}

		int getStrength() {
			return strength;
		}

		void attack(int &playerHealth);

		Action generateAction(Party *playerParty, int numPartyMembers);
};


class enemyParty {
	public:
		Enemy *enemies[MAX_ENEMY_COUNT];
		enemyParty();
		void getEnemyPartyInfo() {
			int i;
			printf("\nENEMY PARTY INFO\n");
			printf("Enemy Party Size: %d\n", numEnemies);
			for (i = 0; i < numEnemies; i++) {
				printf("Enemy: %d: Name: %s\n", i, enemies[i] -> getName());
			}
		}
		
		int getNumEnemies() {
			return numEnemies;
		}

		int addEnemy(Enemy *enemy);
		int removeEnemy(unsigned int position);

	private: 
		int numEnemies;
};

#endif
