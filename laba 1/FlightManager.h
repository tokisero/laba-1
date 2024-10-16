#pragma once
#include "Flight.h"
#include <iostream>
#include <vector>
#include <ranges>
#include <fstream>

class FlightManager
{
private:
    std::vector<Flight> flights;
    const std::string filename = "flights.txt";
public:
    FlightManager();
    ~FlightManager();
    FlightManager(const FlightManager& other);
    FlightManager& operator=(const FlightManager& other);
    FlightManager(FlightManager&& other) noexcept;
    FlightManager& operator=(FlightManager&& other) noexcept;
    void addFlight(int flightNumber, const std::string& destination, int day, int month, int time);
    void editFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight() const;
    void listAllFlights() const;
    FlightManager& operator+=(const Flight& flight);
private:
    void readFromFile();
    void writeToFile() const;
};