#include "extPersonType.h"

extPersonType::extPersonType()
    : personType("", "", dateType(), "", addressType()), relationship("") {}

extPersonType::extPersonType(const std::string& first, const std::string& last, const dateType& bDate, const std::string& phone, const addressType& addr, const std::string& relation)
    : personType(first, last, bDate, phone, addr), relationship(relation) {}

void extPersonType::print() const {
    personType::print();
    std::cout << "Relationship: " << relationship << std::endl;
}

bool extPersonType::operator==(const extPersonType& other) const {
    return (lastName + " " + firstName) == (other.lastName + " " + other.firstName);
}

bool extPersonType::operator!=(const extPersonType& other) const {
    return !(*this == other);
}

bool extPersonType::operator>=(const extPersonType& other) const {
    return (lastName + " " + firstName) >= (other.lastName + " " + other.firstName);
}
