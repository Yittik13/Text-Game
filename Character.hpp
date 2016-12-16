#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Character {
	public:

		//TODO: Add more stats and change how damage works
		const char *name;
		int health;
		int maxHealth;
		int strength;
		int speed;
		int partyPosition;
		bool isAlive;

		Character(const char *name, int health, int strength, int speed);
		//virtual ~Character();

		void getInfo() {
			printf("\nCHARACTER INFO\n");
			printf("Name: %s\nHealth: %d\nStrength: %d\n", name, health, strength);	
		}

		const char *getName() {
			return name;
		}

		int getHealth() {
			return health;
		}
		
		int getSpeed() {
			return speed;
		}

		int getStrength() {
			return strength;
		}

		void setHealth(int health) {
			this -> health = health;
			this -> maxHealth = health;
		}

		void setStrength(int strength) {
			this -> strength = strength;
		}

		void setSpeed(int speed) {
			this -> speed = speed;
		}

		void attack(int &enemyHealth);
};

#endif
