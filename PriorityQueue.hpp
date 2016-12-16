#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Party.hpp"
#include "Enemy.hpp"
#include "Action.hpp"

class PriorityQueue {
	public:
		PriorityQueue(Party *playerParty, class enemyParty *enemyParty);

		int num_actions;

		action queue[MAX_ACTIONS];

		int enqueue(action action);
		void print();
		int execute();
		int reset();

		Party *playerParty;
		enemyParty *enemyParty;

		Action nullAction;	
};

#endif
