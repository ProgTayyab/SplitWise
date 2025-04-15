#include "Dashboard.h"
#include <iostream>
#include <algorithm>

void Dashboard::addPersonalExpense(const std::string& description, double amount, const std::string& payer) {
    PersonalExpense expense(description, amount, payer);
    personalExpenses.push_back(expense);
}

void Dashboard::addFriendExpense(const std::string& description, double amount, const std::string& payer, const std::string& friendName) {
    FriendExpense expense(description, amount, payer, friendName);
    friendExpenses.push_back(expense);
}

void Dashboard::addGroupExpense(const std::string& description, double amount, const std::string& payer, const std::vector<std::string>& groupMembers) {
    GroupExpense expense(description, amount, payer, groupMembers);
    groupExpenses.push_back(expense);
}

void Dashboard::deleteExpense(int serialNo, const std::string& expenseType) {
    if (expenseType == "personal" && serialNo >= 0 && serialNo < personalExpenses.size()) {
        personalExpenses.erase(personalExpenses.begin() + serialNo);
    } else if (expenseType == "friend" && serialNo >= 0 && serialNo < friendExpenses.size()) {
        friendExpenses.erase(friendExpenses.begin() + serialNo);
    } else if (expenseType == "group" && serialNo >= 0 && serialNo < groupExpenses.size()) {
        groupExpenses.erase(groupExpenses.begin() + serialNo);
    } else {
        std::cout << "Invalid serial number or expense type!" << std::endl;
    }
}

void Dashboard::displayPersonalExpenses() const {
    for (int i = 0; i < personalExpenses.size(); ++i) {
        std::cout << i << ". ";
        personalExpenses[i].displayExpense();
    }
}

void Dashboard::displayFriendExpenses() const {
    for (int i = 0; i < friendExpenses.size(); ++i) {
        std::cout << i << ". ";
        friendExpenses[i].displayExpense();
    }
}

void Dashboard::displayGroupExpenses() const {
    for (int i = 0; i < groupExpenses.size(); ++i) {
        std::cout << i << ". ";
        groupExpenses[i].displayExpense();
    }
}
void Dashboard::displayGroups() const {
    std::cout << "Groups:\n";
    for (const auto& group : groups) {
        std::cout << "- " << group << "\n";
    }}

void Dashboard::createGroup(const std::string& groupName, const std::vector<std::string>& members) {
    groups.push_back(groupName);
    // You can also store the members if needed
}

std::vector<std::string> Dashboard::getGroupMembers(const std::string& groupName) const {
    // Placeholder implementation
    // You need to implement the logic to fetch the actual group members based on the group name
    std::vector<std::string> members;
    // Example: Fetch members from a map or database
    return members;
}

bool Dashboard::groupExists(const std::string& groupName) const {
    return std::find(groups.begin(), groups.end(), groupName) != groups.end();
}