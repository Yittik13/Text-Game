#ifndef DEBUG_H
#define DEBUG_H

#include <stdarg.h>

#define	DEBUG_TYPE_OFF				0x0000
#define	DEBUG_TYPE_CHARACTER_STATS		0x0001
#define	DEBUG_TYPE_ENEMY_STATS			0x0002
#define	DEBUG_TYPE_CHARACTER_DAMAGE		0x0004
#define	DEBUG_TYPE_ENEMY_DAMAGE			0x0008
#define	DEBUG_TYPE_GAMESTATE			0x0010
#define DEBUG_TYPE_MASK				0x001f
#define	N_DEBUG_TYPES				6

class Debug {
public:
    Debug();

    int debug(int type, const char *fmt, ...);
    void setDebugTypes(unsigned int type);
    unsigned int getDebugTypes();
    
private:
    /* DEBUG LEVELS
     * 0 - Off
     * 1 - Character Stats
     * 2 - Enemy Stats
     * 3 - Character and Enemy Stats
     * 4 - Character Damage
     * 5 - Enemy Damage
     * 6 - Character and Enemy Damage
     * 7 - Gamestate
     *
     */
    unsigned int debugTypes;
};

#endif
