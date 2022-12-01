#include "NPC.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

NPC::NPC()
{

}

void NPC::printNPCinteraction(Game game, User user, Map map)
{
    string input;
    cout << "Your party has encountered an NPC!\n" << endl;
    cout << "Please choose one of the following: \n";
    cout << "  1. Move \n";
    cout << "  2. Speak to NPC \n";
    cout << "  3. Give up \n";

    cin >> input;

    switch (stoi(input))
    {
        /*case 1: 
        {

        }*/

        case 2: 
        {
            string line;
            vector<string> riddleVect;
            ifstream riddles("riddles.txt");
            int arr_size = 2;
            string arr[arr_size];

            cout << "The NPC is willing to offer you help, but you must solve this riddle first:" << endl;

            while (getline(riddles, line))
            {
                riddleVect.push_back(line);
            }

            int size = riddleVect.size();
            int random = rand() % size - 1;
            string riddle = riddleVect[random];
            if (game.split(riddle, '~', arr, 2) == 2)
            {
                cout << arr[0] << endl;
                cin >> input;

                if (input == arr[1])
                {
                    Merchant NPC(user);
                    NPC.printInteraction(game, user);
                }
                else
                {

                }
            }
            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());

            break;
        }
    }
}