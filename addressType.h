#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>

class addressType {
public:
    addressType(const std::string& street = "", const std::string& city = "", const std::string& state = "", const std::string& zip = "");
    void setAddress(const std::string& street, const std::string& city, const std::string& state, const std::string& zip);
    void print() const;

private:
    std::string street;
    std::string city;
    std::string state;
    std::string zipCode;
};

#endif // ADDRESSTYPE_H
#pragma once
