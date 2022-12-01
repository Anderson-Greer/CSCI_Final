#include "Monster.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Monster::Monster()
{
    threat_level_ = 0;
    attack_ = 0;
    name_ = "";
}

Monster::Monster(int threat_level, int attack, string name)
{
    threat_level_ = threat_level;
    attack_ = attack;
    name_ = name;
}

int Monster::getThreat()
{
    return threat_level_;
}

int Monster::getAttack()
{
    return attack_;
}

string Monster::getName()
{
    return name_;
}

vector<string> Monster::loadMonsters() {
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

void Monster::surrender(User &user) {
    int rand_character = rand() % (user.getCompanions().size() - 1);
    cout << "You surrendered and " << user.getCompanions().at(rand_character).getName() << " died to the monster." << endl;
    user.getCompanions().erase(user.getCompanions().begin() + rand_character);

    if(user.getCompanions().size() == 0) {
        cout << "You lost all your companions. GAME OVER." << endl;
        user.setGameOver(true);
    }
}

void Monster::fightMonster(User user) {
    int random = rand() % 3;

    string monster_line;
    bool flag = false;

    string split_arr[2];
    int arr_size = 2;

    NPC npc;

    do { // makes sure the chosen monster has not already been defeated
        monster_line = monsters_.at(user.getRoomsCleared() * 4 + random);
        flag = true;
        for(int i = 0; i < defeated_monsters_.size(); i++) {
            if(monster_line == defeated_monsters_.at(i))
                flag = false;
        }
    } while(!flag);

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
                case 1: // user wants to buy ingredients
                {   
                    int w = user.getCompanions().size() + 1;
                    for(int i = 0; i < user.getCompanions().size(); i++) {
                        if(user.getWeapons().size() < i) {
                            w += user.getWeapons().at(i).getDamage();
                        }
                    }
                    int d;
                    int a = user.getArmor();
                    int c = stoi(split_arr[1]);
                    int r1 = 1 + rand() % 6;
                    int r2 = 1 + rand() % 6;

                    int result = (r1 * w + d) - ((r2 * c) / a);

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
                        for(int i = 0; i < user.getCompanions().size(); i++) {
                            rand_num = 1 + rand() % 100;
                            if(i + 1 > user.getArmor()) {
                                if(rand_num <= 10) {
                                    cout << user.getCompanions().at(i).getName() << " was slain." << endl;
                                    user.getCompanions().erase(user.getCompanions().begin() + i);
                                }
                            }
                            else if(rand_num <= 5) {
                                cout << user.getCompanions().at(i).getName() << " was slain." << endl;
                                user.getCompanions().erase(user.getCompanions().begin() + i);
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
}