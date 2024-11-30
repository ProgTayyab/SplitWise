#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <string>
#include <vector>
#include "Expense.h"

using namespace std;

class Dashboard {
private:
    vector<PersonalExpense> personalExpenses;
    vector<FriendExpense> friendExpenses;
    vector<GroupExpense> groupExpenses;

public:
    void addPersonalExpense(const string& description, double amount, const string& payer);
    void addFriendExpense(const string& description, double amount, const string& payer, const string& friendName);
    void addGroupExpense(const string& description, double amount, const string& payer, const vector<string>& groupMembers);

    void viewAllExpenses() const; // Renamed from `displayAllExpenses`
    void settleUpAmount(const string& user); // Renamed from `settleUp`
};

#endif
