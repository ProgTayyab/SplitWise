#ifndef LOGIN_H
#define LOGIN_H

#include <string>  // Include string header

using namespace std;  // Use the standard namespace

class LoginDetails {
private:
    string Email;
    string UserName;
    string Password;

public:
    LoginDetails();  // Default constructor
    LoginDetails(const string& email, const string& username, const string& password); // Parametrized constructor

    bool SignUp(const string& email, const string& username, const string& password);
    bool isValidUserName(const string& username);
    bool isValidPassword(const string& password);
    bool isValidEmail(const string& email);
    bool Authenticate(const string& email, const string& username, const string& password);
};

#endif // LOGIN_H
