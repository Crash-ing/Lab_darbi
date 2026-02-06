// Māris Priede, mp24063
//
// D1. "Izveidot klasi ""Komplekss skaitlis"" - ComplexNumber, kurā tiek glabāti divi skaitļi, kas nosaka kompleksu skaitli. 
// Klasei izveidot šādas metodes: 
// (1) konstruktors, ar kuru tiek padotas sākotnējās vērtības, 
// (2) destruktors, kurš paziņo par objekta likvidēšanu, 
// (3) metode ""Pieskaitīt"" - add ar diviem parametriem, kas (savam) kompleksajam skaitlim pieskaita otru (kas padots ar parametriem) kompleksu skaitli un rezultātu noglabā pie sevis, 
// (4) metode ""Reizināt""  - multiply ar diviem parametriem, kas sareizina kompleksus skaitļus, 
// (5) metode ""Drukāt"" - print, kas izdrukā komplekso skaitli."
// 
// Programma izveidota: 8/12/2024

#include <iostream>
#include <limits>
#include "program.h"
using namespace std;

double readDoubleValue() {
    double integer;

    while (true) {
        cin >> integer;

        if (cin.fail ()) {
            cin.clear ();
            cin.ignore (numeric_limits<streamsize>::max(), '\n');
            cout << "Error! You didn't input a valid integer! Try again: ";
        }
        else {
            break;
        }
    } 
    return integer;
}

double readIntgerValue() {
    int integer;

    cout << "Do you want to restart (1) or end (0) the program? " << endl;
    while (true) {
        cin >> integer;
        if (cin.fail () || (integer != 0 && integer != 1) || cin.peek () != '\n') {
            cin.clear ();
            cin.ignore (numeric_limits<streamsize>::max (), '\n');
            cout << "You need to input 1 to restart or 0 to end the program! Try again: ";
        }
        else {
            break;
        }
    }
    return integer;
}

int main() {
    int restart = 1;
    do {
        double a, b, x, y;
        string function;

        cout << "Input a complex number: ";
        a = readDoubleValue();      // Ievades pārbaudes
        b = readDoubleValue();        

        ComplexNumber n(a, b);
        n.print();

        cout << "Input a second complex number: ";
        x = readDoubleValue();
        y = readDoubleValue();  

        while (true) {      // Darbības izvēle
            cout << "Do you want to add (a) or multiply (m) them?" << endl;
            cin >> function;

            if (function == "a") {      // Saskaitīšana
                n.add(x, y);
                cout << "Your complex number after addition: " << endl;
                n.print();
                break;
            }
            else if (function == "m") {     // Reizināšana
                n.multiply(x, y);
                cout << "Your complex number after multiplication: " << endl;
                n.print();
                break;
            }
            else {      // Nepareiza ievade
                cout << "You have to input 'a' or 'm'!" << endl;
                continue;
            }
        }

        restart = readIntgerValue();        // 'restart' pārbaude
    } while (restart == 1);

    cout << "Exiting program..." << endl;
    return 0;
}