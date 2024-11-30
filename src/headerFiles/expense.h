
#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Expense class
class Expense {
protected:
    string description;
    double amount;
    string payer;

public:
    Expense(string desc, double amt, string payer);
    virtual ~Expense() {}

    virtual void displayExpense() const = 0; // Pure virtual function for displaying expenses
    double getAmount() const { return amount; }
    string getPayer() const { return payer; }
};

// Derived class for Personal Expenses
class PersonalExpense : public Expense {
public:
    PersonalExpense(string desc, double amt, string payer);
    void displayExpense() const override;
};

// Derived class for Friend Expenses
class FriendExpense : public Expense {
private:
    string friendName;

public:
    FriendExpense(string desc, double amt, string payer, string friendName);
    void displayExpense() const override;
    string getFriendName() const { return friendName; }
};

// Derived class for Group Expenses
class GroupExpense : public Expense {
private:
    vector<string> groupMembers;

public:
    GroupExpense(string desc, double amt, string payer, vector<string> groupMembers);
    void displayExpense() const override;
    vector<string> getGroupMembers() const { return groupMembers; }
};

#endif
