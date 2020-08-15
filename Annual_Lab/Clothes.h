//
//  Clothes.h
//  Annual_Lab
//
//  Created by Afaq Ahmed on 15/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#ifndef Clothes_h
#define Clothes_h
#include <fstream>
#include <iostream>
#include "Product.h"
using namespace std;


class Clothes : public Product {
    string color;
public:
    Clothes();
    void getData();
    void show();
    void storeData();
    void readData();
    void deleteData();
    void updateData();
    void searchData();
};

Clothes::Clothes()
:color("") {    }

void Clothes::getData(){
    Product::getData();
    cout << "Enter Color: "; cin >> color;
}

void Clothes::show(){
    Product::show();
    cout << "\t" << "Color: " << color;
}

void Clothes::storeData() {
    fstream file;
    int localProductID;
    bool flag = true;
    
    file.open("record.txt", ios::binary | ios::in);
    if (!file){
        file.close();
        file.open("record.txt", ios::binary | ios::out | ios::app);
        if (!file) {
            cout <<"\nFile writing object error";
        }else{
            cout << "Enter product id: "; cin >> localProductID;
            getData();
            setProductID(localProductID);
            file.write((char*)this, sizeof(*this));
            cout << "\nThe following record added successfully";
            cout <<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
            show();
            setWritingStatus(false);
            file.close();
        }
    }
    else{
        cout << "\nEnter Product ID: ";
    getIdAgain:
        cin >> localProductID;
        file.read((char*)this, sizeof(*this));
        while (!file.eof())
        {
            if (localProductID == getProductID()) {
                flag = false;
                break;
            }
            file.read((char*)this, sizeof(*this));
        }
        file.close();
    }
    if (flag == false) {
        cout << "Product Id already exists, Please in again: ";
        file.open("record.txt", ios::binary | ios::in);
        flag = true;
        goto getIdAgain;
    }else{
        file.open("record.txt", ios::binary | ios::out | ios::app);
        if (!file) {
            cout <<"\nFile writing object error";
        }else{
            getData();
            setProductID(localProductID);
            file.write((char*)this, sizeof(*this));
            cout << "\nThe following record added successfully";
            cout <<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
            show();
        }
    }
    file.close();
    
}

void Clothes::readData(){
    int count = 0;
    fstream file("record.txt", ios::binary | ios::in);
    if (!file)
        cout << "File reading error....";
    else
    {
        cout << "\nFollowing are the Records from File";
        cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
        file.read((char*)this, sizeof(*this));
        while (!file.eof())
        {
            count++;
            show    ();
            file.read((char*)this, sizeof(*this));
        }
        cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
    }
    if(count==0)
        cout<<"\nRecord not found";
    else
        cout<<"\nTotal Records found="<<count;
    file.close();
    
}

void Clothes::deleteData() {
    fstream file("record.txt",ios::binary|ios::in|ios::out);
    fstream tempfile("record_t.txt", ios::binary  | ios::out);
    if(!file)
        cout<<"\nFile Reading error";
    else
    {
        cout<<"\nEnter Product ID you want to delete:";
        int id;  int count=0;
        cin>>id;
        file.read((char*)this, sizeof(*this));
        while (!file.eof())
        {
            if (id == getProductID())
            {
                count++;
            }
            else
            {
                tempfile.write((char*)this, sizeof(*this));
            }
            file.read((char*)this, sizeof(*this));
            
        }
        if (count == 0)
            cout << "\nRecord not found";
        else
        {
            cout << "\n" << count << " Record deleted successfully";
            tempfile.close();
            file.close();
            remove("record.txt");
            rename("record_t.txt", "record.txt");
        }
        
    }
    file.close();
}

void Clothes:: updateData() {
    fstream file("record.txt",ios::binary|ios::in|ios::out);
    
    if(!file)
        cout<<"\nFile Reading error....";
    else
    {    cout<<"\nEnter Product ID you want to update";
        int id;  int count=0;
        cin>>id;
        file.read((char*)this, sizeof(*this));
        while(!file.eof())
        {
            if(id==getProductID())
            {
                count++;
                streampos rposition=file.tellg();
                int size=sizeof(*this);
                
                file.seekp((int)rposition - size);
                getData();
                file.write((char*)this, sizeof(*this));
                break;     //removing one record at a time
            }
            file.read((char*)this, sizeof(*this));
        }
        if(count==0)
            cout<<"\nRecord not found";
        else
            cout<<"\n"<<count<<" Record updated successfully";
    }
    file.close();
    
}

void Clothes::searchData() {
    fstream file("record.txt",ios::binary|ios::in);
    if(!file)
        cout<<"\nReading error";
    else
    {    cout<<"\nEnter Product ID you want to search:";
        int id;  int count=0;
        cin>>id;
        file.read((char*)this, sizeof(*this));
        while(!file.eof())
        {
            if(id==getProductID())
            {
                show();
                count++;
            }
            file.read((char*)this, sizeof(*this));
            
        }
        if(count==0)
            cout<<"\nRecord not found";
        else
            cout<<"\nTotal Records found="<<count;
    }
    file.close();
}


#endif /* Clothes_h */
