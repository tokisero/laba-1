#pragma once
#include "User.h"
#include "FlightManager.h"

class Admin : public User, public FlightManager {

public:
    explicit Admin(const std::string& username);
    void menu() override;
};