#include "Merchant.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Merchant::Merchant(User user)
{
    price_multiplier_ = 1 + (0.25 * user.getRoomsCleared());
}

void Merchant::printInteraction(User &user) {
    string input;
    int price;
    bool end = false;
    
    cout << "If you're looking to get supplies, you've come to the right place." <<
        "\nI would be happy to part with some of my wares...for the proper price!\n" << endl;

    while(!end) {

        user.printInventory();

        cout << "\nPlease choose one of the following: " <<
            "\n  1. Ingredients: To make food, you have to cook raw ingredients." <<
            "\n  2. Cookware: You will need something to cook those ingredients." <<
            "\n  3. Weapons: It's dangerous to go alone, take this!" <<
            "\n  4. Armor: If you want to survive monster attacks, you will need some armor." <<
            "\n  5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." <<
            "\n  6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;

        cin >> input;

        switch(stoi(input)) {
            case 1: // user wants to buy ingredients
            {   
                string ing_input;
                cout << "How many kg of ingredients do you need [" << (1 * price_multiplier_) << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel):" << endl;
                cin >> ing_input;

                price = stoi(ing_input) * price_multiplier_;

                while(stoi(ing_input) % 5 != 0 || stoi(ing_input) < 0) {
                    cout << "Invalid input." << endl;
                    cout << "How many kg of ingredients do you need [" << (1 * price_multiplier_) << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel):" << endl;
                    cin >> ing_input;
                    price = stoi(ing_input) * price_multiplier_;
                }

                if(stoi(ing_input) == 0) {
                    cout << "You entered 0 to cancel." << endl;
                    break;
                }

                cout << "You want to buy " << ing_input << " kg of ingredients for " << price << " Gold? (y/n)" << endl;
                
                string YorN;
                cin >> YorN;

                if(YorN == "y") {
                    if(user.getGold() >= price) {
                        user.setGold(user.getGold() - price);
                        cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                        
                        user.setIngredients(user.getIngredients() + stoi(ing_input));

                        break;
                    }
                    else {
                        cout << "You could not afford " << ing_input << " kg of ingredients for " << price << " Gold." << 
                            "\nYou only have " << user.getGold() << " Gold. " << endl;
                        break;
                    }
                }
                break;
            }

            case 2: // user wants to buy cookware
            {
                string cookware_input;
                string cookware_count;
                bool break_loop = false;

                while(!break_loop) {
                    break_loop = true;

                    cout << "I have three different types of cookware, which one would you like to purchase?" << 
                        "\nEach one has a different probability of breaking after each use, marked with (XX%)." <<
                        "\n\nChoose one of the following:" <<
                        "\n  1. (25%) Ceramic Pot [" << (2 * price_multiplier_) << " Gold]" <<
                        "\n  2. (10%) Frying Pan [" << (10 * price_multiplier_) << " Gold]" <<
                        "\n  3. (2%) Cauldron [" << (20 * price_multiplier_) << " Gold]" <<
                           "\n  4. Cancel" << endl;

                    cin >> cookware_input;

                    switch(stoi(cookware_input)) { 
                        case 1: // user wants to buy ceramic pots
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> cookware_count;
                            while(stoi(cookware_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> cookware_count;
                            }
                            if(cookware_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(cookware_count) * 2) * price_multiplier_;

                            cout << "You want to buy " << cookware_count << " Ceramic Pot(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(cookware_count); i++) {
                                        Item cookware(0.25, 2, 1, "Ceramic Pot (P)"); // creates the ceramic pot item
                                        user.addCookware(cookware);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << cookware_count << " Ceramic Pot(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 2: // user wants to buy frying pans
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> cookware_count;
                            while(stoi(cookware_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> cookware_count;
                            }
                            if(cookware_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(cookware_count) * 10) * price_multiplier_;

                            cout << "You want to buy " << cookware_count << " Frying Pan(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(cookware_count); i++) {
                                        Item cookware(0.10, 10, 1, "Frying Pan (F)"); // creates the frying pan item
                                        user.addCookware(cookware);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << cookware_count << " Frying Pan(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 3: // user wants to buy cauldrons
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> cookware_count;
                            while(stoi(cookware_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> cookware_count;
                            }
                            if(cookware_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(cookware_count) * 20) * price_multiplier_;

                            cout << "You want to buy " << cookware_count << " Cauldron(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(cookware_count); i++) {
                                        Item cookware(0.02, 20, 1, "Cauldron (C)"); // creates the cauldron item
                                        user.addCookware(cookware);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << cookware_count << " Cauldron(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 4: // user cancelled
                        {
                            cout << "You decided to cancel the transaction.\n" << endl;
                            break;
                        }

                        default:
                        {
                            cout << "Invalid input, please make a valid choice." << endl;
                            break_loop = false;
                            break;
                        }
                    }
                }
                break;
            }
            
            case 3: // user wants to buy weapons
            {
                cout << "I have a plentiful collection of weapons to choose from, what would you like?" << 
                    "\nNote that some of them provide you a special bonus in combat, marked by a (+X)." << endl;

                string weap_input;
                string weap_count;
                bool break_loop = false;

                while(!break_loop) {
                    break_loop = true;

                    cout << "\nChoose one of the following:" <<
                        "\n  1. Stone Club [" << (2 * price_multiplier_) << " Gold]" <<
                        "\n  2. Iron Spear [" << (2 * price_multiplier_) << " Gold]" <<
                        "\n  3. (+1) Mythril Rapier [" << (5 * price_multiplier_) << " Gold]" <<
                        "\n  4. (+2) Flaming Battle-Axe [" << (15 * price_multiplier_) << " Gold]" <<
                        "\n  5. (+3) Vorpal Longsword [" << (50 * price_multiplier_) << " Gold]" <<
                        "\n  6. Cancel" << endl;

                    cin >> weap_input;

                    switch(stoi(weap_input)) {
                        case 1: // user wants to buy clubs
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> weap_count;
                            while(stoi(weap_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> weap_count;
                            }
                            if(weap_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(weap_count) * 2) * price_multiplier_;

                            cout << "You want to buy " << weap_count << " Stone Club(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(weap_count); i++) {
                                        Weapon weapon(2, 0, "Stone Club (C)");
                                        user.addWeapon(weapon);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << weap_count << " Stone Club(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 2: // user wants to buy spears
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> weap_count;
                            while(stoi(weap_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> weap_count;
                            }
                            if(weap_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(weap_count) * 2) * price_multiplier_;

                            cout << "You want to buy " << weap_count << " Iron Spear(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(weap_count); i++) {
                                        Weapon weapon(2, 0, "Iron Spear (S)");
                                        user.addWeapon(weapon);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << weap_count << " Iron Spear(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 3: // user wants to buy rapiers
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> weap_count;
                            while(stoi(weap_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> weap_count;
                            }
                            if(weap_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(weap_count) * 5) * price_multiplier_;

                            cout << "You want to buy " << weap_count << " Mythril Rapier(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(weap_count); i++) {
                                        Weapon weapon(5, 1, "Mythril Rapier (R)"); // creates the ceramic pot item
                                        user.addWeapon(weapon);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << weap_count << " Mythril Rapier(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 4: // user wants to buy battle-axe
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> weap_count;
                            while(stoi(weap_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> weap_count;
                            }
                            if(weap_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(weap_count) * 15) * price_multiplier_;

                            cout << "You want to buy " << weap_count << " Flaming Battle-Axe(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(weap_count); i++) {
                                        Weapon weapon(15, 2, "Flaming Battle-Axe (B)"); // creates the ceramic pot item
                                        user.addWeapon(weapon);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << weap_count << " Flaming Battle-Axe(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 5: // user wants to buy longsword
                        {
                            cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                            cin >> weap_count;
                            while(stoi(weap_count) < 0) {
                                cout << "Please enter a positive integer or 0 to cancel:" << endl;
                                cin >> weap_count;
                            }
                            if(weap_count == "0") {
                                cout << "You entered a 0 to cancel." << endl;
                                break;
                            }

                            price = (stoi(weap_count) * 50) * price_multiplier_;

                            cout << "You want to buy " << weap_count << " Vorpal Longsword(s) for " << price << " Gold? (y/n)" << endl;
                            string YorN;
                            cin >> YorN;

                            if(YorN == "y") {
                                if(user.getGold() >= price) {
                                    user.setGold(user.getGold() - price);
                                    cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                                    for(int i = 0; i < stoi(weap_count); i++) {
                                        Weapon weapon(50, 3, "Vorpal Longsword (L)"); // creates the ceramic pot item
                                        user.addWeapon(weapon);
                                    }
                                    break;
                                }
                                else {
                                    cout << "You could not afford " << weap_count << " Vorpal Longsword(s) for " << price << " Gold." << 
                                        "\nYou only have " << user.getGold() << " Gold. " << endl;
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 6: // user cancelled
                        {
                            cout << "You decided to cancel the transaction.\n" << endl;
                            break;
                        }

                        default:
                        {
                            cout << "Invalid input, please make a valid choice." << endl;
                            break_loop = false;
                            break;
                        }
                    }
                }
                break;
            }

            case 4: // user wants to buy armor
            {
                string armor_input;
                cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel) [" << (5 * price_multiplier_) << " Gold each]:" << endl;
                cin >> armor_input;

                while(stoi(armor_input) < 0) {
                    cout << "Invalid input." << endl;
                    cout << "How many suits of armor can I get you? (Enter a positive integer, or 0 to cancel):" << endl;
                    cin >> armor_input;
                }

                if(stoi(armor_input) == 0) {
                    cout << "You entered 0 to cancel." << endl;
                    break;
                }

                price = (stoi(armor_input) * 5) * price_multiplier_;

                cout << "You want to buy " << armor_input << " suits of armor for " << price << " Gold? (y/n)" << endl;

                string YorN;
                cin >> YorN;

                if(YorN == "y") {
                    if(user.getGold() >= price) {
                        user.setGold(user.getGold() - price);
                        cout << "Congratulations on your purchase! You now have " << user.getGold() << " Gold." << endl;
                        
                        user.setArmor(user.getArmor() + (stoi(armor_input)));

                        break;
                    }
                    else {
                        cout << "You could not afford " << armor_input << " suits of amor for " << price << " Gold." << 
                            "\nYou only have " << user.getGold() << " Gold. " << endl;
                        break;
                    }
                }
                break;
            }

            case 5: // user wants to sell treasures
            {   
                if(user.getSellingTreasures().size() == 0) {
                    cout << "You have no treasures to sell." << endl;
                    break;
                }

                cout << "Each type of treasure is worth a different amount of gold, here are their values: " <<
                    "\n  Silver Ring (R) - " << (10 * price_multiplier_) << " gold pieces each" << 
                    "\n  Ruby necklace (N) - " << (20 * price_multiplier_) << " gold pieces each" << 
                    "\n  Emerald bracelet (B) - " << (30 * price_multiplier_) << " gold pieces each" << 
                    "\n  Diamond circlet (C) - " << (40 * price_multiplier_) << " gold pieces each" << 
                    "\n  Gem-encrusted goblet (G) - " << (50 * price_multiplier_) << " gold pieces each" << endl;

                string treas_input;
                bool found = false;

                cout << "Here are all the treasures that you have: " << endl;
                for(int i = 0; i < user.getSellingTreasures().size(); i++) {
                    cout << user.getSellingTreasures().at(i).getName() << " ";
                }
                cout << endl;

                cout  << "Enter a treasure to sell using it's capital letter: " << endl;
                cin >> treas_input;

                for(int i = 0; i < user.getSellingTreasures().size(); i++) {
                    if(user.getSellingTreasures().at(i).getName() == treas_input  && treas_input == "R") {
                        price = 10 * price_multiplier_;
                        user.removeTreasure(i);
                        user.setGold(user.getGold() + price);
                        cout << "You just sold your Silver Ring for " << price << " Gold pieces, you now have " << user.getGold() << " Gold." << endl;
                        found = true;
                        i = user.getSellingTreasures().size();
                    }
                    else if(user.getSellingTreasures().at(i).getName() == treas_input && treas_input == "N") {
                        price = 20 * price_multiplier_;
                        user.removeTreasure(i);
                        user.setGold(user.getGold() + price);
                        cout << "You just sold your Ruby Necklace for " << price << " Gold pieces, you now have " << user.getGold() << " Gold." << endl;
                        found = true;
                        i = user.getSellingTreasures().size();
                    }
                    else if(user.getSellingTreasures().at(i).getName() == treas_input && treas_input == "B") {
                        price = 30 * price_multiplier_;
                        user.removeTreasure(i);
                        user.setGold(user.getGold() + price);
                        cout << "You just sold your Emerald Bracelet for " << price << " Gold pieces, you now have " << user.getGold() << " Gold." << endl;
                        found = true;
                        i = user.getSellingTreasures().size();
                    }
                    else if(user.getSellingTreasures().at(i).getName() == treas_input && treas_input == "C") {
                        price = 40 * price_multiplier_;
                        user.removeTreasure(i);
                        user.setGold(user.getGold() + price);
                        cout << "You just sold your Diamond Circlet for " << price << " Gold pieces, you now have " << user.getGold() << " Gold." << endl;
                        found = true;
                        i = user.getSellingTreasures().size();
                    }
                    else if(user.getSellingTreasures().at(i).getName() == treas_input && treas_input == "G") {
                        price = 30 * price_multiplier_;
                        user.removeTreasure(i);
                        user.setGold(user.getGold() + price);
                        cout << "You just sold your Gem-Encrusted Goblet for " << price << " Gold pieces, you now have " << user.getGold() << " Gold." << endl;
                        found = true;
                        i = user.getSellingTreasures().size();
                    }
                }

                if(!found) {
                    cout << "You do not possess that treasure." << endl;
                    break;
                }

                break;
            }

            case 6: // user decides to leave
            {   
                cout << "Are you sure you're ready to leave? You won't be able to buy from me for the rest of the game! (y/n)" << endl;
                cin >> input;
                if(input == "y") {
                    cout << "Good luck my friend! Goodbye!" << endl;
                    end = true;
                    break;
                }

                cout << "Feel free to continue shopping!" << endl;
                break;
            }

            default:
                cout << "Invalid input, please try again." << endl;
        }
    }
}