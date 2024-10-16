#pragma once
#include "Flight.h"
#include <iostream>
#include <ranges>

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
    FlightManager& operator += (const Flight& flight);
};