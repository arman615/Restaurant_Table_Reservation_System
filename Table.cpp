#include "Table.h"

Table::Table(int tableNumber, int seatingCapacity)
    : tableNumber(tableNumber), seatingCapacity(seatingCapacity), status("Available") {}

int Table::getTableNumber() const {
    return tableNumber;
}

int Table::getSeatingCapacity() const {
    return seatingCapacity;
}

const std::string &Table::getStatus() const {
    return status;
}

void Table::setStatus(const std::string &status) {
    this->status = status;
}
