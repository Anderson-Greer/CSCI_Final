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

        void printDashedLine(); // prints a dashed line to be used in printStatus
        void printCookware(User user); // prints the number of each type of cookware, to be used in printStatus
        void printWeapons(User user); // prints the number of each type of weapon, to be used in printStatus
        void printTreasures(User user); // prints the number of each type of treasure, to be used in printStatus
        void printStatus(User); // prints the status update
        void move(char); // handles the movement of the party
        void investigate(); // handles the investigation of a space
        // void fight(Monster); // handles picking a fight
        void cookAndEat(Item, double); // handles cooking and eating ingredients
        void giveUp(); // handles giving up
};

#endif
