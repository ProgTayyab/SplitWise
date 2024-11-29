#ifndef PERSONAL_EXPENSE_H
#define PERSONAL_EXPENSE_H

#include "Expense.h"

// Derived class for personal expenses
class PersonalExpense : public Expense {
public:
    // Constructor to initialize the personal expense
    PersonalExpense(string desc, double amt, string payer)
        : Expense(desc, amt, payer) {}

    // Overriding the displayExpense method
    void displayExpense() override {
        cout << "Personal Expense Description: " << description << endl;
        cout << "Amount: " << amount << endl;
        cout << "Paid by: " << payer << endl;
        cout << "--------------------------" << endl;
    }
};

#endif // PERSONAL_EXPENSE_H
