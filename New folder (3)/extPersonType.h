#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include <iostream>
#include <string>
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

class extPersonType : public personType
{
public:
    extPersonType() : birthDate() {} // Initialize birthDate to resolve the warning

    void print() const {
        std::cout << "Name: " << getName() << "\n"
            << "Birth Date: " << birthDate.getMonth() << "/" << birthDate.getDay() << "/" << birthDate.getYear() << "\n"
            << "Address: " << address.getStreet() << ", " << address.getCity() << ", " << address.getState() << " " << address.getZipCode() << "\n"
            << "Phone: " << phone << "\n"
            << "Relationship: " << relationship << "\n";
    }

    bool read(std::istream& input) {
        input >> firstName >> lastName;
        int month, day, year;
        input >> month >> day >> year;
        birthDate.setDate(month, day, year);
        std::string street, city, state, zip;
        input.ignore(); // ignore newline
        std::getline(input, street);
        std::getline(input, city);
        std::getline(input, state);
        std::getline(input, zip);
        address.setAddress(street, city, state, zip);
        std::getline(input, phone);
        std::getline(input, relationship);
        return !input.fail();
    }

    void setBirthDate(int month, int day, int year) {
        birthDate.setDate(month, day, year);
    }

    void setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip) {
        address.setAddress(street, city, state, zip);
    }

    void setPhone(const std::string& ph) {
        phone = ph;
    }

    void setRelationship(const std::string& rel) {
        relationship = rel;
    }

    dateType getBirthDate() const { return birthDate; }
    addressType getAddress() const { return address; }
    std::string getPhone() const { return phone; }
    std::string getRelationship() const { return relationship; }

    // Overload comparison operators for orderedLinkedList
    bool operator==(const extPersonType& other) const {
        return (lastName == other.lastName) && (firstName == other.firstName);
    }

    bool operator>=(const extPersonType& other) const {
        if (lastName > other.lastName) {
            return true;
        }
        else if (lastName == other.lastName) {
            return firstName >= other.firstName;
        }
        else {
            return false;
        }
    }

private:
    dateType birthDate;
    addressType address;
    std::string phone;
    std::string relationship;
};

#endif
