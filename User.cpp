#include "User.h"

User::User(const std::string &name, const std::string &contactInfo)
    : name(name), contactInfo(contactInfo) {}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getContactInfo() const {
    return contactInfo;
}
