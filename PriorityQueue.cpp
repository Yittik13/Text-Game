#include <stdio.h>

#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue(Party *playerParty, class enemyParty *enemyParty) {
	int i;
/*
	Action nullAction;
	nullAction.speed = -1;
	nullAction.type = -1;
	nullAction.unit = -1;
	nullAction.target = -1;
	nullAction.executed = true;
*/
	this -> playerParty = playerParty;
	this -> enemyParty = enemyParty;
	
	//num_actions = 10; /* DO NOT KEEP */
	
	for (i = 0; i < MAX_ACTIONS; i++) {
		queue[i] = nullAction;
	}
}


int PriorityQueue::reset() {
	int i;
/*
	Action nullAction;
	nullAction.speed = -1;
	nullAction.type = -1;
	nullAction.unit = -1;
	nullAction.target = -1;
	nullAction.executed = true;
*/
	this -> num_actions = 0;
	for (i = 0; i < MAX_ACTIONS; i++) {
		queue[i] = nullAction;
	}
	return 0;
}


int PriorityQueue::enqueue(action action) {
	if (this -> num_actions < MAX_ACTIONS) {
		//printf("ACTION QUEUED\n");
		//printf("Speed: %d, Type: %d, Target: %d\n", action.speed, action.type, action.target);
		this -> queue[num_actions] = action;
		num_actions++;
		return 0;
	}

	else {
		return -1;
	}
}

void PriorityQueue::print() {
	int i;
	printf("\nPRIORITY QUEUE INFORMATION\n");
	printf("Number of actions queued: %d\n", this -> num_actions);
	for (i = 0; i < this -> num_actions; i++) {
		printf("Action %d: Speed: %d, Type: %d, Unit: %d, Target: %d, Executed: %d\n", i,  queue[i].speed, queue[i].type, queue[i].unit, queue[i].target, queue[i].executed);
	}
}

int PriorityQueue::execute() {
	if (num_actions > 0) {
		int i;
		int position;
		int highestSpeed;
		int num_executed = 0;

		while (num_executed < num_actions) {
			i = 0;
			position = 0;
			highestSpeed = 0;
			while (i < num_actions) {
				if (highestSpeed <= this -> queue[i].speed && !(this -> queue[i].executed)) {
					highestSpeed = this -> queue[i].speed;
					position = i;
				}
				i++;
			}
				
			switch(this -> queue[position].type) {
			
			case NULL_ACTION:
				this -> queue[position].executed = true;
				num_executed++;
				break;

			case PLAYER_ATTACK_ACTION: /* Player Attack Case */
				//printf("\nATTACK CASE\n");
				//printf("Action at position %d executed\n", position);
				this -> playerParty -> members[queue[position].unit] -> attack(enemyParty -> enemies[queue[position].target] -> health);
				this -> queue[position].executed = true;
				num_executed++;
				break;

			case ENEMY_ATTACK_ACTION: /* Enemy Attack Case */
				//printf("Action at position %d executed\n", position);
				this -> enemyParty -> enemies[queue[position].unit] -> attack(playerParty -> members[queue[position].target] -> health);
				this -> queue[position].executed = true;
				num_executed++;
				break;
			
			default:
				//printf("\nWE SHOULD NOT PRINT THIS\n");
				break;
			}
		}

		return 0;
	}

	else {
		return -1;
	}
}


