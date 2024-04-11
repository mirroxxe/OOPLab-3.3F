#pragma once
#include <iostream>
#include <string>
#include "Money.h"
#include "Date.h"

class Goods : public Money, private Date {
protected:
    std::string name;
    Date date;
    Money price;
    int quantity;
    int invoiceNumber;

public:
    Goods();
    Goods(const std::string& name, const Date& date, const Money& price, int quantity, int invoiceNumber);
    Goods(const Goods& other);

    Goods& operator=(const Goods& other);

    void changePrice(const Money& newPrice);
    void changeQuantity(int newQuantity);
    Money calculateTotalCost() const;

    friend std::istream& operator>>(std::istream& is, Goods& goods);
    friend std::ostream& operator<<(std::ostream& os, const Goods& goods);
};