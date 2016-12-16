#ifndef PARTY_H
#define PARTY_H

#include "Character.hpp"
//#include "Enemy.hpp"

#define MAX_PARTY_SIZE 4
//#define MAX_ENEMY_COUNT 6

class Party {
	public:
		Character *members[MAX_PARTY_SIZE];
		//Enemy *enemies[MAX_ENEMY_COUNT];
		Party();
		void getInfo() {
			int i;
			printf("\nPARTY INFO\n");
			printf("Current Party Size: %d\n", numMembers);
			for(i = 0; i < numMembers; i++) {
				printf("Member %d: Name: %s\n", i, members[i] -> getName());
			}
		}
/*
		void getEnemyPartyInfo() {
			int i;
			printf("\nENEMY PARTY INFO\n");
			printf("Enemy Party Size: %d\n", numEnemies);
			for(i = 0; i < numEnemies; i++) {
				printf("Enemy: %d: Name: %s\n", i, enemies[i] -> getName());
			}
		}
*/

		int getNumMembers() {
			return numMembers;
		}
/*		
		int getNumEnemies() {
			return numEnemies;
		}
*/
		int addMember(Character *member);
		int removeMember(unsigned int position);
		int swapMembers(unsigned int pos1, unsigned int pos2);
/*
		int addEnemy(Enemy *enemy);
		int removeEnemy(unsigned int position);
*/
		//TODO Add more functions? 
	private:
		int numMembers;
//		int numEnemies;
};

#endif
