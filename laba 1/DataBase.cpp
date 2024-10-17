#include "DataBase.h"
#include <iostream>
#include <fstream>

DataBase::DataBase(const std::string& file) : filename(file) {}

 std::vector<Flight> DataBase::readFromFile() const {
    std::vector<Flight> flights;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Файл не найден. Создание нового." << std::endl;
        std::ofstream newFile(filename);
        newFile.close();
        return flights;
    }
    int flightNumber;
    int day;
    int month;
    int time;
    std::string destination;
    while (file >> flightNumber >> destination >> day >> month >> time) {
        flights.emplace_back(flightNumber, destination, day, month, time);
    }
    file.close();
    return flights;
}

void DataBase::writeToFile(const std::vector<Flight>& flights) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    for (const auto& flight : flights) {
        file << flight.getFlightNumber() << " "
            << flight.getDestination() << " "
            << flight.getDay() << " "
            << flight.getMonth() << " "
            << flight.getTime() << "\n";
    }
    file.close();
}