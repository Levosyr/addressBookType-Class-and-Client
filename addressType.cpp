#include "addressType.h"
#include <iostream>

addressType::addressType(const std::string& street, const std::string& city, const std::string& state, const std::string& zip)
    : street(street), city(city), state(state), zipCode(zip) {}

void addressType::setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip) {
    this->street = street;
    this->city = city;
    this->state = state;
    this->zipCode = zip;
}

void addressType::print() const {
    std::cout << "Address: " << street << ", " << city << ", " << state << " " << zipCode << std::endl;
}
