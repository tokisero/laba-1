#include "Flight.h"
#include "FlightManager.h"
#include <iostream>
#include <ranges>

void updateFlightDetails(Flight& flight) {
    std::string newDestination;
    int newDay;
    int newMonth;
    int newTime;
    std::string zero = "0";

    std::cout << "Ââåäèòå íîâûé ïóíêò íàçíà÷åíèÿ:(0 äëÿ ïðîïóñêà) ";
    std::cin >> newDestination;
    if (newDestination != zero) {
        flight.setDestination(newDestination);
    }

    std::cout << "Ââåäèòå íîâûé äåíü îòïðàâêè:(0 äëÿ ïðîïóñêà) ";
    std::cin >> newDay;
    if (newDay != 0 && newDay <= 31) {
        flight.setDay(newDay);
    }

    std::cout << "Ââåäèòå íîâûé ìåñÿö îòïðàâêè: (0 äëÿ ïðîïóñêà) ";
    std::cin >> newMonth;
    if (newMonth != 0 && newMonth <= 12) {
        flight.setMonth(newMonth);
    }

    std::cout << "Ââåäèòå íîâîå âðåìÿ îòïðàâêè: (0 äëÿ ïðîïóñêà) ";
    std::cin >> newTime;
    if (newTime != 0 && newTime <= 24) {
        flight.setTime(newTime);
    }

    std::cout << "Äàííûå î ðåéñå óñïåøíî èçìåíåíû!" << std::endl;
}

void FlightManager::addFlight(int flightNumber, const std::string& destination, int day, int month, int time) {
    Flight newFlight(flightNumber, destination, day, month, time);
    flights.push_back(std::move(newFlight));
    std::cout << "Ðåéñ óñïåøíî äîáàâëåí!" << std::endl;
}

void FlightManager::editFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            updateFlightDetails(flight);
            return;
        }
    }
    std::cout << "Ðåéñ ñ òàêèì íîìåðîì íå íàéäåí!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    auto it = std::ranges::find_if(flights, [flightNumber](const Flight& f) {return f.getFlightNumber() == flightNumber; });
    if (it != flights.end()) {
        flights.erase(it);
        std::cout << "Ðåéñ óäàë¸í!" << std::endl;
    }
    else {
        std::cout << "Ðåéñ ñ òàêèì íîìåðîì íå íàéäåí!" << std::endl;
    }
}

void findFlightByNumber(const std::vector<Flight>& flights) {
    int flightNumber;
    std::cout << "Ââåäèòå íîìåð\n";
    std::cin >> flightNumber;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Ðåéñ ñ òàêèì íîìåðîì íå íàéäåí!" << std::endl;
    }
}

void findFlightByDestination(const std::vector<Flight>& flights) {
    std::string destination;
    std::cout << "Ââåäèòå òî÷êó íàçíà÷åíèÿ\n";
    std::cin >> destination;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDestination() == destination) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Ðåéñ ñ òàêèì ïóíêòîì íàçíà÷åíèÿ íå íàéäåí!" << std::endl;
    }
}

void findFlightByDate(const std::vector<Flight>& flights) {
    int day;
    int month;
    std::cout << "Ââåäèòå äåíü: ";
    std::cin >> day;
    std::cout << "Ââåäèòå ìåñÿö: ";
    std::cin >> month;

    bool found = false;
    for (const auto& flight : flights) {
        if (flight.getDay() == day && flight.getMonth() == month) {
            flight.printFlight();
            found = true;
        }
    }
    if (!found) {
        std::cout << "Ðåéñ ñ òàêîé äàòîé íå íàéäåí!" << std::endl;
    }
}

void FlightManager::findFlight() const {
    int choice = 0;
    do {
        std::cout << "1. Íàéòè ïî íîìåðó\n";
        std::cout << "2. Íàéòè ïî òî÷êå íàçíà÷åíèÿ\n";
        std::cout << "3. Íàéòè ïî äàòå\n";
        std::cout << "4. Çàêîí÷èòü ïîèñê\n";
        std::cout << "Âàø âûáîð: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            findFlightByNumber(flights);
            break;
        case 2:
            findFlightByDestination(flights);
            break;
        case 3:
            findFlightByDate(flights);
            break;
        case 4:
            std::cout << "Âûõîä èç ïðîãðàììû." << std::endl;
            break;
        default:
            std::cout << "Íåâåðíûé âûáîð, ïîïðîáóéòå ñíîâà." << std::endl;
            break;
        }
    } while (choice != 4);
}

void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        std::cout << "Íåò äîñòóïíûõ ðåéñîâ." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            flight.printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
