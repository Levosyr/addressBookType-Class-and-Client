#include "dateType.h"
#include <iostream>

dateType::dateType(int month, int day, int year) : month(month), day(day), year(year) {}

void dateType::setDate(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
}

int dateType::getMonth() const {
    return month;
}

int dateType::getDay() const {
    return day;
}

int dateType::getYear() const {
    return year;
}

void dateType::print() const {
    std::cout << month << "/" << day << "/" << year << std::endl;
}
