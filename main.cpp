#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Table.h"
#include "User.h"
#include "Reservation.h"

void tableRegister(std::vector<Table> &tables, int tableNumber, int seatingCapacity) {
    Table newTable(tableNumber, seatingCapacity);
    tables.push_back(newTable);
    std::cout << "Table registered successfully.\n";
}

void userRegister(std::vector<User> users, const std::string &name, const std::string &contactInfo) {
    User newUser(name, contactInfo);
    users.push_back(newUser);
    std::cout << "User registered successfully.\n";
}

bool isTableAvailable(const Table &table) {
    return table.getStatus() == "Available";
}

void bookTable(std::vector<Table>& tables, std::vector<User>& users, std::vector<Reservation>& reservations,
               int seatingCapacity, const std::string& userName, const std::string& userContactInfo) {
    std::vector<Table> availableTables;
    for (const Table& table : tables) {
        if (table.getSeatingCapacity() == seatingCapacity && isTableAvailable(table)) {
            availableTables.push_back(table);
        }
    }
    if (availableTables.empty()) {
        std::cout << "No available tables with seating capacity " << seatingCapacity << " found\n";
        return;
    }
    std::cout << "Available tables with seating capacity " << seatingCapacity << ":\n";
    for (const Table& table : availableTables) {
        std::cout << "Table " << table.getTableNumber() << std::endl;
    }

    int selectedTableNumber;
    while (true) {
        std::cout << "Enter the table number to book: ";
        std::cin >> selectedTableNumber;

        bool validTable = false;
        for (const Table& table : availableTables) {
            if (table.getTableNumber() == selectedTableNumber) {
                validTable = true;
                break;
            }
        }

        if (validTable) {
            break;
        } else {
            std::cout << "Invalid table number. Please try again.\n";
        }
    }

    Table* selectedTablePtr = nullptr;
    for (Table& table : tables) {
        if (table.getTableNumber() == selectedTableNumber && isTableAvailable(table)) {
            selectedTablePtr = &table;
            break;
        }
    }
    if (selectedTablePtr == nullptr) {
        std::cout << "Invalid table selection or the table is already booked.\n";
        return;
    }

    User newUser(userName, userContactInfo);
    users.push_back(newUser);

    Reservation newReservation(*selectedTablePtr, newUser);
    reservations.push_back(newReservation);

    selectedTablePtr->setStatus("Booked");
    std::cout << "Table booked successfully!\n";
}

void generateReport(const std::vector<Reservation>& reservations){
    std::cout<<"Report\n";
    for(const Reservation& reservation: reservations){
        std::cout<<"Table number: "<<reservation.getTable().getTableNumber()<<std::endl;
        std::cout<<"Seating capacity: "<<reservation.getTable().getSeatingCapacity()<<std::endl;
        std::cout<<"User name: "<<reservation.getUser().getName()<<std::endl;
        std::cout<<"User contact information: "<<reservation.getUser().getContactInfo()<<std::endl;
        std::cout<<"---------------------------------";
    }
}
void saveReportToFile(std::vector<Reservation> reservations){
   std::ofstream filename("report.txt");
   if(filename.is_open()){
       filename<<"Report\n";
       for(const Reservation& reservation:reservations){
           filename<<"Table number: "<<reservation.getTable().getTableNumber()<<std::endl;
           filename<<"Seating capacity: "<<reservation.getTable().getSeatingCapacity()<<std::endl;
           filename<<"User name: "<<reservation.getUser().getName()<<std::endl;
           filename<<"User contact information: "<<reservation.getUser().getContactInfo()<<std::endl;
           filename<<"---------------------------------";
       }
       filename.close();
       std::cout<<"Report is saved to file successfully.\n";
   }
   else{
       std::cout<<"Unable to save report to file.\n";
   }
}

int main() {
    std::vector<Table> tables;
    std::vector<User> users;
    std::vector<Reservation> reservations;
    tableRegister(tables,1,4);
    tableRegister(tables,2,4);
    tableRegister(tables,3,6);
    tableRegister(tables,4,2);

    userRegister(users,"Arman","arman@gmail.com");
    userRegister(users,"Abo","abo@gmail.com");

    bookTable(tables,users,reservations,4,"Arman","arman@gmail.com");
    bookTable(tables,users,reservations,2,"Abo","abo@gmail.com");

    generateReport(reservations);
    saveReportToFile(reservations);
}
