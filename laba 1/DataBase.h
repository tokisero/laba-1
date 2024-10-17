#pragma once
#include "Flight.h"
#include <vector>
#include <string>

class DataBase {
private:
    std::string filename;
public:
    explicit DataBase(const std::string& file);
    const std::vector<Flight> readFromFile();
    void writeToFile(const std::vector<Flight>& flights) const;
};