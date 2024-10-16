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

    // Копирующий конструктор
    FlightManager(const FlightManager& other);

    // Оператор копирующего присваивания
    FlightManager& operator=(const FlightManager& other);

    // Конструктор перемещения и оператор перемещающего присваивания
    FlightManager(FlightManager&& other) noexcept = default;
    FlightManager& operator=(FlightManager&& other) noexcept = default;

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