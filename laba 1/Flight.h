#pragma once
#include <iostream>
#include <string>

class Flight {
private:
    int flightNumber;
    std::string destination;
    int day;
    int month;
    int time;
    int seats;
    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
public:
    Flight(int flightNumber, const std::string& destination, int day, int month, int time, int seats);
    int getFlightNumber() const;
    const std::string& getDestination() const;
    int getDay() const;
    int getMonth() const;
    int getTime() const;
    int getSeats() const;
    void setDestination(std::string_view dest);
    void setDay(int d);
    void setMonth(int mnth);
    void setTime(int tm);
    void setSeats(int s);
    bool bookSeat();
    bool unbookSeat();
    bool operator==(const Flight& flight) const;
    
};