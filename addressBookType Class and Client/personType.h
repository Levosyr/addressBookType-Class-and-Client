#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include "dateType.h"
#include "addressType.h"

class personType {
public:
    void setName(const std::string& firstName, const std::string& lastName);
    void setBirthDate(int month, int day, int year);
    void setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip);
    void setPhone(const std::string& phone);
    virtual void print() const;

protected:
    std::string firstName;
    std::string lastName;
    dateType birthDate;
    addressType address;
    std::string phone;
};

#endif // PERSONTYPE_H
#pragma once
