#include <ncurses.h>
#include "Character.hpp"

Character::Character(const char *name, int health, int strength, int speed) {
    this -> name = name;
    this -> health = health;
	this -> maxHealth= health;
    this -> strength = strength; //changes to this will be made
	this -> speed = speed;
    this -> isAlive = true;
	this -> partyPosition = -1;
	srand(time(NULL));
}

void Character::attack(int &enemyHealth) { //change later
	int damage = (strength * 100) + (rand() % (strength * 10));
	if (isAlive) {
		enemyHealth = enemyHealth - damage;
		mvprintw(30 + partyPosition, 0, "%s hit for %d damage\n", this -> name, damage);
	}
//return rand() % this -> strength + 1;
}
