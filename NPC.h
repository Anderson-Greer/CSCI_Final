#ifndef NPC_H
#define NPC_H

#include <string>

using namespace std;

class NPC
{
    public:
        NPC();

        int split(string, char, string[], int);
        void printNPCinteraction(User&, Map&);
};

#endif