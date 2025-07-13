#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "Expense.h"
#include <vector>
#include <string>

class Dashboard {
private:
    std::vector<PersonalExpense> personalExpenses;
    std::vector<FriendExpense> friendExpenses;
    std::vector<GroupExpense> groupExpenses;
    std::vector<std::string> groups;

public:
    void addPersonalExpense(const std::string& description, double amount, const std::string& payer);
    void addFriendExpense(const std::string& description, double amount, const std::string& payer, const std::string& friendName);
    void addGroupExpense(const std::string& description, double amount, const std::string& payer, const std::vector<std::string>& groupMembers);
    void deleteExpense(int serialNo, const std::string& expenseType);
    void displayPersonalExpenses() const;
    void displayFriendExpenses() const;
    void displayGroupExpenses() const;
    void displayGroups() const;
    void createGroup(const std::string& groupName, const std::vector<std::string>& members);
    std::vector<std::string> getGroupMembers(const std::string& groupName) const;
    bool groupExists(const std::string& groupName) const;
};

#endif // DASHBOARD_H