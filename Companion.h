#ifndef COMPANION_H
#define COMPANION_H

#include <string>
#include <vector>

using namespace std;

class Companion {
    private:
        string name_;
        int fullness_;
        bool armor_;
        
    public:
        // constructors
        Companion();
        Companion(string);

        // getter functions
        string getName();
        int getAttack();
        int getFullness();

        // setter functions
        int setFullness(int);
};

#endif