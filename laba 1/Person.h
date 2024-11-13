#pragma once
#include "User.h"
#include "FlightManager.h"

class Person : public User, public FlightManager {
public:
    explicit Person(const std::string& username);
    void menu() override;
};