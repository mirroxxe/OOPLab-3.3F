// Date.h
#pragma once
#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);

    Date& operator=(const Date& other);
    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;

    friend std::istream& operator>>(std::istream& is, Date& date);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};