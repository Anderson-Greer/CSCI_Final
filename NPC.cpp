#include "NPC.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

NPC::NPC()
{

}

// split function
int NPC::split(string input_string, char separator, string arr[], int arr_size)
{   
    int count = 0;          // declare variables used in for loop
    int place = 0;
    arr[0] = input_string;
    
    if (input_string.length() == 0)     // input validation
    {
        return 0;
    }

    for (int i = 0; i <= input_string.length(); i++)
    {
        if (input_string[i] == separator)       // checks if char == separator
        {
            arr[count] = input_string.substr(place, i - place);     // populates array with correct substring
            count++;            // increments array index
            place = i + 1;      // updates place value so next string starts at correct spot
            
            if (count >= arr_size)      // checks if array is at capacity
            {
                return -1;
            }
        }
    }
    arr[count] = input_string.substr(place, input_string.length() - place);     // populates last array spot
    
    return count + 1;
}


void NPC::printNPCinteraction(User &user, Map &map)
{
    string input;
    int rand_num;
    int fullness = user.getFullness();
    vector<Companion> companions = user.getCompanions();
    cout << "Your party has encountered an NPC!\n" << endl;
    cout << "Please choose one of the following: \n";
    cout << "  1. Move \n";
    cout << "  2. Speak to NPC \n";
    cout << "  3. Give up \n";

    cin >> input;

    switch (stoi(input))
    {
        case 1: 
        {
            char direction;
            cout << "Enter a direction you would like to move [w for up, s for down," <<
                " a for left, and d for right]" << endl;
            cin >> direction;
            map.move(direction);

            rand_num = 1 + rand() % 100;
            if(rand_num <= 20) {
                fullness--;
                cout << "You lost 1 fullness from moving." << endl;
            }
            for(int i = 0; i < 4; i++) {
                rand_num = 1 + rand() % 100;
                if(rand_num <= 20) {
                    companions.at(i).setFullness(companions.at(i).getFullness() - 1);
                    cout << companions.at(i).getName() << " lost 1 fullness from moving." << endl;
                }
            }
            if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
            {
                NPC npc;
                npc.printNPCinteraction(user, map);
            }
            
            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());
            break;
        }

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
            if (split(riddle, '~', arr, 2) == 2)
            {   
                cout << arr[0] << endl;
                cout << "Answer: " << arr[1] << endl;
                cin >> input;
                string answer = arr[1];
                // cout << "Input: " << answer << endl;
                // cout << "Equal: " << (input[0] == arr[1][0] && input[1] == arr[1][1]) << endl;
                
                bool flag = true;
                if(input.length() + 1 == arr[1].length()) {
                    cout << input.length() << ", " << arr[1].length() << endl;
                    for(int i = 0; i < input.length(); i++) {
                        if(input[i] != arr[1][i])
                            flag = false;
                    }
                }
                else {
                    flag = false;
                }

                if(flag) {
                    cout << "Good job! You figured it out. Is there anything you'd like to buy off me?" << endl;
                    Merchant NPC(user);
                    NPC.printInteraction(user);
                }
                else {
                    cout << "Wrong answer, buddy! Now you feel my wrath!" << endl;
                    user.fightMonster(user);
                }
            }
            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());

            break;
        }

        case 3:
        {
            cout << "Are you sure you want to give up? This will end the game. [y/n]" << endl;

            string YorN;
            cin >> YorN;

            if(YorN == "y") {
                cout << "Alright :(, it was a good game while it lasted..." << endl;
                user.setGameOver(true);
            }
            break;
        }
    }
}