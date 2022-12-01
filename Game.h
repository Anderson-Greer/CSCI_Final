#ifndef GAME_H
#define GAME_H

#include "User.h"
#include <string>

using namespace std;

class Game {
    private:
        bool game_over_;

    public:
        bool getGameOver();
        bool setGameOver(bool);

        int split(string, char, string[], int);
        // void fight(Monster); // handles picking a fight
        void giveUp(); // handles giving up
};

#endif
