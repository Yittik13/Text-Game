#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdlib.h>
#include <stdio.h>

class Gamestate {
  public:

    bool running;
/*
    Gamestate(const char *type);

    void getInfo();
  */
	void setType(const char* type) {
		this -> type = type;
	}  
    const char *getType() {
	return type;
    }
/*
    bool isRunning() {
	return running;
    }

    int start();
    int stop();
*/
private:
	const char *type;
};

#endif
