#pragma once
#include <iostream>
#include <string>

class Flight
{
private:
    int flightNumber;
    std::string destination;
    int day;
    int month;
    int time;

public:
    Flight(int flightNumber, const std::string& destination, int day, int month, int time);
    ~Flight();

    // Копирующий конструктор
    Flight(const Flight& other);

    // Оператор копирующего присваивания
    Flight& operator=(const Flight& other);

    // Конструктор перемещения
    Flight(Flight&& other) noexcept;

    // Оператор перемещающего присваивания
    Flight& operator=(Flight&& other) noexcept;

    int getFlightNumber() const;
    const std::string& getDestination() const;
    int getDay() const;
    int getMonth() const;
    int getTime() const;
    void setDestination(std::string_view dest);
    void setDay(int d);
    void setMonth(int mnth);
    void setTime(int tm);
    bool operator==(const Flight& flight) const;

    friend std::ostream& operator<<(std::ostream& os, const Flight& flight) {
        os << "Flight number: " << flight.flightNumber << "\n"
            << "Destination: " << flight.destination << "\n"
            << "Date: " << flight.day << "." << flight.month << "\n"
            << "Time: " << flight.time << "\n\n";
        return os;
    }
};