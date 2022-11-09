#include <string>
#include "User.h"

using namespace std;

User::User() {
    name_ = ""; // name of player
    rooms_cleared_ = 0; // number of rooms that have been cleared
}

User::User(string name) {
    name_ = name;
    rooms_cleared_ = 0;
}