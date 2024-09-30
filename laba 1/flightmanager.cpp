#include "flight.h"
#include <iostream>
#include <ranges>

void updateFlightDetails(flight& flight) {
    std::string newdestination;
    int newday;
    int newmonth; 
    int newtime;
    std::string zero = "0";

    std::cout << "Введите новый пункт назначения:(0 для пропуска) ";
    std::cin >> newdestination;
    if (newdestination != zero) {
        flight.setdestination(newdestination);
    }

    std::cout << "Введите новый день отправки:(0 для пропуска) ";
    std::cin >> newday;
    if (newday != 0 && newday <= 31) {
        flight.setday(newday);
    }

    std::cout << "Введите новый месяц отправки: (0 для пропуска) ";
    std::cin >> newmonth;
    if (newmonth != 0 && newmonth <= 12) {
        flight.setmonth(newmonth);
    }

    std::cout << "Введите новое время отправки: (0 для пропуска) ";
    std::cin >> newtime;
    if (newtime != 0 && newtime <= 24) {
        flight.settime(newtime);
    }

    std::cout << "Данные о рейсе успешно изменены!" << std::endl;
}

void flightmanager::addflight(int flightnumber, const std::string& destination, int day, int month, int time) {
    flight newFlight(flightnumber, destination, day, month, time);
    flights.push_back(std::move(newFlight));
    std::cout << "Рейс успешно добавлен!" << std::endl;
}

void flightmanager::editflight(int flightnumber) {
    for (auto& flight : flights) {
        if (flight.getflightnumber() == flightnumber) {
            updateFlightDetails(flight);
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void flightmanager::deleteflight(int flightnumber) {
    auto it = std::find_if(flights.begin(), flights.end(),
        [flightnumber](const flight& f) { return f.getflightnumber() == flightnumber; });
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "Рейс удалён!" << std::endl;
    }
    else {
        std::cout << "Рейс с таким номером не найден!" << std::endl;
    }
}

void findFlightByNumber(const std::vector<flight>& flights) {
    int flightNumber;
    std::cout << "Введите номер\n";
    std::cin >> flightNumber;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getflightnumber() == flightNumber) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с таким номером не найден!" << std::endl;
    }
}

void findFlightByDestination(const std::vector<flight>& flights) {
    std::string destination;
    std::cout << "Введите точку назначения\n";
    std::cin >> destination;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getdestination() == destination) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с таким пунктом назначения не найден!" << std::endl;
    }
}

void findFlightByDate(const std::vector<flight>& flights) {
    int day; 
    int month;
    std::cout << "Введите день: ";
    std::cin >> day;
    std::cout << "Введите месяц: ";
    std::cin >> month;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getday() == day && flight.getmonth() == month) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Рейс с такой датой не найден!" << std::endl;
    }
}

void flightmanager::findflight() const {
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

void flightmanager::listallflights() const {
    if (flights.empty()) {
        std::cout << "Нет доступных рейсов." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            flight.printflight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
