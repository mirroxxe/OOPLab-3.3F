// Money.cpp
#include "Money.h"

Money::Money() : grivnas(0), kopiykas(0) {}

Money::Money(long grivnas, unsigned char kopiykas) : grivnas(grivnas), kopiykas(kopiykas) {}

Money::Money(const Money& other) : grivnas(other.grivnas), kopiykas(other.kopiykas) {}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        grivnas = other.grivnas;
        kopiykas = other.kopiykas;
    }
    return *this;
}

Money& Money::operator+=(const Money& other) {
    grivnas += other.grivnas;
    kopiykas += other.kopiykas;
    grivnas += kopiykas / 100;
    kopiykas %= 100;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    grivnas -= other.grivnas;
    int totalKopiykas = kopiykas - other.kopiykas;
    if (totalKopiykas < 0) {
        grivnas -= 1;
        kopiykas += 100;
    }
    kopiykas = totalKopiykas;
    return *this;
}

Money& Money::operator*=(double factor) {
    double totalAmount = grivnas + kopiykas / 100.0;
    totalAmount *= factor;
    grivnas = static_cast<long>(totalAmount);
    kopiykas = static_cast<int>((totalAmount - grivnas) * 100);
    return *this;
}

Money& Money::operator/=(double divisor) {
    double totalAmount = grivnas + kopiykas / 100.0;
    totalAmount /= divisor;
    grivnas = static_cast<long>(totalAmount);
    kopiykas = static_cast<int>((totalAmount - grivnas) * 100);
    return *this;
}

bool Money::operator==(const Money& other) const {
    return (grivnas == other.grivnas && kopiykas == other.kopiykas);
}

bool Money::operator<(const Money& other) const {
    return (grivnas < other.grivnas || (grivnas == other.grivnas && kopiykas < other.kopiykas));
}

Money Money::operator+(const Money& other) const {
    Money result(*this);
    result += other;
    return result;
}

Money Money::operator-(const Money& other) const {
    Money result(*this);
    result -= other;
    return result;
}

Money Money::operator*(double factor) const {
    Money result(*this);
    result *= factor;
    return result;
}

Money Money::operator/(double divisor) const {
    Money result(*this);
    result /= divisor;
    return result;
}

Money& Money::operator++() {
    *this += Money(1, 0);
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    *this -= Money(1, 0);
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    --(*this);
    return temp;
}

std::istream& operator>>(std::istream& is, Money& money)
{
    std::cout << "Enter money amount (grivnas kopiykas): ";
    is >> money.grivnas >> money.kopiykas;
    if (!is) {
        // Input error occurred
        is.setstate(std::ios::failbit);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& money)
{
    os << money.grivnas << ',' << static_cast<int>(money.kopiykas);
    return os;
}