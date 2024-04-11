#include "Goods.h"
#include <iostream>

Goods::Goods() : name(""), date(), price(), quantity(0), invoiceNumber(0) {}

Goods::Goods(const std::string& name, const Date& date, const Money& price, int quantity, int invoiceNumber)
    : name(name), date(date), price(price), quantity(quantity), invoiceNumber(invoiceNumber) {}

Goods::Goods(const Goods& other)
    : name(other.name), date(other.date), price(other.price), quantity(other.quantity), invoiceNumber(other.invoiceNumber) {}

Goods& Goods::operator=(const Goods& other) {
    if (this != &other) {
        name = other.name;
        date = other.date;
        price = other.price;
        quantity = other.quantity;
        invoiceNumber = other.invoiceNumber;
    }
    return *this;
}

void Goods::changePrice(const Money& newPrice) {
    price = newPrice;
}

void Goods::changeQuantity(int newQuantity) {
    quantity = newQuantity;
}

Money Goods::calculateTotalCost() const {
    return price * quantity;
}

std::istream& operator>>(std::istream& is, Goods& goods)
{
    std::cout << "Enter details for Product:" << std::endl;

    std::cout << "Date: ";
    is >> goods.date;
    if (!is) {
        is.setstate(std::ios::failbit);
        return is;
    }

    std::cout << "Name: ";
    std::getline(is >> std::ws, goods.name); 

    std::cout << "Price (grivnas kopiykas): ";
    is >> goods.price;
    if (!is) {
        is.setstate(std::ios::failbit);
        return is;
    }

    std::cout << "Quantity: ";
    is >> goods.quantity;
    if (!is) {
        is.setstate(std::ios::failbit);
        return is;
    }

    std::cout << "Invoice Number: ";
    is >> goods.invoiceNumber;
    if (!is) {
        is.setstate(std::ios::failbit);
        return is;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Goods& goods)
{
    os << "Date: " << goods.date << ", Name: " << goods.name << ", Price: " << goods.price
        << ", Quantity: " << goods.quantity << ", Invoice Number: " << goods.invoiceNumber;
    return os;
}