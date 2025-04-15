#include "Login.h"
#include <iostream>
#include <regex>

Login::Login() : username(""), email(""), password("") {}

void Login::setUsername(const std::string& username) {
    this->username = username;
}

void Login::setEmail(const std::string& email) {
    this->email = email;
}

void Login::setPassword(const std::string& password) {
    this->password = password;
}

bool Login::authenticate(const std::string& username, const std::string& password) const {
    return this->username == username && this->password == password;
}

// Simple email validation using regex
bool Login::isValidEmail(const std::string& email) {
    const std::regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    return std::regex_match(email, pattern);
}