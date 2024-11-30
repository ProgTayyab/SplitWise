#include <iostream>
#include <vector>
#include <string>
#include "Dashboard.h"
#include "Login.h"

using namespace std;

int main() {
    Dashboard dashboard;
    Login login;

    string username, password, email;
    cout << "Welcome to SplitWise App!" << endl;

    // User registration/login
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter email: ";
    cin >> email;
    while (!login.isValidEmail(email)) { // Updated to use `isValidEmail`
        cout << "Invalid email format. Please include '@'. Enter email again: ";
        cin >> email;
    }
    cout << "Enter password: ";
    cin >> password;

    login.setUsername(username);
    login.setEmail(email);
    login.setPassword(password);

    cout << "\nLogin successful! Welcome, " << username << "!" << endl;

    // Main menu
    while (true) {
        cout << "\nMain Menu" << endl;
        cout << "1. Add Personal Expense" << endl;
        cout << "2. Add Friend Expense" << endl;
        cout << "3. Add Group Expense" << endl;
        cout << "4. Settle Up Amount" << endl;
        cout << "5. View All Expenses" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string desc;
                double amt;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter amount: ";
                cin >> amt;
                dashboard.addPersonalExpense(desc, amt, username);
                cout << "Personal expense added successfully!" << endl;
                break;
            }
            case 2: {
                string desc, friendName;
                double amt;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter amount: ";
                cin >> amt;
                cout << "Enter friend's name: ";
                cin.ignore();
                getline(cin, friendName);
                dashboard.addFriendExpense(desc, amt, username, friendName);
                cout << "Friend expense added successfully!" << endl;
                break;
            }
            case 3: {
                string desc;
                double amt;
                int numMembers;
                vector<string> members;

                cout << "Enter description: ";
                cin.ignore();
                getline(cin, desc);
                cout << "Enter amount: ";
                cin >> amt;
                cout << "Enter number of group members: ";
                cin >> numMembers;

                cout << "Enter group members' names:" << endl;
                for (int i = 0; i < numMembers; ++i) {
                    string member;
                    cin.ignore();
                    getline(cin, member);
                    members.push_back(member);
                }

                dashboard.addGroupExpense(desc, amt, username, members);
                cout << "Group expense added successfully!" << endl;
                break;
            }
            case 4: {
                string user;
                cout << "Enter username to settle up: ";
                cin >> user;
                dashboard.settleUpAmount(user);
                break;
            }
            case 5: {
                dashboard.viewAllExpenses();
                break;
            }
            case 6:
                cout << "Thank you for using SplitWise. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

