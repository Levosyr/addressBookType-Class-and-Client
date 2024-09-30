#include "personType.h"

void personType::setName(const std::string& firstName, const std::string& lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

void personType::setBirthDate(int month, int day, int year) {
    birthDate.setDate(month, day, year);
}

void personType::setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip) {
    address.setAddress(street, city, state, zip);
}

void personType::setPhone(const std::string& phone) {
    this->phone = phone;
}

void personType::print() const {
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Birth Date: " << birthDate.getMonth() << "/" << birthDate.getDay() << "/" << birthDate.getYear() << std::endl;
    address.print();
    std::cout << "Phone: " << phone << std::endl;
}
