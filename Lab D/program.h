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
// Klases deklarācija

#ifndef program_h
#define program_h

class ComplexNumber {
    private:
        double a;
        double b;
    public:
        ComplexNumber(double aa, double bb);
        ~ComplexNumber();
        void add(double x, double y);
        void multiply(double x, double y);
        void print();
};

#endif