#include "../HeaderFiles/Login.h"
#include <iostream>
using namespace std;
#include <string>

// Constructor to initialize default values
LoginDetails::LoginDetails() {
    UserName = "";
    Password = "";
    Email = "";
}

// Sign-up function to store the user's details
bool LoginDetails::SignUp(const string& UserName, const string& Password, const string& Email) {
    this->UserName = UserName;
    this->Password = Password;
    this->Email = Email;
    cout << "Sign-up successful!" << endl;
    return true;  // Return true after successful sign-up
}

// Email validation function
bool LoginDetails::isValidEmail(const string& Email) {
    return (Email.find('@') != string::npos && Email.find(".com") != string::npos);  // Check if '@' and '.com' exist
}

// Password validation (length should be at least 5 characters)
bool LoginDetails::isValidPassword(const string& Password) {
    return (Password.length() >= 5);  // Password must be at least 5 characters
}

// Username validation (it shouldn't be empty)
bool LoginDetails::isValidUserName(const string& UserName) {
    return (UserName != "");  // Username shouldn't be an empty string
}

// Authenticate the user by checking if the credentials match
bool LoginDetails::Authenticate(const string& UserName, const string& Password, const string& Email) {
    return (UserName == this->UserName && Password == this->Password && Email == this->Email);  // Check if all match
}
