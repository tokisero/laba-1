#pragma once
#include "Flight.h"
#include <vector>
#include <string>
#include <sqlite3.h>

class DataBase {
private:
    std::string filename;
    sqlite3* db;
    void open();
    void close();
public:
    explicit DataBase(const std::string& file);
    ~DataBase();
    std::vector<Flight> readFromFile() const;
    void writeToFile(const std::vector<Flight>& flights) const;
    void initialize();
    void addFlight(const Flight& flight) const;
    void editFlight(const Flight& flight) const;
    void deleteFlight(int flightNumber) const;
};