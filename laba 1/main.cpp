#include <iostream>
#include <locale>
#include "Flight.h"

int main() {
    setlocale(LC_ALL, "RU");
    flightmanager manager;
    int choice = 0;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить рейс\n";
        std::cout << "2. Изменить данные о рейсе\n";
        std::cout << "3. Снять рейс\n";
        std::cout << "4. Найти рейс\n";
        std::cout << "5. Вывести все рейсы\n";
        std::cout << "6. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int flightnumber;
            std::string destination;
            int day;
            int month;
            int time;
            std::cout << "Введите номер рейса\n";
            std::cin >> flightnumber;
            std::cout << "Введите место назначения\n";
            std::cin >> destination;
            std::cout << "Введите месяц\n";
            std::cin >> month;
            std::cout << "Введите день\n";
            std::cin >> day;
            std::cout << "Введите время вылета\n";
            std::cin >> time;
            manager.addflight(flightnumber, destination, day, month, time);
            break;
        }
        case 2: {
            int flightnumber;
            std::cout << "Введите номер рейса: ";
            std::cin >> flightnumber;
            manager.editflight(flightnumber);
            break;
        }
        case 3: {
            int flightnumber;
            std::cout << "Введите номер рейса: ";
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
            std::cout << "Выход из программы." << std::endl;
            break;
        }
        default: {
            std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }
        }
    } while (choice != 6);
    return 0;
}