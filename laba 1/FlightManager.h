#pragma once
#include "Flight.h"
#include <iostream>
#include <ranges>
#include <memory>

class FlightManager
{
private:
    //std::vector<std::unique_ptr<Flight>> flights;
    std::vector<Flight> flights;
public:
    void addFlight(int flightNumber, const std::string& destination, int day, int month, int time);
    void editFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight() const;
    void listAllFlights() const;
    FlightManager& operator += (const Flight& flight);
};