//
//  Product.h
//  Annual_Lab
//
//  Created by Afaq Ahmed on 15/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#ifndef Product_h
#define Product_h
#include <iostream>
using namespace std;

class Product{
    int productID;
    double price;
    string name;
    static bool writingFirstTime;
public:
    Product();
    void getData();
    void show();
    int getProductID();
    void setProductID(int);
    bool getWritingStatus();
    void setWritingStatus(bool);
};

bool Product::writingFirstTime = true;

Product::Product()
:productID(0), price(0), name("") {  }

void Product::getData(){
    cout << "\nEnter Product Price: "; cin >> price;
    cout << "Enter Product Name: "; cin >> name;
}

void Product::show(){
    cout << "\nProduct ID: " << productID << "\t"
    << "Price: " << price << "\t"
    << "Name: " << name;
}

int Product::getProductID() {
    return productID;
}

void Product::setProductID(int id) {
    productID = id;
}

bool Product::getWritingStatus() {
    return writingFirstTime;
}

void Product::setWritingStatus(bool status) {
    writingFirstTime = status;
}

#endif /* Product_h */
