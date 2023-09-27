#include "Reservation.h"

Reservation::Reservation(const Table &table, const User &user)
    : table(table), user(user) {}

const Table &Reservation::getTable() const {
    return table;
}

const User &Reservation::getUser() const {
    return user;
}
