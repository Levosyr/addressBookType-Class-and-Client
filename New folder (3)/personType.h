#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

class personType {
public:
    void setName(const std::string& first, const std::string& last) {
        firstName = first;
        lastName = last;
    }

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getName() const { return lastName + " " + firstName; }

protected:
    std::string firstName;
    std::string lastName;
};

#endif