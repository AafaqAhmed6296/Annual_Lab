//
//  main.cpp
//  Annual_Lab
//
//  Created by Afaq Ahmed on 15/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Clothes.h"

using namespace std;

int main(){
    int option;
    Clothes c1;
    char check;
    
    do
    {
        system("cls");
        cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
        cout << "\n\tWelcome to the UIIT Filing Program";
        cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
        cout << "\n\tDeveloped by \"Your Name\"";
        cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
        cout << "\n\tPress 1 for write data into file";
        cout << "\n\tPress 2 for read data from file";
        cout << "\n\tPress 3 for search data from file";
        cout << "\n\tPress 4 for update record in file";
        cout << "\n\tPress 5 for delete record from file:";
        cout << "\n\tEnter Option:";
        cin >> option;
        switch (option)
        {
            case 1: c1.storeData();     break;
            case 2: c1.readData();      break;
            case 3: c1.searchData();    break;
            case 4: c1.updateData();  break;
            case 5: c1.deleteData();  break;
        }
        cout << "\n\n\tDo you want to continue...y/n:"; cin >> check;
    } while ( check == 'y' || check == 'Y');
    cout << "\n\tThanks for using this program, Bye!";
    
    return 0;
}
