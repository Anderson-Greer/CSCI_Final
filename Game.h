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

        void investigate(); // handles the investigation of a space
        // void fight(Monster); // handles picking a fight
        void cookAndEat(Item, double); // handles cooking and eating ingredients
        void giveUp(); // handles giving up
};

#endif
