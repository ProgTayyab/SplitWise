#include "Expense.h"
#include "Theme.h"
#include <iostream>

using namespace std;

// Base Expense Constructor
Expense::Expense(const std::string& description, double amount, const std::string& payer)
    : description(description), amount(amount), payer(payer) {}

// PersonalExpense Constructor
PersonalExpense::PersonalExpense(const std::string& description, double amount, const std::string& payer)
    : Expense(description, amount, payer) {}

void PersonalExpense::displayExpense() const {
    Theme::printSeparator();
    Theme::printHeader("             PERSONAL EXPENSE            ");
    Theme::printSeparator();
    Theme::printMenu("Payer       : " + payer + "\n");
    Theme::printMenu("Description : " + description + "\n");
    Theme::printMenu("Amount      : $" + std::to_string(amount) + "\n");
    Theme::printSeparator();
}



// FriendExpense Constructor
FriendExpense::FriendExpense(const std::string& description, double amount, const std::string& payer, const std::string& friendName)
    : Expense(description, amount, payer), friendName(friendName) {}

void FriendExpense::displayExpense() const {
    Theme::printSeparator();
    Theme::printHeader("              FRIEND EXPENSE             ");
    Theme::printSeparator();
    Theme::printMenu("Payer       : " + payer + "\n");
    Theme::printMenu("Friend      : " + friendName + "\n");
    Theme::printMenu("Description : " + description + "\n");
    Theme::printMenu("Amount      : $" + std::to_string(amount) + "\n");
    Theme::printSeparator();
}



// GroupExpense Constructor
GroupExpense::GroupExpense(const std::string& description, double amount, const std::string& payer, const std::vector<std::string>& groupMembers)
    : Expense(description, amount, payer), groupMembers(groupMembers) {}


void GroupExpense::displayExpense() const {
    Theme::printSeparator();
    Theme::printHeader("              GROUP EXPENSE              ");
    Theme::printSeparator();
    Theme::printMenu("Payer        : " + payer + "\n");
    Theme::printMenu("Description  : " + description + "\n");
    Theme::printMenu("Amount       : $" + std::to_string(amount) + "\n");
    
    std::string members = "Group Members: ";
    for (const auto& member : groupMembers) {
        members += member + " ";
    }
    Theme::printMenu(members + "\n");
    Theme::printSeparator();
}

