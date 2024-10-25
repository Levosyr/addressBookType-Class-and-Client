#ifndef DATETYPE_H
#define DATETYPE_H

class dateType {
public:
    void setDate(int month, int day, int year);
    int getMonth() const;
    int getDay() const;
    int getYear() const;

private:
    int month;
    int day;
    int year;
};

#endif
