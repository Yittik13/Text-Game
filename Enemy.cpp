#include <ncurses.h>

#include "Party.hpp"
#include "Enemy.hpp"

Enemy::Enemy(const char *name, int health, int strength, int speed) {
	this -> name = name;
	this -> health = health;
	this -> maxHealth = health;
	this -> strength = strength;
	this -> speed = speed;
	this -> isAlive = true;
	srand(time(NULL));
}

/*
   Enemy::~Enemy() {
   free(name);
   }
 */
void Enemy::attack(int &playerHealth) {
	int damage = (strength * 100) + (rand() % (strength * 10));
	if (isAlive) {
		playerHealth = playerHealth - damage;
		if (playerHealth <= 0) {
			playerHealth = 0;
		}
		mvprintw(36 + partyPosition, 0, "%s hit for %d damage\n", this -> name, damage);
	}
	//return rand() %this -> strength + 1;
}

Action Enemy::generateAction(Party *playerParty, int numPartyMembers) {
	Action action;
	int target;

	do {
		target = rand() % numPartyMembers;
	} while (!(playerParty -> members[target] -> isAlive));

	action.speed = this -> speed;
	action.type = ENEMY_ATTACK_ACTION;
	action.unit = partyPosition;
	action.target = target;
	action.executed = false;

	return action;
}

enemyParty::enemyParty() {
	this -> numEnemies = 0;
}

int enemyParty::addEnemy(Enemy *enemy) {
	if (numEnemies < MAX_ENEMY_COUNT) {
		this -> enemies[numEnemies] = enemy;
		this -> numEnemies++;
		return 0;
	}
	else {
		printf("ERROR: Enemy party full\n");
		return -1;
	}
}

int enemyParty::removeEnemy(unsigned int position) {
	if (position >= this -> numEnemies) {
		printf("ERROR: Incorrect Position\n");
		return -1;
	}
	else {
		int i;
		this -> enemies[position] = NULL;
		this -> numEnemies--;
		for (i = position; i < numEnemies; i++) {
			this -> enemies[i] = this -> enemies[i + 1];
		}
		return 0;
	}
}
