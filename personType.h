#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include "dateType.h"
#include "addressType.h"

class personType {
public:
    personType(const std::string& first, const std::string& last, const dateType& bDate, const std::string& phone, const addressType& address);
    virtual void print() const;

    std::string getName() const { return firstName + " " + lastName; }
    dateType getBirthDate() const { return birthDate; }
    std::string getPhone() const { return phone; }

protected:
    std::string firstName;
    std::string lastName;
    dateType birthDate;
    addressType address;
    std::string phone;
};

#endif // PERSONTYPE_H
