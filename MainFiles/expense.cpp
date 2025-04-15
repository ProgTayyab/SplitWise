#include "Expense.h"
#include <iostream>

using namespace std;

// Base Expense Constructor
Expense::Expense(const std::string& description, double amount, const std::string& payer)
    : description(description), amount(amount), payer(payer) {}

// PersonalExpense Constructor
PersonalExpense::PersonalExpense(const std::string& description, double amount, const std::string& payer)
    : Expense(description, amount, payer) {}

void PersonalExpense::displayExpense() const {
    cout << "=========================================\n";
    cout << "             PERSONAL EXPENSE            \n";
    cout << "=========================================\n";
    cout << "Payer       : " << payer << "\n"
         << "Description : " << description << "\n"
         << "Amount      : $" << amount << "\n";
    cout << "=========================================\n";
}



// FriendExpense Constructor
FriendExpense::FriendExpense(const std::string& description, double amount, const std::string& payer, const std::string& friendName)
    : Expense(description, amount, payer), friendName(friendName) {}

void FriendExpense::displayExpense() const {
    cout << "=========================================\n";
    cout << "              FRIEND EXPENSE             \n";
    cout << "=========================================\n";
    cout << "Payer       : " << payer << "\n"
         << "Friend      : " << friendName << "\n"
         << "Description : " << description << "\n"
         << "Amount      : $" << amount << "\n";
    cout << "=========================================\n";
}



// GroupExpense Constructor
GroupExpense::GroupExpense(const std::string& description, double amount, const std::string& payer, const std::vector<std::string>& groupMembers)
    : Expense(description, amount, payer), groupMembers(groupMembers) {}


void GroupExpense::displayExpense() const {
    std::cout << "=========================================\n";
    std::cout << "              GROUP EXPENSE              \n";
    std::cout << "=========================================\n";
    std::cout << "Payer        : " << payer << "\n"
              << "Description  : " << description << "\n"
              << "Amount       : $" << amount << "\n"
              << "Group Members: ";
    
    // Display group members in a formatted way
    for (const auto& member : groupMembers) {
        std::cout << member << " ";
    }
    std::cout << "\n=========================================\n";
}

