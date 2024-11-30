#include "Login.h"
#include <iostream>

void Login::setUsername(const string& user) {
    username = user;
}

void Login::setEmail(const string& mail) {
    email = mail;
}

void Login::setPassword(const string& pass) {
    password = pass;
}

string Login::getUsername() const {
    return username;
}

string Login::getEmail() const {
    return email;
}

string Login::getPassword() const {
    return password;
}

bool Login::isValidEmail(const string& mail) const { // Updated to match the header file
    return mail.find('@') != string::npos;
}

