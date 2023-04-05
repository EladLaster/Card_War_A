#ifndef GAME
#define GAME

#include <iostream>
#include "player.hpp"
#include "card.hpp"

using namespace std;
namespace ariel{

class Game{

public:
	Player pla1,pla2;

	Game();
    Game (Player &pla1,Player &pla2);
    void playTurn();
	void printLastTurn();
	void playAll();
	void printWiner();
	void printLog();
	void printStats();
};
}

#endif