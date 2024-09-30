#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include <iostream>
#include <string>
#include <fstream>

struct DateType {
    int day;
    int month;
    int year;
};

class extPersonType {
public:
    void print() const;
    bool read(std::istream& input);

    // Getters
    std::string getName() const { return name; }
    DateType getBirthDate() const { return birthDate; }
    std::string getRelationship() const { return relationship; }

private:
    std::string name;
    DateType birthDate;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;
    std::string relationship;
};

#endif // EXTPERSONTYPE_H
