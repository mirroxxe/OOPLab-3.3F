#include <iostream>
#include "Goods.h"

using namespace std;

int main() {
    string name1, name2;
    Date date1, date2;
    Money price1, price2;
    int quantity1, quantity2, invoiceNumber1, invoiceNumber2;

    cout << "Enter details for Product 1:" << endl;
    cout << "Name: ";
    cin >> name1;
    cout << "Date (dd mm yyyy): ";
    cin >> date1;
    cout << "Price (grivnas kopiykas): ";
    cin >> price1;
    cout << "Quantity: ";
    cin >> quantity1;
    cout << "Invoice Number: ";
    cin >> invoiceNumber1;

    cout << endl << "Enter details for Product 2:" << endl;
    cout << "Name: ";
    cin >> name2;
    cout << "Date (dd mm yyyy): ";
    cin >> date2;
    cout << "Price (grivnas kopiykas): ";
    cin >> price2;
    cout << "Quantity: ";
    cin >> quantity2;
    cout << "Invoice Number: ";
    cin >> invoiceNumber2;

    Goods product1(name1, date1, price1, quantity1, invoiceNumber1);
    Goods product2(name2, date2, price2, quantity2, invoiceNumber2);

    cout << endl << "Product 1 details: " << product1 << endl;
    cout << "Product 2 details: " << product2 << endl;

    Money totalCost = product1.calculateTotalCost() + product2.calculateTotalCost();
    cout << "Total cost of products: " << totalCost << endl;

    return 0;
}
