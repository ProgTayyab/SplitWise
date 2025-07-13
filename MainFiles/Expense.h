#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <vector>

// Base Expense class
class Expense {
protected:
    std::string description;
    double amount;
    std::string payer;

public:
    Expense(const std::string& description, double amount, const std::string& payer);
    virtual void displayExpense() const = 0;
    virtual ~Expense() = default;
};

// PersonalExpense class
class PersonalExpense : public Expense {
public:
    PersonalExpense(const std::string& description, double amount, const std::string& payer);
    void displayExpense() const override;
};

// FriendExpense class
class FriendExpense : public Expense {
private:
    std::string friendName;

public:
    FriendExpense(const std::string& description, double amount, const std::string& payer, const std::string& friendName);
    void displayExpense() const override;
};

// GroupExpense class
class GroupExpense : public Expense {
private:
    std::vector<std::string> groupMembers;

public:
    GroupExpense(const std::string& description, double amount, const std::string& payer, const std::vector<std::string>& groupMembers);
    void displayExpense() const override;
};

#endif // EXPENSE_H