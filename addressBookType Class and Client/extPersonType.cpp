#include "extPersonType.h"

void extPersonType::print() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Birth Date: " << birthDate.month << "/" << birthDate.day << "/" << birthDate.year << std::endl;
    std::cout << "Address: " << address << ", " << city << ", " << state << " " << zip << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}

bool extPersonType::read(std::istream& input) {
    if (std::getline(input, name) &&
        input >> birthDate.month >> birthDate.day >> birthDate.year &&
        input.ignore() && // Ignore the newline after the date
        std::getline(input, address) &&
        std::getline(input, city) &&
        std::getline(input, state) &&
        std::getline(input, zip) &&
        std::getline(input, phone) &&
        std::getline(input, relationship)) {
        return true; // Successfully read all fields
    }
    return false; // Failed to read
}
