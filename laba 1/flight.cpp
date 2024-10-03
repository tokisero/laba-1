#include "flight.h"
#include "flightmanager.h"
#include <iostream>
#include <string_view>

Flight::Flight(int flightNumber, const std::string& destination, int day, int month, int time)
    : flightNumber(flightNumber), destination(destination), day(day), month(month), time(time) {
}

int Flight::getFlightNumber() const {
    return flightNumber;
}

const std::string& Flight::getDestination() const {
    return destination;
}

int Flight::getDay() const {
    return day;
}

int Flight::getMonth() const {
    return month;
}

int Flight::getTime() const {
    return time;
}

void Flight::setDestination(std::string_view dest) {
    destination = dest;
}

void Flight::setMonth(const int mnth) {
    month = mnth;
}

void Flight::setDay(const int d) {
    day = d;
}

void Flight::setTime(const int tm) {
    time = tm;
}

void Flight::printFlight() const {
    std::cout << "Номер рейса: " << flightNumber << std::endl;
    std::cout << "Пункт назначения: " << destination << std::endl;
    std::cout << "Дата: " << day << "." << month << std::endl;
    std::cout << "Время: " << time << std::endl;
}
