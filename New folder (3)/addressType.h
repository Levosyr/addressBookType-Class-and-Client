#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>

class addressType {
public:
    void setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip);
    void print() const;
    std::string getStreet() const { return street; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    std::string getZipCode() const { return zipCode; }

private:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
};

#endif
