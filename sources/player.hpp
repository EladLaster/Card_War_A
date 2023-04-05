#ifndef PLAYER
#define PLAYER

#include <iostream>

using namespace std;
namespace ariel {

class Player{

public:
    string name;

    Player ();
    Player (string name);
    int stacksize(); 
    int cardesTaken();
};
}

#endif