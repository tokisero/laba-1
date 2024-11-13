#include <iostream>
#include <string>
#include "FlightManager.h"
#include "Admin.h"
#include "Person.h"

void login() {
    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    int a = 0;
    while (a == 0) {
        if (password == "admin") {
            Admin admin(username);
            admin.menu();
            a = 1;
        }
        else if (password == "user") {
            Person person(username);
            person.menu();
            a = 1;
        }
        else {
            std::cout << "Invalid password. Please try again.\n";
            rewind(stdin);
        }
    }
}

int main() {
    FlightManager manager("flights.db");
    login();
    return 0;
}