#ifndef USER_H
#define USER_H

#include "Login.h"
#include "Dashboard.h"
#include <string>
#include <vector>

class User {
private:
    std::string username;
    Login login;
    Dashboard dashboard;

public:
    User(const std::string& username, const std::string& email, const std::string& password);
    bool authenticate(const std::string& username, const std::string& password);
    void addPersonalExpense(const std::string& description, double amount);
    void addFriendExpense(const std::string& description, double amount, const std::string& friendName);
    void addGroupExpense(const std::string& description, double amount, const std::string& groupName);
    void createGroup(const std::string& groupName, const std::vector<std::string>& members);
    void displayExpenses(int expenseChoice) const;
    void deleteExpense(int serialNo, const std::string& expenseType);
    void displayGroups() const;
    bool groupExists(const std::string& groupName) const;
};

#endif // USER_H