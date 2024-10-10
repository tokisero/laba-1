#include <iostream>
#include <locale>
#include "FlightManager.h"
#include "Flight.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    FlightManager manager;
    int choice = 0;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add flight\n";
        std::cout << "2. Edit flight data\n";
        std::cout << "3. Remove flight\n";
        std::cout << "4. Find flight\n";
        std::cout << "5. List all flights\n";
        std::cout << "6. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int flightNumber;
            std::string destination;
            int day;
            int month;
            int time;
            std::cout << "Enter flight number\n";
            std::cin >> flightNumber;
            std::cout << "Enter destination\n";
            std::cin >> destination;
            std::cout << "Enter month\n";
            std::cin >> month;
            std::cout << "Enter day\n";
            std::cin >> day;
            std::cout << "Enter departure time\n";
            std::cin >> time;
            manager.addFlight(flightNumber, destination, day, month, time);
            break;
        }
        case 2: {
            int flightNumber;
            std::cout << "Enter flight number: ";
            std::cin >> flightNumber;
            manager.editFlight(flightNumber);
            break;
        }
        case 3: {
            int flightNumber;
            std::cout << "Enter flight number: ";
            std::cin >> flightNumber;
            manager.deleteFlight(flightNumber);
            break;
        }
        case 4: {
            manager.findFlight();
            break;
        }
        case 5: {
            manager.listAllFlights();
            break;
        }
        case 6: {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice, try again." << std::endl;
        }
        }
    } while (choice != 6);
    return 0;
}
