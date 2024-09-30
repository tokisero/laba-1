#include "Flight.h"
#include <iostream>

void flightmanager::addflight(int flightnumber, const std::string& destination, int day, int month, int time) {
	flight flight(flightnumber, destination, day, month, time);
	flights.push_back(std::move(flight));
	std::cout << "Рейс успешно добавлен!" << std::endl;
}

void flightmanager::editflight(int flightnumber) {
	for (auto& flight : flights)
	{
		if (flight.getflightnumber() == flightnumber) {
			std::string newdestination;
			int newday;
			int newmonth;
			int newtime;
			std::string zero;
			zero = '0';
			std::cout << "Введите новый пункт назначения:(0 для пропуска)";
			std::cin >> newdestination;
			if (newdestination != zero) flight.setdestination(newdestination);
			std::cout << "Введите новый день отправки:(0 для пропуска)";
			std::cin >> newday;
			if (newday != 0 && newday <= 31) flight.setday(newday);
			std::cout << "Введите новый месяц оправки: (0 для пропуска)";
			std::cin >> newmonth;
			if (newmonth != 0 && newmonth <= 12) flight.setmonth(newmonth);
			std::cout << "Введите новое время отправки: (0 для пропуска)";
			std::cin >> newtime;
			if (newtime != 0 && newtime <= 24) flight.settime(newtime);
			std::cout << "Данные о рейсе успешно изменены!" << std::endl;
			return;
		}
		std::cout << "Рейс с таким номером не найден!" << std::endl;
	}
}

void flightmanager::deleteflight(int flightnumber) {
	for (auto it = flights.begin(); it != flights.end(); ++it)
	{
		if (it->getflightnumber() == flightnumber) {
			flights.erase(it);
			std::cout << "Рейс удалён!" << std::endl;
			return;
		}
	}
	std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void flightmanager::findflight() const {
	int choice = 0;
	std::string newdestination;
	int newflightnumber;
	int newday;
	int newmonth;
	int newtime;
	do {
		std::cout << "1. Найти по номеру\n";
		std::cout << "2. Найти по точке назначения\n";
		std::cout << "3. Найти по дате\n";
		std::cout << "4. Закончить поиск\n";
		std::cout << "Ваш выбор: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cout << "Введите номер\n";
			std::cin >> newflightnumber;
			for (const auto& flight : flights) {
				if (flight.getflightnumber() == newflightnumber) {
					flight.printflight();
					return;
				}
			}
			std::cout << "Рейс с таким номером не найден!" << std::endl;
			break;
		}
		case 2: {
			std::cout << "Введите точку назначения\n";
			std::cin >> newdestination;
			int i = 0;
			for (const auto& flight : flights) {
				if (flight.getdestination() == newdestination) {
					flight.printflight();
					i++;
				}
			}
			if (i == 0) std::cout << "Рейс с таким номером не найден!" << std::endl;
			break;
		}
		case 3: {
			std::cout << "Введите день: ";
			std::cin >> newday;
			std::cout << "Введите месяц: ";
			std::cin >> newmonth;
			int i = 0;
			for (const auto& flight : flights) {
				if (flight.getday() == newday && flight.getmonth() == newmonth) {
					flight.printflight();
					i++;
				}
			}
			if (i == 0) std::cout << "Рейс с таким номером не найден!" << std::endl;
			break;
		}
		case 4: {
			std::cout << "Выход из программы." << std::endl;
			break;
		}
		default: {
			std::cout << "Неверный выбор, попробуйте снова." << std::endl;
		}
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