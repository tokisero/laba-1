#include "Flight.h"
#include "FlightManager.h"
#include <iostream>
#include <string_view>

Flight::Flight(int flightNumber, const std::string& destination, int day, int month, int time)
    : flightNumber(flightNumber), destination(destination), day(day), month(month), time(time) {}

Flight::~Flight() {
    destination.clear();
}

// Копирующий конструктор
Flight::Flight(const Flight& other)
    : flightNumber(other.flightNumber), destination(other.destination), day(other.day), month(other.month), time(other.time) {
    std::cout << "Copy constructor called." << std::endl;
}

// Оператор копирующего присваивания
Flight& Flight::operator=(const Flight& other) {
    if (this != &other) {
        flightNumber = other.flightNumber;
        destination = other.destination;
        day = other.day;
        month = other.month;
        time = other.time;
        std::cout << "Copy assignment operator called." << std::endl;
    }
    return *this;
}

Flight::Flight(Flight&& other) noexcept
    : flightNumber(other.flightNumber), destination(std::move(other.destination)), day(other.day), month(other.month), time(other.time) {}

Flight& Flight::operator=(Flight&& other) noexcept {
    if (this != &other) {
        flightNumber = other.flightNumber;
        destination = std::move(other.destination);
        day = other.day;
        month = other.month;
        time = other.time;
    }
    return *this;
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


bool Flight:: operator == (const Flight& flight) const {
    return this->getFlightNumber() == flight.getFlightNumber();
}
