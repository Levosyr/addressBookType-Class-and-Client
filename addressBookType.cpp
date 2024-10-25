#include "addressBookType.h"
#include <fstream>
#include <iostream>

addressBookType::addressBookType() {}

void addressBookType::initEntry(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string firstName, lastName, street, city, state, zip, phone, relationship;
    int month, day, year;
    while (inputFile >> firstName >> lastName >> month >> day >> year >> street >> city >> state >> zip >> phone >> relationship) {
        dateType birthDate(month, day, year);
        addressType address(street, city, state, zip);
        extPersonType person(firstName, lastName, birthDate, phone, address, relationship);
        this->insert(person);  // Use linked list insert
    }
}

void addressBookType::findPerson(const std::string& firstName, const std::string& lastName) const {
    std::string key = lastName + " " + firstName;
    bool found = false;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if ((*it).getName() == key) {
            (*it).print();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No entry found for: " << key << std::endl;
    }
}

void addressBookType::findBirthdays(int month) const {
    bool found = false;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if ((*it).getBirthDate().getMonth() == month) {
            (*it).print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found with birthdays in month: " << month << std::endl;
    }
}

void addressBookType::findRelations(const std::string& relationship) const {
    bool found = false;
    for (auto it = this->begin(); it != this->end(); ++it) {
        if ((*it).getRelationship() == relationship) {
            (*it).print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found with relationship: " << relationship << std::endl;
    }
}

void addressBookType::print() const {
    for (auto it = this->begin(); it != this->end(); ++it) {
        (*it).print();
        std::cout << std::endl;
    }
}
