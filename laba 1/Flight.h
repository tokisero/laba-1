#pragma once
#include <iostream>
#include <vector>
#include <string_view>

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
    int getFlightNumber() const;
    const std::string& getDestination() const;
    int getDay() const;
    int getMonth() const;
    int getTime() const;
    void setDestination(std::string_view dest);
    void setDay(int d);
    void setMonth(int mnth);
    void setTime(int tm);
    void printFlight() const;
};

