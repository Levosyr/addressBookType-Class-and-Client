#include "personType.h"

personType::personType(const std::string& first, const std::string& last, const dateType& bDate, const std::string& phone, const addressType& addr)
    : firstName(first), lastName(last), birthDate(bDate), phone(phone), address(addr) {}

void personType::print() const {
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Birth Date: ";
    birthDate.print();
    std::cout << "Phone: " << phone << std::endl;
    address.print();
}
