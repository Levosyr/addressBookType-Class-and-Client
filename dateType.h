#pragma once
#ifndef DATETYPE_H
#define DATETYPE_H

class dateType {
public:
    dateType(int month = 1, int day = 1, int year = 1900); // Constructor
    void setDate(int month, int day, int year); // Set the date
    int getMonth() const; // Get the month
    int getDay() const; // Get the day
    int getYear() const; // Get the year
    void print() const; // Print the date

private:
    int month;
    int day;
    int year;
};

#endif // DATETYPE_H
