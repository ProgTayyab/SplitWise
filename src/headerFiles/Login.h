#ifndef LOGIN_H
#define LOGIN_H

#include <string>

using namespace std;

class Login {
private:
    string username;
    string email;
    string password;

public:
    void setUsername(const string& user);
    void setEmail(const string& mail);
    void setPassword(const string& pass);

    string getUsername() const;
    string getEmail() const;
    string getPassword() const;

    bool isValidEmail(const string& mail) const; // Renamed from `validateEmail`
};

#endif
