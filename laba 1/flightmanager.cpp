#include "flight.h"
#include <iostream>
#include <ranges>

void updateFlightDetails(flight& flight) {
    std::string newdestination;
    int newday;
    int newmonth; 
    int newtime;
    std::string zero = "0";

    std::cout << "������� ����� ����� ����������:(0 ��� ��������) ";
    std::cin >> newdestination;
    if (newdestination != zero) {
        flight.setdestination(newdestination);
    }

    std::cout << "������� ����� ���� ��������:(0 ��� ��������) ";
    std::cin >> newday;
    if (newday != 0 && newday <= 31) {
        flight.setday(newday);
    }

    std::cout << "������� ����� ����� ��������: (0 ��� ��������) ";
    std::cin >> newmonth;
    if (newmonth != 0 && newmonth <= 12) {
        flight.setmonth(newmonth);
    }

    std::cout << "������� ����� ����� ��������: (0 ��� ��������) ";
    std::cin >> newtime;
    if (newtime != 0 && newtime <= 24) {
        flight.settime(newtime);
    }

    std::cout << "������ � ����� ������� ��������!" << std::endl;
}

void flightmanager::addflight(int flightnumber, const std::string& destination, int day, int month, int time) {
    flight newFlight(flightnumber, destination, day, month, time);
    flights.push_back(std::move(newFlight));
    std::cout << "���� ������� ��������!" << std::endl;
}

void flightmanager::editflight(int flightnumber) {
    for (auto& flight : flights) {
        if (flight.getflightnumber() == flightnumber) {
            updateFlightDetails(flight);
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void flightmanager::deleteflight(int flightnumber) {
    auto it = std::find_if(flights.begin(), flights.end(),
        [flightnumber](const flight& f) { return f.getflightnumber() == flightnumber; });
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "���� �����!" << std::endl;
    }
    else {
        std::cout << "���� � ����� ������� �� ������!" << std::endl;
    }
}

void findFlightByNumber(const std::vector<flight>& flights) {
    int flightNumber;
    std::cout << "������� �����\n";
    std::cin >> flightNumber;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getflightnumber() == flightNumber) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "���� � ����� ������� �� ������!" << std::endl;
    }
}

void findFlightByDestination(const std::vector<flight>& flights) {
    std::string destination;
    std::cout << "������� ����� ����������\n";
    std::cin >> destination;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getdestination() == destination) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "���� � ����� ������� ���������� �� ������!" << std::endl;
    }
}

void findFlightByDate(const std::vector<flight>& flights) {
    int day; 
    int month;
    std::cout << "������� ����: ";
    std::cin >> day;
    std::cout << "������� �����: ";
    std::cin >> month;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getday() == day && flight.getmonth() == month) {
            flight.printflight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "���� � ����� ����� �� ������!" << std::endl;
    }
}

void flightmanager::findflight() const {
    int choice = 0;
    do {
        std::cout << "1. ����� �� ������\n";
        std::cout << "2. ����� �� ����� ����������\n";
        std::cout << "3. ����� �� ����\n";
        std::cout << "4. ��������� �����\n";
        std::cout << "��� �����: ";
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
            std::cout << "����� �� ���������." << std::endl;
            break;
        default:
            std::cout << "�������� �����, ���������� �����." << std::endl;
            break;
        }
    } while (choice != 4);
}

void flightmanager::listallflights() const {
    if (flights.empty()) {
        std::cout << "��� ��������� ������." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            flight.printflight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
