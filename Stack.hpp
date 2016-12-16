#ifndef STACK_H
#define STACK_H

#include "Gamestate.hpp"

#define MAXSTACK 50

class Stack {
	public:
		void clear();
		Gamestate* pop();
		void push(Gamestate *gamestate);
		void print();
		Gamestate *peek();

	private:
		int top = 0;
		Gamestate *stack[MAXSTACK];
};

#endif
