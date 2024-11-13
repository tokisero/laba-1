#include <iostream>
#include <string>
#include "FlightManager.h"
#include "Admin.h"
#include "Person.h"

void login(FlightManager& manager) {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    while (true) {
        if (password == "admin") {
            Admin admin(username);
            admin.menu();
            break;
        }
        else if (password == "user") {
            Person person(username);
            person.menu();
            break;
        }
        else {
            std::cout << "Invalid password. Please try again.\n";
            rewind(stdin);
        }
    }
}

int main() {
    FlightManager manager("flights.db");
    login(manager);
    return 0;
}