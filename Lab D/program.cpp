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
// 
// Metožu realizācija

#include <iostream>
#include "program.h"
using namespace std;

ComplexNumber::ComplexNumber(double aa, double bb) {    // Konstruktors
    a = aa;
    b = bb;
}

ComplexNumber::~ComplexNumber() {       // Destruktors
    cout << "Object destroyed" << endl;
}

void ComplexNumber::add(double x, double y) {       // Metode 'add'
    a += x;
    b += y;
}

void ComplexNumber::multiply(double x, double y) {      // Metode 'multiply'
    double tempA = a * x - b * y;   // saglabā jauno a vērtību, lai tā netiek izmantota nākamajā kalkulācijā
    b = a * y + b * x;
    a = tempA;      // a vērtībai piešķir iepriekš izrēķināto jauno vērtību
}

void ComplexNumber::print() {       // Metode 'print'
    cout << "Complex Number: " << a << " + " << b << "*i" << endl;
}