#ifndef ACTION_H
#define ACTION_H

#define MAX_ACTIONS 10
#define NULL_ACTION -1
#define PLAYER_ATTACK_ACTION 1
#define ENEMY_ATTACK_ACTION 2


typedef struct action {
	int speed = 1; //acting unit's speed
	int type = NULL_ACTION; //the type of action
	int unit = NULL_ACTION; //the number of the unit performing the action
	int target = NULL_ACTION; //the target of the action
	bool executed = false; //if the action has been executed or not
} Action;

#endif
