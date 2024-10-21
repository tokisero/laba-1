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
    explicit FlightManager(const std::string& filename = "flights.txt");
    ~FlightManager();
  
    FlightManager(const FlightManager& other) = delete; 
    FlightManager& operator=(const FlightManager& other) = delete; 
   
    void addFlight(int flightNumber, const std::string& destination, int day, int month, int time);
    void editFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight() const;
    void listAllFlights() const;
    FlightManager& operator+=(const Flight& flight);
};