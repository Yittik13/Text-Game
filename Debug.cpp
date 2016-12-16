#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "Debug.hpp"

static const char *debug_types[] = {
    "Debugger off",		// OFF
    "Character Stats",		// DEBUG_TYPE_CHARACTER_STATS		0x0001
    "Enemy Stats",		// DEBUG_TYPE_ENEMY_STATS		0x0002
    "Character Damage",		// DEBUG_TYPE_CHARACTER_DAMAGE		0x0004
    "Enemy Damage",		// DEBUG_TYPE_ENEMY_DAMAGE		0x0008
    "Gamestate"			// DEBUG_TYPE_GAMESTATE			0x0010
};

Debug::Debug() {
	this -> debugTypes = DEBUG_TYPE_OFF;
}

/* debug
 * Parameters: Varrying amounts of debugging information to print
 * Returns: 0 if Successful -1 if Unsuccessful
 */
int Debug::debug(int type, const char *fmt, ...) {
	if (debugTypes & type) {
		va_list ap;
		va_start(ap,fmt);
		vprintf(fmt, ap);
		va_end(ap);
	}

	/*
	   if (debugLevel == 0) { //OFF
	   va_end(ap);
	   return 0;
	   }

	   else if (debugLevel == 1) { //CHARACTER STATS
//printf("\nSHOWING INFO FOR CHARACTER STATS\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 2) { //ENEMY STATS
//printf("\nSHOWING INFO FOR ENEMY STATS\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 3) { //CHARACTER AND ENEMY STATS
//printf("\nSHOWING INFO FOR CHARACTER AND ENEMY STATS\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 4) { //CHARACTER DAMAGE
//printf("\nSHOWING INFO FOR CHARACTER DAMAGE\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 5) { //ENEMY DAMAGE
//printf("\nSHOWING INFO FOR ENEMY DAMAGE\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 6) { //CHARACTER AND ENEMY DAMAGE
//printf("\nSHOWING INFO FOR CHARACTER AND ENEMY DAMAGE\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else if (debugLevel == 7) { //GAMESTATE
//printf("\nSHOWING INFO FOR CURRENT GAMESTATE\n");
vprintf(fmt, ap);
va_end(ap);
return 0;
}

else {
printf("\nINCORRECT LEVEL\n");
return -1;
}
	 */
//va_start(ap, fmt);
//vprintf(fmt, ap);
//va_end(ap);
	return 0;
}

void Debug::setDebugTypes(unsigned int types) {
	if (types & ~DEBUG_TYPE_MASK) {
		printf("Incorrect type specified 0x%x\n", types);
		return;
	}
	printf("\nDebugger set to types: 0x%04x (", types);

	bool first = true;
	for (int i = 0; i < N_DEBUG_TYPES; i++) {
		if (types & (1 << i)) {
			if (i > 0 && !first)
				printf(", ");
			printf("%s", debug_types[i + 1]);
			first = false;
		}
	}
	printf(")\n");
	debugTypes = types;
}

unsigned int Debug::getDebugTypes() {
	return debugTypes;
}

