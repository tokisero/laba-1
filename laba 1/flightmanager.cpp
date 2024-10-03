#include "flight.h"
#include <iostream>
#include <ranges>

void updateFlightDetails(Flight& flight) {
    std::string newDestination;
    int newDay;
    int newMonth;
    int newTime;
    std::string zero = "0";

    std::cout << "Введите новый пункт назначения:(0 для пропуска) ";
    std::cin >> newDestination;
    if (newDestination != zero) {
        flight.setDestination(newDestination);
    }

    std::cout << "Введите новый день отправки:(0 для пропуска) ";
    std::cin >> newDay;
    if (newDay != 0 && newDay <= 31) {
        flight.setDay(newDay);
    }

    std::cout << "Введите новый месяц отправки: (0 для пропуска) ";
    std::cin >> newMonth;
    if (newMonth != 0 && newMonth <= 12) {
        flight.setMonth(newMonth);
    }

    std::cout << "Введите новое время отправки: (0 для пропуска) ";
    std::cin >> newTime;
    if (newTime != 0 && newTime <= 24) {
        flight.setTime(newTime);
    }

    std::cout << "Данные о рейсе успешно изменены!" << std::endl;
}

void FlightManager::addFlight(int flightNumber, const std::string& destination, int day, int month, int time) {
    Flight newFlight(flightNumber, destination, day, month, time);
    flights.push_back(std::move(newFlight));
    std::cout << "Рейс успешно добавлен!" << std::endl;
}

void FlightManager::editFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            updateFlightDetails(flight);
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    auto it = std::find_if(flights.begin(), flights.end(),
        [flightNumber](const Flight& f) { return f.getFlightNumber() == flightNumber; });
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "Рейс удалён!" << std::endl;
    }
    else {
        std::cout << "Рейс с таким номером не найден!" << std::endl;
    }
}

void findFlightByNumber(const std::vector<Flight>& flights) {
    int flightNumber;
    std::cout << "Введите номер\n";
    std::cin >> flightNumber;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с таким номером не найден!" << std::endl;
    }
}

void findFlightByDestination(const std::vector<Flight>& flights) {
    std::string destination;
    std::cout << "Введите точку назначения\n";
    std::cin >> destination;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с таким пунктом назначения не найден!" << std::endl;
    }
}

void findFlightByDate(const std::vector<Flight>& flights) {
    int day;
    int month;
    std::cout << "Введите день: ";
    std::cin >> day;
    std::cout << "Введите месяц: ";
    std::cin >> month;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDay() == day && flight.getMonth() == month) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с такой датой не найден!" << std::endl;
    }
}

void FlightManager::findFlight() const {
    int choice = 0;
    do {
        std::cout << "1. Найти по номеру\n";
        std::cout << "2. Найти по точке назначения\n";
        std::cout << "3. Найти по дате\n";
        std::cout << "4. Закончить поиск\n";
        std::cout << "Ваш выбор: ";
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
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор, попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 4);
}

void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        std::cout << "Нет доступных рейсов." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            flight.printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
