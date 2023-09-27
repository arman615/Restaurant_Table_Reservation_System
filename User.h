#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    std::string contactInfo;

public:
    User(const std::string &name, const std::string &contactInfo);

    const std::string &getName() const;
    const std::string &getContactInfo() const;
};

#endif // USER_H
