#include <string>
#include "NPC.h"
#include "User.h"

using namespace std;

User::User() {
    name_ = ""; // name of player
    rooms_cleared_ = 0; // number of rooms that have been cleared
    armor_ = 0;
    keys_ = 0;
    fullness_ = 50;
    gold_ = 100;
    ingredients_ = 0;
    anger_level_ = 0;
}

User::User(string name) {
    name_ = name;
    rooms_cleared_ = 0;
    armor_ = 0;
    keys_ = 0;
    fullness_ = 50;
    gold_ = 100;
    ingredients_ = 0;
    anger_level_ = 0;
}

string User::getName() {
    return name_;
}

int User::getIngredients() {
    return ingredients_;
}

bool User::getGameOver() {
    return game_over_;
}

vector<Weapon> User::getWeapons() {
    return weapons_;
}

int User::getArmor() {
    return armor_;
}

vector<Item> User::getCookware() {
    return cookware_;
}

vector<Companion> User::getCompanions() {
    return companions_;
}

vector<Item> User::getSellingTreasures() {
    return selling_treasures_;
}

int User::getRoomsCleared() {
    return rooms_cleared_;
}

int User::getNumKeys() {
    return keys_;
}

int User::getFullness() {
    return fullness_;
}

int User::getAngerLevel() {
    return anger_level_;
}

int User::getGold() {
    return gold_;
}

vector<Weapon> User::addWeapon(Weapon weapon) { // add weapon to weapons vector
    weapons_.push_back(weapon);
    return weapons_;
}

int User::setArmor(int armor_num) { // changes armor value of party
    armor_ = armor_num;
    return armor_;
}

bool User::setGameOver(bool status) {
    game_over_ = status;
    return game_over_;
}

vector<Item> User::addCookware(Item cookware) { // add cookware to cookware vector
    cookware_.push_back(cookware);
    return cookware_;
}

vector<Companion> User::addCompanion(Companion companion) { // add cookware to cookware vector
    companions_.push_back(companion);
    return companions_;
}

vector<Item> User::addTreasure() { // add treasure to treasures vector
    Item treasure;
    treasure.setAmount(1);

    if(rooms_cleared_ == 1) {
        treasure.setCost(10);
        treasure.setName("R");
    }
    else if(rooms_cleared_ == 2) {
        treasure.setCost(20);
        treasure.setName("N");
    }
    else if(rooms_cleared_ == 3) {
        treasure.setCost(30);
        treasure.setName("B");
    }
    else if(rooms_cleared_ == 4) {
        treasure.setCost(40);
        treasure.setName("C");
    }
    else if(rooms_cleared_ == 5) {
        treasure.setCost(50);
        treasure.setName("G");
    }

    selling_treasures_.push_back(treasure);
    return selling_treasures_;
}

vector<Item> User::removeTreasure(int index) { // add treasure to treasures vector
    selling_treasures_.erase(selling_treasures_.begin() + index);
    return selling_treasures_;
}

int User::addKey() { // adds a key to key count and returns the new number of keys
    keys_++;
    return keys_;
}

int User::removeKey()
{
    keys_--;
    return keys_;
}

int User::increaseRoomsCleared() { // increases the number of rooms cleared
    if(rooms_cleared_ >= 5)
        return -1;

    rooms_cleared_++;
    return rooms_cleared_;
}

int User::setFullness(int lost_fullness) {
    fullness_ -= lost_fullness;
    return fullness_;
}

void User::changePartyFullness(int fullness) { // removes or adds an equal amount of fullness from each party member
    fullness_ += fullness;
    for(int i = 0; i < companions_.size(); i++) {
        companions_.at(i).setFullness(fullness);
    }
}

int User::setAngerLevel(int level) {
    anger_level_ = level;
    return anger_level_;
}

int User::setGold(int gold) {
    gold_ = gold;
    return gold_;
}

int User::setIngredients(int ingredients) {
    ingredients_ = ingredients;
    return ingredients;
}

void User::misfortune(bool is_room) { // runs through the chance of getting a misfortune and then what happens if one does occur
    int rand_num = 1 + rand() % 100;

    if(rand_num <= 40) { // runs if misfortune happens
        int rand_num = 1 + rand() % 100;

        if(rand_num <= 30) { // chance that party is robbed
            cout << "OH NO! You were just robbed by rats!!" << endl;
            int chance = 1 + rand() % 100;
            if(chance <= 33 && cookware_.size() > 0) {
                cout << "You lost 1 " << cookware_.at(cookware_.size() - 1).getName() << "!" << endl;
                cookware_.pop_back();
                return;
            }
            else if(chance <= 66 && armor_ > 0) {
                cout << "You lost 1 piece of armor." << endl;
                armor_--;
                return;
            }
            else {
                cout << "You lost up to 10 ingredients." << endl;
                if(ingredients_ >= 10) {
                    ingredients_ -= 10;
                }
                else {
                    ingredients_ = 0;
                }
            }
        }
        else if(rand_num > 30 && rand_num <= 40) {
            int chance = 1 + rand() % 100;
            if(chance <= 50 && armor_ > 0) { // armor broke
                cout << "OH NO! You lost a set of armor." << endl;
                armor_--;
            }
            else { // weapon broke
                int index = rand() % (weapons_.size() - 1);
                cout << "OH NO! Your " << weapons_.at(index).getName() << " broke." << endl;
                weapons_.erase(weapons_.begin() + index);
            }
        }
        else if(rand_num > 40 && rand_num <= 70) { // food poisoning
            int rand_character = 1 + rand() % (companions_.size() - 1);
            if(rand_character == 1) {
                fullness_ -= 10;
                cout << "OH NO! You lost 10 fullness by misfortune." << endl;
                if(fullness_ <= 0) {
                    setGameOver(true);
                    cout << "You starved. GAME OVER." << endl;
                    return;
                }
            }
            else {
                rand_character--;
                companions_.at(rand_character).setFullness(10);
                cout << "OH NO! " << companions_.at(rand_character).getName() << " lost 10 fullness." << endl;

                if(companions_.at(rand_character).getFullness() <= 0) {
                    cout << "Uh oh, it appears as if " << companions_.at(rand_character).getName() << " starved." << endl;
                    companions_.erase(companions_.begin() + rand_character);

                    if(companions_.size() == 0) {
                        cout << "It looks like all your companions peacefully passed away. GAME OVER." << endl;
                        setGameOver(true);
                        return;
                    }
                }
            }
        }
        if(rand_num > 70 && rand_num <= 100 && is_room) {
            int rand_character;
            if(companions_.size() > 1) {
                rand_character = rand() % (companions_.size() - 1);
            }
            else
                rand_character = 0;
            cout << "OH NO! Your companion " << companions_.at(rand_character).getName() << " is trapped in the previous room and " <<
                "is unable to get through. You must continue without them." << endl;
            companions_.erase(companions_.begin() + rand_character);
            cout << "Your party size has reduced to " << companions_.size() << endl;
            if(companions_.size() == 0) {
                cout << "It looks like all your companions peacefully passed away. GAME OVER." << endl;
                setGameOver(true);
                return;
            }
        }
    }
}

vector<string> User::loadMonsters() {
    string line;
    ifstream monsters("Monsters.txt");

    int arr_size = 2;
    string arr[arr_size];

    while (getline(monsters, line))
    {
        monsters_.push_back(line);
    }

    return monsters_;

    // int size = monsters_.size();
    // int random = rand() % size - 1;
}

void User::surrender(User &user) {
    int rand_character = rand() % (companions_.size() - 1);
    cout << "You surrendered and " << companions_.at(rand_character).getName() << " died to the monster." << endl;
    companions_.erase(companions_.begin() + rand_character);

    if(companions_.size() == 0) {
        cout << "You lost all your companions. GAME OVER." << endl;
        user.setGameOver(true);
    }
}

bool User::fightMonster(User &user) {
    int random = rand() % 3;

    string monster_line;
    bool flag = false;

    string split_arr[2];
    int arr_size = 2;

    NPC npc;

    if (user.getRoomsCleared() <= 4)
    {
        do
        { // makes sure the chosen monster has not already been defeated
            monster_line = monsters_.at((user.getRoomsCleared() * 4) + random);
            flag = true;
            for(int i = 0; i < defeated_monsters_.size(); i++) {
                if(monster_line == defeated_monsters_.at(i))
                    flag = false;
            }
        } while(!flag);
    }
    else
    {
        monster_line = monsters_.at(monsters_.size() - 1);
    }
     
    

    npc.split(monster_line, ',', split_arr, arr_size);

    cout << split_arr[0] << " ahead, get ready for a fight!" << endl;

    flag = false;
    if(user.getWeapons().size() > 0) {
        while(!flag) {
            flag = true;
            cout << "\nPlease choose one of the following: " <<
                "\n  1. Fight the monster." <<
                "\n  2. Surrender and lose 1 companion." << endl;

            string input;
            cin >> input;

            switch(stoi(input)) {
                case 1: // fight
                {   
                    int w = 0;
                    if (user.getWeapons().size() >= companions_.size())
                    {
                        w += companions_.size();
                        for (int i = 0; i < companions_.size(); i++)
                        {
                            w += user.getWeapons().at(user.getWeapons().size() - i - 1).getDamage();
                        }
                    }
                    else
                    {
                        w += user.getWeapons().size();
                        for (int i = 0; i < user.getWeapons().size(); i++)
                        {
                            w += user.getWeapons().at(i).getDamage();
                        }
                    }
                    int d = 4;
                    for (int i = 0; i < user.getWeapons().size(); i++)
                    {
                        for (int j = 0; j < user.getWeapons().size(); j++)
                        {
                            if (j != i)
                            {
                                if (user.getWeapons().at(i).getName() == user.getWeapons().at(j).getName())
                                {
                                    d = 0;
                                    break;
                                }
                            }
                        }
                    }

                    int a = user.getArmor();
                    int c = stoi(split_arr[1]);
                    int r1 = 1 + rand() % 6;
                    int r2 = 1 + rand() % 6;
                    double result;

                    if (a > 0)
                        result = (r1 * w + d) - ((r2 * c) / a);
                    else if (a == 0)
                        result = (r1 * w + d) - (r2 * c);

                    if(result > 0) {
                        defeated_monsters_.push_back(monster_line);
                        cout << "YOU DEFEATED THE MONSTER! You gained " << (10 * c) << " gold and " << (5 * c) << " ingredients from the monster." << endl;
                        user.setGold(user.getGold() + 10 * c);
                        user.setIngredients(user.getIngredients() + 5 * c);
                        int rand_num = 1 + rand() % 100;
                        if(rand_num <= 10) {
                            user.addKey();
                            cout << "The monster also dropped a key!" << endl;
                        }

                        user.increaseRoomsCleared();
                        return true;
                    }
                    else {
                        cout << "The monster defeated your party. You lose " << (user.getGold() * 0.25) << " gold and up to 30 ingredients." << endl;
                        user.setGold(user.getGold() - user.getGold() * 0.25);
                        if(user.getIngredients() > 30) {
                            user.setIngredients(user.getIngredients() - 30);
                        }
                        else {
                            user.setIngredients(0);
                        }
                        int rand_num;
                        for(int i = 0; i < companions_.size(); i++) {
                            rand_num = 1 + rand() % 100;
                            if(i + 1 > user.getArmor()) {
                                if(rand_num <= 10) {
                                    cout << companions_.at(i).getName() << " was slain." << endl;
                                    companions_.erase(companions_.begin() + i);
                                }
                            }
                            else if(rand_num <= 5) {
                                cout << companions_.at(i).getName() << " was slain." << endl;
                                companions_.erase(companions_.begin() + i);
                            }
                        }
                    }
                    break;
                }

                case 2:
                {
                    surrender(user);
                    break;
                }

                default:
                    cout << "Enter a valid input." << endl;
                    flag = false;
                    break;
            }
        }
    }
    else {
        cout << "You have no weapons, you are forced to surrender." << endl;
        surrender(user);
    }
    return false;
}

void User::runPlayerAction(Map &map, User &user) {
    srand((unsigned) time(NULL));
    int rand_num;

    string input;
    cout << "\nPlease choose one of the following: " <<
            "\n  1. Move a single space in any direction, 20% chance fullness of any party member drops by 1." <<
            "\n  2. Investigate, explore an unexplored space. 50% chance fullness of any party member drops by 1. " << 
                "[10% chance you find a key, 20% chance you find treasure, or 20% chance you must fight a random monster]" <<
            "\n  3. Pick a fight and cause a random monster to appear. Defeating a monster has a" <<
                " 10% chance of dropping a key." <<
            "\n  4. Cook and eat using current ingredients and cookware." <<
            "\n  5. Give up and end the game." << endl;
    cin >> input;

    switch(stoi(input)) {
        case 1:
        {
            char direction;
            cout << "Enter a direction you would like to move [w for up, s for down," <<
                " a for left, and d for right]" << endl;
            cin >> direction;
            map.move(direction);

            rand_num = 1 + rand() % 100;
            if(rand_num <= 20) {
                fullness_--;
                cout << "You lost 1 fullness from moving." << endl;
            }
            for(int i = 0; i < companions_.size(); i++) {
                rand_num = 1 + rand() % 100;
                if(rand_num <= 20) {
                    companions_.at(i).setFullness(1);
                    cout << companions_.at(i).getName() << " lost 1 fullness from moving." << endl;
                }
            }
            if (!map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
                anger_level_++;
            if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
            {   
                NPC npc;
                npc.printNPCinteraction(user, map);
            }
            if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
            {
                user.printRoomInteraction(user, map);
            }
            
            break;
        }

        case 2:
        {
            if(!map.isExplored(map.getPlayerRow(), map.getPlayerCol()) && !map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) {
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                rand_num = 1 + rand() % 100;
                if(rand_num <= 10) {
                    cout << "You found a key!" << endl;
                    addKey();
                }
                else if(rand_num > 10 && rand_num <= 30 && rooms_cleared_ > 0) {
                    cout << "You found treasure! It's worth " << rooms_cleared_ * 10 << " Gold!" << endl;
                    addTreasure();
                }
                else if(rand_num > 30 && rand_num <= 50) {
                    cout << "You found a monster! Get ready for a fight." << endl;
                    fightMonster(user);
                }
                else
                    cout << "You found nothing." << endl;
            }
            else
                cout << "This space is already explored, choose another action." << endl;

            rand_num = 1 + rand() % 100;
            if(rand_num <= 50) {
                fullness_--;
                cout << "You lost 1 fullness from investigating." << endl;
            }
            for(int i = 0; i < companions_.size(); i++) {
                rand_num = 1 + rand() % 100;
                if(rand_num <= 50) {
                    companions_.at(i).setFullness(1);
                    cout << companions_.at(i).getName() << " lost 1 fullness from investigating." << endl;
                }
            }
            
            misfortune(false);
            break;
        }

        case 3:
        {
            cout << "You're getting cocky!" << endl;
            fightMonster(user);
            misfortune(false);
            break;
        }

        case 4:
        {   
            bool flag = false;
            int index;
            
            while(!flag) {
                flag = true;

                string amount_input;
                char cook_input;
                cout << "Choose which piece of cookware you would like to use from your selection below. Please enter the capital letter of the cookware\n| ";
                for(int i = 0; i < cookware_.size(); i++) {
                    cout << cookware_.at(i).getName() << ", chance of breaking: " << cookware_.at(i).getChance() * 100 << "% | ";
                }
                cout << endl;
                cin >> cook_input;

                for(int i = 0; i < cookware_.size(); i++) {
                    char cook_symbol = cookware_.at(i).getName()[cookware_.at(i).getName().length() - 2];
                    if(cook_symbol == cook_input  && cook_input == 'P') {
                        index = i;
                        i = cookware_.size();
                    }
                    else if(cook_symbol == cook_input && cook_input == 'F') {
                        index = i;
                        i = cookware_.size();
                    }
                    else if(cook_symbol == cook_input && cook_input == 'C') {
                        index = i;
                        i = cookware_.size();
                    }
                    else {
                        cout << "Invalid input, please select a valid piece of cookware from the list above." << endl;
                        flag = false;
                    }
                }

                cout << "For every 5 ingredients used, each party member gains 1 fullness.\nHow many ingredients would you like to use?" << endl;
                cin >> amount_input;
                
                rand_num = 1 + rand() % 100;
                if(rand_num <= cookware_.at(index).getChance() * 100) {
                    cout << "The cookware broke! You lost " << (stoi(amount_input) - (stoi(amount_input) % 5)) << " ingredients and the cookware." << endl;
                    ingredients_ -= stoi(amount_input) - (stoi(amount_input) % 5);
                    cookware_.erase(cookware_.begin() + index);
                }
                else {
                    cout << "You cooked a meal successfully! Each member in your party gained " << (stoi(amount_input) / 5) << " fullness" << 
                        " from " << stoi(amount_input) - (stoi(amount_input) % 5) << " ingredients." << endl;
                    ingredients_ -= stoi(amount_input) - (stoi(amount_input) % 5);
                    fullness_ += (stoi(amount_input) / 5);
                    for(int j = 0; j < companions_.size(); j++) {
                        companions_.at(j).setFullness(-(stoi(amount_input) / 5));
                    }
                    cout << "We made it here" << endl;
                    cout << "| " << name_ << " | Fullness: " << fullness_ << endl;
                    for(int j = 0; j < companions_.size(); j++) {
                        Companion compy = companions_.at(j);
                        cout << "| " << compy.getName() << " | Fullness: " << compy.getFullness() << endl;
                    }
                    cout << "| Ingredients remaining: " << ingredients_ << endl;
                }
            }

            misfortune(false);
            break;
        }

        case 5:
        {
            cout << "Are you sure you want to give up? This will end the game. [y/n]" << endl;

            string YorN;
            cin >> YorN;

            if(YorN == "y") {
                cout << "Alright :(, it was a good game while it lasted..." << endl;
                user.setGameOver(true);
            }

            misfortune(false);
            break;
        }
    }
}

void User::printRoomInteraction(User &user, Map &map)
{
    string input;
    int rand_num;
    cout << "Your party has encountered a Room!\n" << endl;
    cout << "Please choose one of the following: \n";
    cout << "  1. Move \n";
    cout << "  2. Open the Door \n";
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
                fullness_--;
                cout << "You lost 1 fullness from moving." << endl;
            }
            for(int i = 0; i < 4; i++) {
                rand_num = 1 + rand() % 100;
                if(rand_num <= 20) {
                    companions_.at(i).setFullness(1);
                    cout << companions_.at(i).getName() << " lost 1 fullness from moving." << endl;
                }
            }
            if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
            {
                NPC npc;
                npc.printNPCinteraction(user, map);
            }
            break;
        }

        case 2: 
        {
            int doorChoice;
            if (user.getNumKeys() > 0)
            {
                user.removeKey();
                if(user.fightMonster(user)) {
                    map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                }
            }
            else if (user.getNumKeys() == 0)
            {
                int counter = 0;

                cout << "Uh oh! It seems like your party doesn't possess the key. \n";
                cout << "However, if you beat the Door in Boulder/Parchment/Shears, it will kindly let you pass. \n";
                cout << "But beware - Doors like these often have ways of making people... disappear O_o" << endl;

                do
                {
                    cout << "Please choose one of the following:\n";
                    cout << "Boulder (1), Parchment (2), or Shears (3)\n";
                    cin >> input;
                    doorChoice = rand() % 3 + 1;

                    if (stoi(input) == 1)
                        cout << "Your choice: Boulder" << endl;
                    else if (stoi(input) == 2)
                        cout << "Your choice: Parchment" << endl;
                    else if (stoi(input) == 3)
                        cout << "Your choice: Shears" << endl;

                    if (doorChoice == 1)
                        cout << "Door's choice: Boulder" << endl;
                    else if (doorChoice == 2)
                        cout << "Door's choice: Parchment" << endl;
                    else if (doorChoice == 3)
                        cout << "Door's choice: Shears" << endl;

                    if ((stoi(input) == 1 && doorChoice == 2) || (stoi(input) == 2 && doorChoice == 3) || (stoi(input) == 3 && doorChoice == 1))
                    {
                        int index = rand() % companions_.size();
                        cout << "\"You have lost.\" The door says, opening its splinter-filled mouth. \"Now, I must take my prize.\" \n";
                        cout << "The Door lunges forward and gruesomely devours " << companions_.at(index).getName() << " right before your eyes!\n";
                        companions_.erase(companions_.begin() + index);

                        if(companions_.size() == 0) {
                            cout << "You lost all your companions. GAME OVER." << endl;
                            user.setGameOver(true);
                        }
                        else
                        {
                            cout << "Remaining companions: ";
                            for (int i = 0; i < companions_.size(); i++)
                            {
                                cout << companions_.at(i).getName() << " ";
                            }
                        }

                        cout << endl;

                        break;
                    }
                    else if ((stoi(input) == 1 && doorChoice == 3) || (stoi(input) == 2 && doorChoice == 1) || (stoi(input) == 3 && doorChoice == 2))
                    {
                        cout << "Congratulations on beating the Door! It swings open to reveal the room beyond.\n";
                        if(user.fightMonster(user)) {
                            map.removeRoom(map.getPlayerRow(), map.getPlayerCol());
                        }
                        break;
                    }

                    counter++;

                    if (counter == 3)
                    {
                        int index = rand() % companions_.size();
                        cout << "\"You have taken too much of my time.\" The door says, opening its splinter-filled mouth. \"Now, I must take my prize.\" \n";
                        cout << "The Door lunges forward and gruesomely devours " << companions_.at(index).getName() << " right before your eyes!\n";
                        companions_.erase(companions_.begin() + index);
                        
                        cout << "Remaining companions: ";
                        for (int i = 0; i < companions_.size(); i++)
                        {
                            cout << companions_.at(i).getName() << " ";
                        }

                        cout << endl;

                        break;
                    }
                }
                while (stoi(input) == doorChoice);
            }

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

        default:
        {
            cout << "Enter a valid input." << endl;
            break;
        }
    }
}

void User::printDashedLine() { // prints dashed line: +-------------+
    cout << "+-------------+" << endl;
}

void User::printCookware() { // prints the number of each type of cookware i.e.: P: 1 | F: 0 | C: 2
    int ceramic_pots = 0;
    int pans = 0;
    int cauldrons = 0; 

    for(int i = 0; i < cookware_.size(); i++) {
        if(cookware_.at(i).getName()[cookware_.at(i).getName().length() - 2] == 'P')
            ceramic_pots++;
        else if(cookware_.at(i).getName()[cookware_.at(i).getName().length() - 2] == 'F')
            pans++;
        else if(cookware_.at(i).getName()[cookware_.at(i).getName().length() - 2] == 'F')
            cauldrons++;
    }

    cout << "P: " << ceramic_pots << " | F: " << pans << " | C: " << cauldrons << endl; 
}

void User::printWeapons() { // prints the number of each type of weapon i.e.: C: 1 | S: 2 | R: 1 | B: 0 | L: 1
    int clubs = 0;
    int spears = 0;
    int rapiers = 0;
    int battle_axe = 0;
    int longsword = 0; 

    for(int i = 0; i < weapons_.size(); i++) {
        if(weapons_.at(i).getName()[weapons_.at(i).getName().length() - 2] == 'C')
            clubs++;
        else if(weapons_.at(i).getName()[weapons_.at(i).getName().length() - 2] == 'S')
            spears++;
        else if(weapons_.at(i).getName()[weapons_.at(i).getName().length() - 2] == 'R')
            rapiers++;
        else if(weapons_.at(i).getName()[weapons_.at(i).getName().length() - 2] == 'B')
            battle_axe++;
        else if(weapons_.at(i).getName()[weapons_.at(i).getName().length() - 2] == 'L')
            longsword++;
    }

    cout << "C: " << clubs << " | S: " << spears << " | R: " << rapiers << " | B: " << battle_axe << " | L: " << longsword << endl; 
}

void User::printTreasures() { // prints the number of each type of treasure i.e.: R: 1 | N: 0 | B: 0 | C: 0 | G: 0
    int ring = 0;
    int necklace = 0;
    int bracelet = 0;
    int circlet = 0;
    int goblet = 0;

    for(int i = 0; i < selling_treasures_.size(); i++) {
        if(selling_treasures_.at(i).getName()[selling_treasures_.at(i).getName().length() - 2] == 'R')
            ring++;
        else if(selling_treasures_.at(i).getName()[selling_treasures_.at(i).getName().length() - 2] == 'N')
            necklace++;
        else if(selling_treasures_.at(i).getName()[selling_treasures_.at(i).getName().length() - 2] == 'B')
            bracelet++;
        else if(selling_treasures_.at(i).getName()[selling_treasures_.at(i).getName().length() - 2] == 'C')
            circlet++;
        else if(selling_treasures_.at(i).getName()[selling_treasures_.at(i).getName().length() - 2] == 'G')
            goblet++;
    }

    cout << "R: " << ring << " | N: " << necklace << " | B: " << bracelet << " | C: " << circlet << " | G: " << goblet << endl; 
}

void User::printStatus() { // prints status update
    printDashedLine();
    cout << "| STATUS      |" << endl;
    printDashedLine();
    cout << "| Rooms Cleared: " << rooms_cleared_ << " | Keys: " << keys_ << " | Anger Level: " << anger_level_ << endl;
    printDashedLine();
    cout << "| INVENTORY   |" << endl;
    printDashedLine();
    cout << "| Gold        | " << gold_ << endl;
    cout << "| Ingredients | " << ingredients_ << endl;
    cout << "| Cookware    | ";
    printCookware();
    cout << "| Weapons     | ";
    printWeapons();
    cout << "| Armor       | " << armor_ << endl;
    cout << "| Treasures   | ";
    printTreasures();
    printDashedLine();
    cout << "| PARTY       |" << endl;
    printDashedLine();
    
    cout << "| " << name_ << " | Fullness: " << fullness_ << endl;
    for(int i = 0; i < companions_.size(); i++) {
        Companion compy = companions_.at(i);
        cout << "| " << compy.getName() << " | Fullness: " << compy.getFullness() << endl;
    }

    printDashedLine();
}

void User::printInventory() { // prints status update
    printDashedLine();
    cout << "| INVENTORY   |" << endl;
    printDashedLine();
    cout << "| Gold        | " << gold_ << endl;
    cout << "| Ingredients | " << ingredients_ << endl;
    cout << "| Cookware    | ";
    printCookware();
    cout << "| Weapons     | ";
    printWeapons();
    cout << "| Armor       | " << armor_ << endl;
    cout << "| Treasures   | ";
    printTreasures();
}

/*
    1. Loop through vector
    2. Compare the damage of each weapon to the next weapon in the vector
    3. If the current Weapon has more damage, move on to next iteration of loop
    4. If the second Weapon has more damage, swap the two
    5. Continue iterating through for loop until the vector is in order
*/
void User::bubbleSortWeapons() 
{
    bool swap = true;

    while (swap)
    {
        swap = false;

        for (int j = 0; j < weapons_.size() - 1; j++)
        {
            if (weapons_[j].getDamage() < weapons_[j+1].getDamage())
            {
                Weapon temp = weapons_[j];
                weapons_[j] = weapons_[j+1];
                weapons_[j+1] = temp;
                swap = true;
            }
        }
    }

    for(int i = 0; i < weapons_.size(); i++) {
        cout << weapons_.at(i).getName() << endl;
    }
}
