// Money.h
#pragma once
#include <iostream>

class Money {
protected:
    long grivnas;
    unsigned char kopiykas;

public:
    Money();
    Money(long grivnas, unsigned char kopiykas);
    Money(const Money& other);

    Money& operator=(const Money& other);
    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    Money& operator*=(double factor);
    Money& operator/=(double divisor);

    bool operator==(const Money& other) const;
    bool operator<(const Money& other) const;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(double factor) const;
    Money operator/(double divisor) const;

    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    friend std::istream& operator>>(std::istream& is, Money& money);
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
};