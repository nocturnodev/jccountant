#include <iostream>
#include <ctime>
#include "nlohmann/json.hpp"
#include "include/Transaction.h"
#include "include/Database.h"

using json = nlohmann::json;

int main() {
    Database db("db.json");

    time_t now = time(0);
    std::string date = ctime(&now);

    char inputType[8];
    std::string stringType;
    char inputReason[80];
    std::string stringReason;
    int inputAmount;

    int choice;

    std::cout << "What do you want to do?\n1. Add an entry\n2. Remove an entry\n3. See all entries\n4. Reset the database\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
        {
            std::cout << "What is the type of this transaction?\n";
            std::cin.ignore(INT_MAX, '\n');
            std::cin.get(inputType, 8);
            stringType = inputType;

            std::cout << "What is the reason for this transaction?\n";
            std::cin.ignore(INT_MAX, '\n');
            std::cin.get(inputReason, 80);
            stringReason = inputReason;

            Transaction t(date, stringType, stringReason, inputAmount);

            db.addEntry(t);
            break;
        }
        case 2:
            int idx;
            std::cout << "Which entry would you like to remove? (Starting from 0)\n";
            std::cin >> idx;
            db.removeEntry(idx);
            break;
        case 3:
            db.seeEntries();
            break;
        case 4:
            db.resetDatabase();
            break;
    }

    return 0;
}