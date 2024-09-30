#include <iostream>
#include <locale>
#include "Flight.h"

int main() {
    setlocale(LC_ALL, "RU");
    flightmanager manager;
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
            int flightnumber;
            std::string destination;
            int day;
            int month;
            int time;
            std::cout << "������� ����� �����\n";
            std::cin >> flightnumber;
            std::cout << "������� ����� ����������\n";
            std::cin >> destination;
            std::cout << "������� �����\n";
            std::cin >> month;
            std::cout << "������� ����\n";
            std::cin >> day;
            std::cout << "������� ����� ������\n";
            std::cin >> time;
            manager.addflight(flightnumber, destination, day, month, time);
            break;
        }
        case 2: {
            int flightnumber;
            std::cout << "������� ����� �����: ";
            std::cin >> flightnumber;
            manager.editflight(flightnumber);
            break;
        }
        case 3: {
            int flightnumber;
            std::cout << "������� ����� �����: ";
            std::cin >> flightnumber;
            manager.deleteflight(flightnumber);
            break;
        }
        case 4: {
            manager.findflight();
            break;
        }
        case 5: {
            manager.listallflights();
            break;
        }
        case 6:{
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