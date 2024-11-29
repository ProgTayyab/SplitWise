
#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <iostream>

using namespace std;

// Base class for general expense
class Expense {
protected:
    string description;
    double amount;
    string payer;

public:
    // Constructor to initialize the expense
    Expense(string desc, double amt, string payer)
        : description(desc), amount(amt), payer(payer) {}

    // Pure virtual function to display expense (will be overridden in derived classes)
    virtual void displayExpense() = 0;
    
    // Getter functions (optional, if needed for further functionality)
    double getAmount() { return amount; }
    string getPayer() { return payer; }
    string getDescription() { return description; }
};




class GroupExpense : public Expense {
private:
    vector<string> groupMembers; // A list of group members who are sharing the expense

public:
    // Constructor to initialize the group expense
    GroupExpense(string desc, double amt, string payer, vector<string> groupMembers)
        : Expense(desc, amt, payer), groupMembers(groupMembers) {}

    // Overriding the displayExpense method
    void displayExpense() override {
        cout << "Group Expense Description: " << description << endl;
        cout << "Amount: " << amount << endl;
        cout << "Paid by: " << payer << endl;
        cout << "Shared with: ";
        for (const auto& member : groupMembers) {
            cout << member << " ";
        }
        cout << endl;
        cout << "--------------------------" << endl;
    }
};



// Derived class for friend expenses
class FriendExpense : public Expense {
private:
    string friendName; // The friend's name for the shared expense

public:
    // Constructor to initialize the friend expense
    FriendExpense(string desc, double amt, string payer, string friendName)
        : Expense(desc, amt, payer), friendName(friendName) {}

    // Overriding the displayExpense method
    void displayExpense() override {
        cout << "Friend Expense Description: " << description << endl;
        cout << "Amount: " << amount << endl;
        cout << "Paid by: " << payer << endl;
        cout << "Shared with: " << friendName << endl;
        cout << "--------------------------" << endl;
    }
};

#endif // EXPENSE_H
