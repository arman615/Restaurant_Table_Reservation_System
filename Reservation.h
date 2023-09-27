#ifndef RESERVATION_H
#define RESERVATION_H

#include "Table.h"
#include "User.h"

class Reservation {
private:
    Table table;
    User user;

public:
    Reservation(const Table &table, const User &user);

    const Table &getTable() const;
    const User &getUser() const;
};

#endif // RESERVATION_H
