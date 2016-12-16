#include <stdio.h>
#include <stdlib.h>

#include "Stack.hpp"

void Stack::clear() {
    top = 0;
}

Gamestate* Stack::pop() {
    if (top != 0) {
	Gamestate *temp = stack[top];
	stack[top] = NULL;
	top--;
	return temp;
    }
    else {
	return NULL;
    }
}

void Stack::push(Gamestate *gamestate) {
    if (top != MAXSTACK - 1) {
	stack[top] = gamestate;
	top++;
    }
    else {
	return;
    }
}

void Stack::print() {
    int i;
    
    if (top == 0) {
	printf("Stack is empty\n");
	return;
    }
    else {
	for (i = 0; i < top; i++) {
	    printf("%d: %s\n", i, stack[i] -> getType());
	}
    }
}

Gamestate* Stack::peek() {
    return stack[top - 1];
}

