#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login {
private:
    std::string username;
    std::string email;
    std::string password;

public:
    Login();
    void setUsername(const std::string& username);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);
    bool authenticate(const std::string& username, const std::string& password) const;
    static bool isValidEmail(const std::string& email);
};

#endif // LOGIN_H