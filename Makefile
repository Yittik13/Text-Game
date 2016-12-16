
all: main

main: main.cpp Character.cpp Enemy.cpp Debug.cpp Stack.cpp Gamestate.cpp Battle.cpp Party.cpp PriorityQueue.cpp TestMenu.cpp
	g++ -std=c++11 -Wall -lncurses -o main main.cpp Character.cpp Enemy.cpp Debug.cpp Stack.cpp Gamestate.cpp Battle.cpp Party.cpp PriorityQueue.cpp TestMenu.cpp

