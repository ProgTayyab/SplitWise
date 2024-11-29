#include <iostream>
#include "../HeaderFiles/Login.h"


using namespace std;

int main() {
    // Create an object of LoginDetails class
    LoginDetails user;

    int choice;
    cout << "Welcome to the Login System" << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // Sign Up
        string email, username, password;
        
        cout << "Enter your email: ";
        cin >> email;
        
        // Validate email format
        if (!user.isValidEmail(email)) {
            cout << "Invalid email format. Please try again." << endl;
            return 0;
        }

        cout << "Enter your username: ";
        cin >> username;
        
        // Validate username
        if (!user.isValidUserName(username)) {
            cout << "Invalid username. Please try again." << endl;
            return 0;
        }

        cout << "Enter your password: ";
        cin >> password;

        // Validate password
        if (!user.isValidPassword(password)) {
            cout << "Password too short! It must be at least 5 characters." << endl;
            return 0;
        }

        // Call SignUp method to store the credentials
        user.SignUp(email, username, password);
    }
    else if (choice == 2) {
        // Login
        string email, username, password;

        cout << "Enter your email: ";
        cin >> email;
        
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password: ";
        cin >> password;

        // Authenticate the user
        if (user.Authenticate(username, password, email)) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Login failed. Invalid credentials." << endl;
        }
    }
    else {
        cout << "Invalid choice. Please restart the program and try again." << endl;
    }

    return 0;
}
