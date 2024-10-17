#include "FlightManager.h"
#include <iostream>
#include <ranges>

FlightManager::FlightManager(const std::string& filename) : db(filename) {
    flights = db.readFromFile();
}

FlightManager::~FlightManager() {
    db.writeToFile(flights);
}

void updateFlightDetails(Flight& flight) {
    std::string newDestination;
    int newDay;
    int newMonth;
    int newTime;
    std::string zero = "0";
    std::cout << "Enter new destination (0 to skip): ";
    std::cin >> newDestination;
    if (newDestination != zero) {
        flight.setDestination(newDestination);
    }

    std::cout << "Enter new daay of departure (0 to skip): ";
    std::cin >> newDay;
    if (newDay != 0 && newDay <= 31) {
        flight.setDay(newDay);
    }

    std::cout << "Enter new month of departure (0 to skip): ";
    std::cin >> newMonth;
    if (newMonth != 0 && newMonth <= 12) {
        flight.setMonth(newMonth);
    }

    std::cout << "Enter new time of departure (0 to skip): ";
    std::cin >> newTime;
    if (newTime != 0 && newTime <= 24) {
        flight.setTime(newTime);
    }

    std::cout << "Flight details successfully updated!" << std::endl;
}

void FlightManager::addFlight(int flightNumber, const std::string& destination, int day, int month, int time) {
    Flight newFlight(flightNumber, destination, day, month, time);
    *this += newFlight;
    std::cout << "Flight successfully added!" << std::endl;
}

void FlightManager::editFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            updateFlightDetails(flight);
            return;
        }
    }
    std::cout << "Flight with that number not found!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    auto it = std::ranges::find_if(flights, [flightNumber](const Flight& f) {return f.getFlightNumber() == flightNumber; });
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "Flight deleted!" << std::endl;
    }
    else {
        std::cout << "Flight with that number not found!" << std::endl;
    }
}

void findFlightByNumber(const std::vector<Flight>& flights) {
    int flightNumber;
    std::cout << "Enter flight number: ";
    std::cin >> flightNumber;
    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            std::cout << flight;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Flight with that number not found!" << std::endl;
    }
}

void findFlightByDestination(const std::vector<Flight>& flights) {
    std::string destination;
    std::cout << "Enter destination: ";
    std::cin >> destination;
    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            std::cout << flight;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Flight with that destination not found!" << std::endl;
    }
}

void findFlightByDate(const std::vector<Flight>& flights) {
    int day;
    int month;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDay() == day && flight.getMonth() == month) {
            std::cout << flight;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Flight with that date not found!" << std::endl;
    }
}

void FlightManager::findFlight() const {
    int choice = 0;
    do {
        std::cout << "1. Find by number\n";
        std::cout << "2. Find by destination\n";
        std::cout << "3. Find by date\n";
        std::cout << "4. Exit search\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            findFlightByNumber(flights);
            break;
        case 2:
            findFlightByDestination(flights);
            break;
        case 3:
            findFlightByDate(flights);
            break;
        case 4:
            std::cout << "Exiting search." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, try again." << std::endl;
            break;
        }
    } while (choice != 4);
}

void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        std::cout << "No available flights." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            std::cout << flight;
            std::cout << "-------------------" << std::endl;
        }
    }
}

FlightManager& FlightManager::operator += (const Flight& flight) {
    int flightNumber = flight.getFlightNumber();
    std::string destination = flight.getDestination();
    int day = flight.getDay();
    int month = flight.getMonth();
    int time = flight.getTime();
    flights.emplace_back(flightNumber, destination, day, month, time);
    return *this;
}