#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game {
    public:
        void move(char); // handles the movement of the party
        void investigate(); // handles the investigation of a space
        // void fight(Monster); // handles picking a fight
        void cookAndEat(Item, double); // handles cooking and eating ingredients
        void giveUp(); // handles giving up
};

#endif
