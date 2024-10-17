#pragma once
#include "Flight.h"
#include <vector>
#include <string>

class DataBase {
private:
    std::string filename;
public:
    explicit DataBase(const std::string& file);
    std::vector<Flight> readFromFile() const;
    void writeToFile(const std::vector<Flight>& flights) const;
};