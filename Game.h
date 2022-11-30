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
        void printCookware(User); // prints the number of each type of cookware, to be used in printStatus
        void printWeapons(User); // prints the number of each type of weapon, to be used in printStatus
        void printTreasures(User); // prints the number of each type of treasure, to be used in printStatus
        void printStatus(User); // prints the status update
        void printInventory(User); // prints the current inventory of the user
<<<<<<< Updated upstream
=======
        void move(char); // handles the movement of the party
        void printNPCmenu(); // prints NPC space action menu
>>>>>>> Stashed changes
        void investigate(); // handles the investigation of a space
        int split(string, char, string, int);
        // void fight(Monster); // handles picking a fight
        void cookAndEat(Item, double); // handles cooking and eating ingredients
        void giveUp(); // handles giving up
};

#endif
