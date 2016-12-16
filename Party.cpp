#include "Party.hpp"

Party::Party() {
	this -> numMembers = 0;
	//this -> numEnemies = 0;
}

/*
 * Add a member to the party
 *
 * Parameters: member: The member to be added
 *
 * Return: 0 if successful, -1 if unsuccessful 
 */
int Party::addMember(Character *member) {
	if (numMembers < MAX_PARTY_SIZE) {
		this -> members[numMembers] = member;
		this -> numMembers++;
		return 0;
	}
	else {
		printf("ERROR: Party full\n");
		return -1;
	}
}

/*
 * Remove a member from the party
 *
 * Parameter: The position of the member to remove
 *
 * Returns: 0 is successful -1 if unsuccessful
 */
int Party::removeMember(unsigned int position) {
	if (position >= this -> numMembers) {
		printf("ERROR: Incorrect Position\n");
		return -1;
	}
	else {
		int i;
		this -> members[position] = NULL;
		this -> numMembers--;
		for (i = position; i < numMembers; i++) {
			this -> members[i] = this -> members[i + 1];
		}
		return 0;
	}
}

/*
 * Swap two members in the party
 * 
 * Parameters: pos1: position of first member, pos2: position of second member
 * 
 * Return: 0 if Successful, -1 if unsuccessful
 */
int Party::swapMembers(unsigned int pos1, unsigned int pos2) {
	if (pos1 >= numMembers || pos2 >= numMembers) {
		printf("ERROR: Incorrect position\n");
		return -1;
	}
	else {
		Character *temp = this -> members[pos1];
		this -> members[pos1] = this -> members[pos2];
		this -> members[pos2] = temp;
		return 0;
	}
}
/*
   int Party::addEnemy(Enemy *enemy) {
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

   int Party::removeEnemy(unsigned int position) {
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
 */
