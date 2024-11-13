#include "DataBase.h"
#include <iostream>
#include <sqlite3.h>

DataBase::DataBase(const std::string& file) : filename(file) {
    open();
    initialize();
}

DataBase::~DataBase() {
    close();
}

void DataBase::initialize() {
    const char* sql_create_table = R"(
        CREATE TABLE IF NOT EXISTS Flights (
            flightNumber INTEGER PRIMARY KEY,
            destination TEXT NOT NULL,
            day INTEGER NOT NULL,
            month INTEGER NOT NULL,
            time INTEGER NOT NULL,
            seats INTEGER NOT NULL
        );
    )";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql_create_table, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Error creating Flights table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void DataBase::open() {
    if (sqlite3_open(filename.c_str(), &db)) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
    }
    else {
        char* errMsg = nullptr;

        const char* sql_check = "PRAGMA table_info(Flights);";
        sqlite3_stmt* stmt;
        bool seatsColumnExists = false;

        if (sqlite3_prepare_v2(db, sql_check, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                const char* column_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                if (std::string(column_name) == "seats") {
                    seatsColumnExists = true;
                    break;
                }
            }
            sqlite3_finalize(stmt);
        }
        if (!seatsColumnExists) {
            const char* sql_add_column = "ALTER TABLE Flights ADD COLUMN seats INTEGER;";
            if (sqlite3_exec(db, sql_add_column, nullptr, nullptr, &errMsg) != SQLITE_OK) {
                std::cerr << "SQL error during ALTER: " << errMsg << std::endl;
                sqlite3_free(errMsg);
            }
            else {
                std::cout << "Column 'seats' successfully added!" << std::endl;
            }
        }
    }
}


void DataBase::close() {
    if (db) {
        sqlite3_close(db);
    }
}

std::vector<Flight> DataBase::readFromFile() const {
    std::vector<Flight> flights;
    const char* sql = "SELECT flightNumber, destination, day, month, time, seats FROM Flights;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int flightNumber = sqlite3_column_int(stmt, 0);
            std::string destination = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            int day = sqlite3_column_int(stmt, 2);
            int month = sqlite3_column_int(stmt, 3);
            int time = sqlite3_column_int(stmt, 4);
            int seats = sqlite3_column_int(stmt, 5);
            flights.emplace_back(flightNumber, destination, day, month, time, seats);
        }
        sqlite3_finalize(stmt);
    }
    else {
        std::cerr << "Failed to read from database: " << sqlite3_errmsg(db) << std::endl;
    }

    return flights;
}

void DataBase::writeToFile(const std::vector<Flight>& flights) const {
    const char* sql = "INSERT OR REPLACE INTO Flights (flightNumber, destination, day, month, time, seats) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    for (const auto& flight : flights) {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
            sqlite3_bind_int(stmt, 1, flight.getFlightNumber());
            sqlite3_bind_text(stmt, 2, flight.getDestination().c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, flight.getDay());
            sqlite3_bind_int(stmt, 4, flight.getMonth());
            sqlite3_bind_int(stmt, 5, flight.getTime());
            sqlite3_bind_int(stmt, 6, flight.getSeats());

            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "SQL error during insert/update: " << sqlite3_errmsg(db) << std::endl;
            }

            sqlite3_finalize(stmt);
        }
        else {
            std::cerr << "Failed to prepare insert query: " << sqlite3_errmsg(db) << std::endl;
        }
    }
}

void DataBase::addFlight(const Flight& flight) const {
    const char* sql = "INSERT INTO Flights (flightNumber, destination, day, month, time, seats) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, flight.getFlightNumber());
        sqlite3_bind_text(stmt, 2, flight.getDestination().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, flight.getDay());
        sqlite3_bind_int(stmt, 4, flight.getMonth());
        sqlite3_bind_int(stmt, 5, flight.getTime());
        sqlite3_bind_int(stmt, 6, flight.getSeats());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "SQL error during flight insert: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    else {
        std::cerr << "Failed to prepare add flight query: " << sqlite3_errmsg(db) << std::endl;
    }
}

void DataBase::editFlight(const Flight& flight) const {
    const char* sql = "UPDATE Flights SET destination = ?, day = ?, month = ?, time = ?, seats = ? WHERE flightNumber = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, flight.getDestination().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, flight.getDay());
        sqlite3_bind_int(stmt, 3, flight.getMonth());
        sqlite3_bind_int(stmt, 4, flight.getTime());
        sqlite3_bind_int(stmt, 5, flight.getSeats());
        sqlite3_bind_int(stmt, 6, flight.getFlightNumber());

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "SQL error during flight update: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    else {
        std::cerr << "Failed to prepare update query: " << sqlite3_errmsg(db) << std::endl;
    }
}

void DataBase::deleteFlight(int flightNumber) const {
    const char* sql = "DELETE FROM Flights WHERE flightNumber = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, flightNumber);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "SQL error during delete: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
    }
    else {
        std::cerr << "Failed to prepare delete query: " << sqlite3_errmsg(db) << std::endl;
    }
}
