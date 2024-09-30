#pragma once
#include <iostream>
#include <vector>

class flight
{
private:
	int flightnumber;
	std::string destination;
	int day;
	int month;
	int time;
public:
	flight(int flightnumber,const std::string& destination, int day, int month, int time);
	int getflightnumber() const;
	const std::string& getdestination() const;
	int getday() const;
	int getmonth() const;
	int gettime() const;
	void setdestination(const std::string& dest);
	void setday(int d);
	void setmonth(int mnth);
	void settime(int tm);
	void printflight() const;
};

class flightmanager
{
private:
	std::vector<flight> flights;
public:
	void addflight(int flightnumber, const std::string& destination, int day, int month, int time);
	void editflight(int flightnubmbr);
	void deleteflight(int flightnumber);
	void findflight() const;
	void listallflights() const;
};

