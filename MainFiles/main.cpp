#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include "User.h"
#include "Theme.h"

using namespace std;

int main() {
    // Initialize theme system
    Theme::loadTheme();
    
    string username, email, password, description, friendName, groupName;
    int choice, expenseChoice, numMembers, serialNo;
    vector<string> members;
    double amount;

    try {
        // Welcome header
        Theme::clearScreen();
        Theme::printHeader("===== WELCOME TO SPLITWISE =====");
        cout << endl;
        
        // Registration/Login
        Theme::printInput("Enter username: ");
        cin >> username;
        Theme::printInput("Enter email: ");
        cin >> email;
        while (!Login::isValidEmail(email)) {
            Theme::printError("Invalid email format. Please try again: ");
            cin >> email;
        }
        Theme::printInput("Enter password: ");
        cin >> password;

        User user(username, email, password);

        Theme::printSuccess("Login successful! Welcome, " + username + ".");
        cout << endl;

        // Main Menu
        do {
            Theme::printHeader("\n===== MAIN MENU =====");
            Theme::printMenu("1. Add Personal Expense\n");
            Theme::printMenu("2. Add Group Expense\n");
            Theme::printMenu("3. Add Friend Expense\n");
            Theme::printMenu("4. Create Group\n");
            Theme::printMenu("5. Display Expenses\n");
            Theme::printMenu("6. Delete Expense\n");
            Theme::printMenu("7. Settings\n");
            Theme::printMenu("8. Exit\n");
            Theme::printInput("Enter your choice: ");
            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                Theme::printError("Invalid input. Please enter a valid choice: ");
            }

            switch (choice) {
                case 1:
                    cin.ignore();
                    Theme::printInput("Enter expense description: ");
                    getline(cin, description);
                    Theme::printInput("Enter amount: ");
                    while (!(cin >> amount)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Theme::printError("Invalid input. Please enter a valid amount: ");
                    }
                    user.addPersonalExpense(description, amount);
                    Theme::printSuccess("Personal expense added successfully!");
                    break;

                case 2:
                    cout << "Current Groups:\n";
                    user.displayGroups();
                    cout << "Do you want to add an expense to an existing group or create a new group?\n"
                         << "1. Add to existing group\n"
                         << "2. Create new group\n"
                         << "Enter your choice: ";
                    while (!(cin >> expenseChoice) || (expenseChoice != 1 && expenseChoice != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid choice: ";
                    }
                    if (expenseChoice == 1) {
                        cout << "Enter group name: ";
                        cin.ignore();
                        getline(cin, groupName);
                        if (user.groupExists(groupName)) {
                            cout << "Group exists" << endl;
                            cout << "Enter expense description: ";
                            getline(cin, description);
                            cout << "Enter amount: ";
                            while (!(cin >> amount)) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter a valid amount: ";
                            }
                            user.addGroupExpense(description, amount, groupName);
                        } else {
                            cout << "Group does not exist" << endl;
                        }
                    } else if (expenseChoice == 2) {
                        cin.ignore();
                        cout << "Enter group name: ";
                        getline(cin, groupName);
                        cout << "Enter number of group members: ";
                        while (!(cin >> numMembers) || numMembers <= 0) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a valid number: ";
                        }
                        cin.ignore();
                        members.clear();
                        for (int i = 0; i < numMembers; ++i) {
                            string member;
                            cout << "Enter member " << i + 1 << ": ";
                            getline(cin, member);
                            members.push_back(member);
                        }
                        user.createGroup(groupName, members);
                        cout << "Enter expense description: ";
                        getline(cin, description);
                        cout << "Enter amount: ";
                        while (!(cin >> amount)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a valid amount: ";
                        }
                        user.addGroupExpense(description, amount, groupName);
                    }
                    break;

                case 3:
                    Theme::printInput("Enter friend's name: ");
                    cin >> friendName;
                    cin.ignore();
                    Theme::printInput("Enter expense description: ");
                    getline(cin, description);
                    Theme::printInput("Enter amount: ");
                    while (!(cin >> amount)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Theme::printError("Invalid input. Please enter a valid amount: ");
                    }
                    user.addFriendExpense(description, amount, friendName);
                    Theme::printSuccess("Friend expense added successfully!");
                    break;

                case 4:
                    cin.ignore();
                    cout << "Enter group name: ";
                    getline(cin, groupName);
                    cout << "Enter number of group members: ";
                    while (!(cin >> numMembers) || numMembers <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid number: ";
                    }
                    cin.ignore();
                    members.clear();
                    for (int i = 0; i < numMembers; ++i) {
                        string member;
                        cout << "Enter member " << i + 1 << ": ";
                        getline(cin, member);
                        members.push_back(member);
                    }
                    user.createGroup(groupName, members);
                    break;

                case 5:
                    cout << "1. Personal Expenses\n"
                         << "2. Friend Expenses\n"
                         << "3. Group Expenses\n"
                         << "4. All Expenses\n"
                         << "Enter your choice: ";
                    while (!(cin >> expenseChoice)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid choice: ";
                    }
                    user.displayExpenses(expenseChoice);
                    break;

                case 6:
                    cout << "Enter the category to delete:\n"
                         << "1. Personal Expense\n"
                         << "2. Friend Expense\n"
                         << "3. Group Expense\n"
                         << "Enter your choice: ";
                    while (!(cin >> expenseChoice) || expenseChoice < 1 || expenseChoice > 3) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid choice: ";
                    }
                    cout << "Enter the serial number of the expense to delete: ";
                    while (!(cin >> serialNo) || serialNo < 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please enter a valid number: ";
                    }
                    if (expenseChoice == 1)
                        user.deleteExpense(serialNo, "personal");
                    else if (expenseChoice == 2)
                        user.deleteExpense(serialNo, "friend");
                    else if (expenseChoice == 3)
                        user.deleteExpense(serialNo, "group");
                    else
                        cout << "Invalid category!" << endl;
                    break;

                case 7:
                    // Settings menu - Dark mode toggle implementation
                    Theme::printHeader("\n===== SETTINGS =====");
                    Theme::printMenu("1. Toggle Dark Mode (Current: ");
                    Theme::printMenu((Theme::getCurrentMode() == Theme::DARK) ? "Dark)\n" : "Light)\n");
                    Theme::printMenu("2. Back to Main Menu\n");
                    Theme::printInput("Enter your choice: ");
                    int settingsChoice;
                    while (!(cin >> settingsChoice) || (settingsChoice != 1 && settingsChoice != 2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        Theme::printError("Invalid input. Please enter a valid choice: ");
                    }
                    if (settingsChoice == 1) {
                        Theme::toggleMode();
                        Theme::printSuccess("Theme switched to " + 
                            string((Theme::getCurrentMode() == Theme::DARK) ? "Dark" : "Light") + " mode!");
                        cout << endl;
                        Theme::printInput("Press Enter to continue...");
                        cin.ignore();
                        cin.get();
                    }
                    break;

                case 8:
                    Theme::printSuccess("Exiting application. Thank you for using SplitWise!");
                    // Reset terminal colors before exit
                    cout << Theme::getResetColor();
                    break;

                default:
                    Theme::printError("Invalid choice. Please try again.");
            }
        } while (choice != 8);
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }

    return 0;
}
