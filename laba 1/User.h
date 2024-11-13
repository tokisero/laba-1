#pragma once
#include <string>

class User {
public:
    explicit User(const std::string& username);
    virtual ~User() = default;
    std::string username;
    virtual void menu() = 0;
};