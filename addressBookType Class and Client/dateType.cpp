#include "dateType.h"

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
