#include <iostream>
#include <iomanip>
#include <cmath>     
#include <string>
#include <sstream>   
#include <algorithm> 

struct MonthlyBudget {
    double housing,
           utilities,
           household_expenses,
           transportation,
           food,
           medical,
           insurance,
           entertainment,
           clothing,
           misc;
};


const char* MonthlyBudgetLabels[] = {
    "Housing",
    "Utilities",
    "Household Expenses",
    "Transportation",
    "Food",
    "Medical",
    "Insurance",
    "Entertainment",
    "Clothing",
    "Miscellaneous"
};


MonthlyBudget GOAL = {
    500.00,
    150.00,
    65.00,
    50.00,
    250.00,
    30.00,
    100.00,
    150.00,
    75.00,
    50.00
};


double sum(MonthlyBudget& b) {
    double s = 0;
    for (size_t i = 0; i < 10; i++) {
        s += *((double *)(&b) + i);
    }
    return s;
}


double roundToMoney(double a) {
    return floor((a * 100) + 0.5) / 100;
}


bool eq(double a, double b) {
    return (fabs(a - b) <= 0.009);
}


void printCompare(double e, double goal) {
    if (eq(e, goal)) {
        std::cout << "Exactly on budget.\n";
    } else if (e > goal) {
        std::cout << "$" << (e - goal) << " over budget.\n";
    } else {
        std::cout << "$" << (goal - e) << " under budget.\n";
    }
    return;
}

void displayDiffs(MonthlyBudget b) {
    std::cout << "Budget Analysis\n"
                 "----------------------------------------------------\n";
    for (size_t i = 0; i < 10; i++) {
        std::cout << std::setw(18) << MonthlyBudgetLabels[i] << ": ";
        printCompare( *((double *)(&b) + i), *((double *)(&GOAL) + i) );
    }

    std::cout << "----------------------------------------------------\n"
                 "Overall Expenses:  ";
    printCompare( sum(b), sum(GOAL) );

    return;
}


bool isNotNumChar(char c) {
    static char number_chars[] = {'0', '1', '2', '3', '4', '5',
                                  '6', '7', '8', '9', '.'};
    return (std::count(number_chars, number_chars+11, c) == 0);
}


double processMoney(std::string raw) {
    // string to filled by remove_copy_if
    std::string processed (raw.size(), '\0');

    // remove non number-relavant characters
    std::remove_copy_if(raw.c_str(),
                        raw.c_str() + raw.size(),
                        processed.begin(),
                        isNotNumChar);

   
    std::istringstream iss (processed);

  
    double money = 0.0;
    iss >> money;
    return roundToMoney(money);
}

MonthlyBudget makeMonthlyBudget() {
    MonthlyBudget b;

    std::cout << "Enter the amounts spent in each category.\n";

    for (size_t i = 0; i < 10; i++) {
        std::string unprocessed;
        std::cout << MonthlyBudgetLabels[i] << ": ";
        std::getline(std::cin, unprocessed);
        *((double *)(&b) + i) = processMoney(unprocessed);
    }

    std::cout << '\n';

    return b;
}


int main() {
    displayDiffs(makeMonthlyBudget()); // Functional Programming. Whoo.
    return 0;
}
