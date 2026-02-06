/*  Māris Priede, mp24063
B9. Doti trīs naturāli skaitļi, kas nosaka datumu, mēnesi un gadu. 
Uzrakstīt funkciju, kas atgriež šādu skaitļu trijnieku nākošajai dienai (pēc Gregora kalendāra garie gadi ir tie, kuri dalās ar 4, izņemot tos, kuri dalās ar 100 un nedalās ar 400). 
Izmantot arī atsevišķu funkciju, kas pārbauda datuma korektību. 
Risinājumā izmantot funkciju, kas atpazīst garos gadus.
Programma izveidota: 19/10/2024
*/

#include <iostream>
#include <limits>
using namespace std;

bool isLeapYear(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

bool isYearValid(int y) {
    if (y < 0) {
        cout << "Invalid year!" << endl;
        return false;
    }
    return true;
}

bool isMonthValid(int m) {
    if (m < 1 || m > 12) {
        cout << "Invalid month!" << endl;
        return false;
    }
    return true;
}

bool isDayValid(int d, int m, int y) {
    // Masīvs kurš satur visu mēnešu dienu skaitu
    int daysInMonth[] = {31, (isLeapYear(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d < 1 || d > daysInMonth[m - 1]) {
        cout << "Invalid day for this month!" << endl;
        return false;
    }
    return true;
}

void printNextDate(int d, int m, int y) {
    int daysInMonth[] = {31, (isLeapYear(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    d++;    
    if (d > daysInMonth[m - 1]) {   // Pārbaude vai dienas pārsniedz limitu, lai saprastu vai jāpārslēdz mēnesis.
        d = 1;
        m++;    
        if (m > 12) {   // Pārbaude vai mēneši pārsniedz limitu, lai saprastu vai jāpārslēdz gads.
            m = 1;
            y++;
        }
    }

    cout << "The next date: " << d << "/" << m << "/" << y << endl;
}

int IntegerInputOK() {  // Funkcija, lai pārbaudītu vai izdevās ievades.
    int integer;
    while (true) {
        cin >> integer;

        if (cin.fail () || cin.peek () != '\n') {
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

int main() {
    int restart = 1;
    do {
        int d, m, y;

        do {
            cout << "Enter a year: ";
            y = IntegerInputOK();
        } while (!isYearValid(y));
            


        do {
            cout << "Enter a month: ";
            m = IntegerInputOK();
        } while (!isMonthValid(m));
       

        do {
            cout << "Enter a day: ";
            d = IntegerInputOK();
        } while (!isDayValid(d, m, y));

        cout << "Date you entered: " << d << "/" << m << "/" << y << " - ";
        
        if (isLeapYear(y)) {
            cout << "This is a leap year!" << endl;
        }
        else {
            cout << "This is an ordinary year!" << endl;
        }
        
        printNextDate(d, m ,y);

        while (true) {
            cout << "Do you want to restart (1) or end (0) the program? " << endl;
            cin >> restart;
            if (cin.fail () || (restart != 0 && restart != 1) || cin.peek () != '\n') {
                cin.clear ();
                cin.ignore (numeric_limits<streamsize>::max (), '\n');
                cout << "You need to input 1 to restart or 0 to end the program!" << endl;
            }
            else {
                break;
            }
        }
        
    } while (restart == 1);

    return 0;
}