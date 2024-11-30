#include "Expense.h"

// Expense constructor
Expense::Expense(string desc, double amt, string payer)
    : description(desc), amount(amt), payer(payer) {}

// PersonalExpense constructor
PersonalExpense::PersonalExpense(string desc, double amt, string payer)
    : Expense(desc, amt, payer) {}

// Display method for PersonalExpense
void PersonalExpense::displayExpense() const {
    cout << "Personal Expense: " << description
         << ", Amount: $" << amount
         << ", Paid by: " << payer << endl;
}

// FriendExpense constructor
FriendExpense::FriendExpense(string desc, double amt, string payer, string friendName)
    : Expense(desc, amt, payer), friendName(friendName) {}

// Display method for FriendExpense
void FriendExpense::displayExpense() const {
    cout << "Friend Expense: " << description
         << ", Amount: $" << amount
         << ", Paid by: " << payer
         << ", Friend: " << friendName << endl;
}

// GroupExpense constructor
GroupExpense::GroupExpense(string desc, double amt, string payer, vector<string> groupMembers)
    : Expense(desc, amt, payer), groupMembers(groupMembers) {}

// Display method for GroupExpense
void GroupExpense::displayExpense() const {
    cout << "Group Expense: " << description
         << ", Amount: $" << amount
         << ", Paid by: " << payer
         << ", Group Members: ";
    for (const auto& member : groupMembers) {
        cout << member << " ";
    }
    cout << endl;
}
