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


void NPC::printNPCinteraction(User user, Map map)
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
            if (split(riddle, '~', arr, 2) == 2)
            {
                cout << arr[0] << endl;
                cin >> input;

                if (arr[1] == input)
                {
                    Merchant NPC(user);
                    NPC.printInteraction(user);
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            map.removeNPC(map.getPlayerRow(), map.getPlayerCol());

            break;
        }
    }
}