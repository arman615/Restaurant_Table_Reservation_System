#ifndef TABLE_H
#define TABLE_H

#include <string>

class Table {
private:
    int tableNumber;
    int seatingCapacity;
    std::string status;

public:
    Table(int tableNumber, int seatingCapacity);

    int getTableNumber() const;
    int getSeatingCapacity() const;
    const std::string &getStatus() const;
    void setStatus(const std::string &status);
};

#endif // TABLE_H
