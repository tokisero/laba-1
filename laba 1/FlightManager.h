#pragma once
#include "Flight.h"
#include "DataBase.h"
#include <vector>
#include <string>

class FlightManager {
private:
    std::vector<Flight> flights;
    DataBase db;

public:
    explicit FlightManager(const std::string& filename = "flight.db");
    ~FlightManager();

    void addFlight(int flightNumber, const std::string& destination, int day, int month, int time, int seats);
    void editFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight() const;
    void listAllFlights() const;
    bool bookFlight(int flightNumber);
    bool unbookFlight(int flightNumber);
    FlightManager& operator+=(const Flight& flight);
};