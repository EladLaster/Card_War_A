#include <stdexcept>
#include <iostream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Testing that the game was built successfully"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);

    CHECK(newgame.pla1.name=="elad");
    CHECK(newgame.pla2.name=="david");
}

TEST_CASE("start-test amount of card"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);

    CHECK(a.cardesTaken()==0);
    CHECK(b.cardesTaken()==0);
    CHECK(a.stacksize()==26);
    CHECK(b.stacksize()==26);
}

TEST_CASE("mid-test amount of card"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);

    CHECK_NOTHROW(newgame.playTurn());
    CHECK(a.cardesTaken()+a.stacksize()+b.cardesTaken()+b.stacksize()==52);
    CHECK(a.stacksize()<26);
    CHECK(b.stacksize()<26);
    CHECK(a.stacksize()==b.stacksize());

}

TEST_CASE("end-test amount of card"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);
    newgame.playAll();

    CHECK(a.cardesTaken()+b.cardesTaken()==52);
    CHECK(a.stacksize()==0);
    CHECK(b.stacksize()==0);
}

TEST_CASE("testing game functions"){ 
    Player a("elad");
    Player b("david");
    Game newgame(a,b);

    CHECK_NOTHROW(newgame.playAll());
    CHECK_NOTHROW(newgame.printLastTurn());
    CHECK_NOTHROW(newgame.printWiner());
    CHECK_NOTHROW(newgame.printLog());
    CHECK_NOTHROW(newgame.printStats());
}

TEST_CASE("testing errors before game beginning"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);

    CHECK_THROWS(newgame.printLastTurn());
    CHECK_THROWS(newgame.printWiner());
}

TEST_CASE("testing errors after game ending"){
    Player a("elad");
    Player b("david");
    Game newgame(a,b);
    newgame.playAll();

    CHECK_THROWS(newgame.playTurn());
    CHECK_THROWS(newgame.playAll());
}
