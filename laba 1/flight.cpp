#include "flight.h"
#include <iostream>


flight::flight(int flightnubmer, const std::string& destination, int day, int month, int time)
	: flightnumber(flightnubmer), destination(destination), day(day), month(month), time(time) {
}
int flight::getflightnumber() const {
	return flightnumber;
 }
const std::string& flight::getdestination() const {
	return destination;
}
int flight::getday() const {
	return day;
}
int flight::getmonth() const {
	return month;
}
int flight::gettime() const {
	return time;
}
void flight::setdestination(const std::string& dest) {
	destination = dest;
}
void flight::setmonth(const int mnth) {
	month = mnth;
}
void flight::setday(const int d) {
	day = d;
}
void flight::settime(const int tm) {
	time = tm;
}
void flight::printflight() const {
	std::cout << "Номер рейса: " << flightnumber << std::endl;
	std::cout << "Пункт назначения: " << destination << std::endl;
	std::cout << "Дата: " << day;
	std::cout << ".";
	std::cout << month << std::endl;
	std::cout << "Время: " << time << std::endl;
}





