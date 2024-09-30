#include "addressBookType.h"

void addressBookType::loadData(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    extPersonType person;
    while (person.read(inputFile)) {
        entries.push_back(person);
    }
    inputFile.close();
}

void addressBookType::displayAllEntries() const {
    for (const auto& entry : entries) {
        entry.print();
    }
}

void addressBookType::displayEntryByName(const std::string& name) const {
    for (const auto& entry : entries) {
        if (entry.getName() == name) {
            entry.print();
            return;
        }
    }
    std::cout << "No entry found for name: " << name << std::endl;
}

void addressBookType::displayEntriesByMonth(int month) const {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getBirthDate().month == month) {
            entry.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found for month: " << month << std::endl;
    }
}

void addressBookType::displayEntriesByRelationship(const std::string& relationship) const {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.getRelationship() == relationship) {
            entry.print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries found for relationship: " << relationship << std::endl;
    }
}
