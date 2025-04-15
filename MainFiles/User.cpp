#include "User.h"

User::User(const std::string& username, const std::string& email, const std::string& password) {
    this->username = username;
    login.setUsername(username);
    login.setEmail(email);
    login.setPassword(password);
}

bool User::authenticate(const std::string& username, const std::string& password) {
    return login.authenticate(username, password);
}

void User::addPersonalExpense(const std::string& description, double amount) {
    dashboard.addPersonalExpense(description, amount, username);
}

void User::addFriendExpense(const std::string& description, double amount, const std::string& friendName) {
    dashboard.addFriendExpense(description, amount, username, friendName);
}

void User::addGroupExpense(const std::string& description, double amount, const std::string& groupName) {
    std::vector<std::string> members = dashboard.getGroupMembers(groupName);
    dashboard.addGroupExpense(description, amount, username, members);
}

void User::createGroup(const std::string& groupName, const std::vector<std::string>& members) {
    dashboard.createGroup(groupName, members);
}

void User::displayExpenses(int expenseChoice) const {
    if (expenseChoice == 1) {
        dashboard.displayPersonalExpenses();
    } else if (expenseChoice == 2) {
        dashboard.displayFriendExpenses();
    } else if (expenseChoice == 3) {
        dashboard.displayGroupExpenses();
    } else if (expenseChoice == 4) {
        dashboard.displayPersonalExpenses();
        dashboard.displayFriendExpenses();
        dashboard.displayGroupExpenses();
    }
}

void User::deleteExpense(int serialNo, const std::string& expenseType) {
    dashboard.deleteExpense(serialNo, expenseType);
}

void User::displayGroups() const {
    dashboard.displayGroups();
}
bool User::groupExists(const std::string& groupName) const {
    return dashboard.groupExists(groupName);
}