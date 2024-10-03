#include <iostream>
#include <locale>
#include "flightmanager.h"
#include "flight.h"

int main() {
    setlocale(LC_ALL, "RU");
    FlightManager manager;
    int choice = 0;
    do {
        std::cout << "����:\n";
        std::cout << "1. �������� ����\n";
        std::cout << "2. �������� ������ � �����\n";
        std::cout << "3. ����� ����\n";
        std::cout << "4. ����� ����\n";
        std::cout << "5. ������� ��� �����\n";
        std::cout << "6. �����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int flightNumber;
            std::string destination;
            int day;
            int month;
            int time;
            std::cout << "������� ����� �����\n";
            std::cin >> flightNumber;
            std::cout << "������� ����� ����������\n";
            std::cin >> destination;
            std::cout << "������� �����\n";
            std::cin >> month;
            std::cout << "������� ����\n";
            std::cin >> day;
            std::cout << "������� ����� ������\n";
            std::cin >> time;
            manager.addFlight(flightNumber, destination, day, month, time);
            break;
        }
        case 2: {
            int flightNumber;
            std::cout << "������� ����� �����: ";
            std::cin >> flightNumber;
            manager.editFlight(flightNumber);
            break;
        }
        case 3: {
            int flightNumber;
            std::cout << "������� ����� �����: ";
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
            std::cout << "����� �� ���������." << std::endl;
            break;
        }
        default: {
            std::cout << "�������� �����, ���������� �����." << std::endl;
        }
        }
    } while (choice != 6);
    return 0;
}
