#pragma once
#include <iostream>
#include <vector>

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
    int getFlightNumber() const;
    const std::string& getDestination() const;
    int getDay() const;
    int getMonth() const;
    int getTime() const;
    void setDestination(const std::string& dest);
    void setDay(int d);
    void setMonth(int mnth);
    void setTime(int tm);
    void printFlight() const;
};

class FlightManager
{
private:
    std::vector<Flight> flights;
public:
    void addFlight(int flightNumber, const std::string& destination, int day, int month, int time);
    void editFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight() const;
    void listAllFlights() const;
};
