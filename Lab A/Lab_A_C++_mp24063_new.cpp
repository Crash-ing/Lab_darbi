/*  Māris Priede, mp24063
    A22. Doti veseli skaitļi  m un n. Izdrukāt tos skaitļus, kuri atrodas intervālā [n,m] un ir veselu skaitļu kubi.
    Programma izveidota: 20.09.2024
*/

#include <iostream>
#include <limits>
using namespace std;

int main() {
    int x, y, restart, i, cube;

    // Atkārto ciklu, kamēr lietotājs pasaka, lai beidz.
    do {

        // Cikls, kurš pārbauda vai mainīgā x vērtība ir vesels skaitlis.
        while (true) {
            cout << "Input x value: ";
            cin >> x;
            
            // Pārbauda vai ievade izdevās un vai ievadē ir citi simboli, kas nav cipari.
            if (cin.fail() || cin.peek() != '\n') {

                // Atbloķē objektu cin.
                cin.clear();  

                // Izdzēš tekstu no atmiņas.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error! You didn't input a valid integer! Try again!" << endl;
            } else {
                break;
            }
        }

        // Pārbauda vai y ievade izdevās veiksmīgi
        while (true) {   
            cout << "Input y value: ";
            cin >> y;

            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error! You didn't input a valid integer! Try again!" << endl;
            } else {
                break;
            }
        }

        // Pārbauda vai x<y, lai saprastu vai skaitļi jāprintē augošā vai diltošā secībā
        if (x <= y) {

            // Skaitļus printēs augošā secībā līdz x<=y
            for (; x <= y; ++x) {        
                if (x < 0) {
                    // Pārbauda negatīvos kubus
                    i = -1;
                    do {
                        cube = i * i * i;
                        --i;
                    } while (cube > x);
                }
                else {
                    // Pārbauda pozitīvos kubus
                    i = 0;
                    do {
                        cube = i * i * i;
                        ++i;
                    } while (cube < x);
                }

                if (cube == x) {
                    // Skaitlis ir vesela skaitļa kubs, izvadām to
                    cout << x << endl;
                }
            }
        } 
        else {          // Ja iepriekšējais nosacījums neizpildās, tad izpildās šis.
            for (; x >= y; x--) {
                if (x < 0) {
                    // Pārbauda negatīvos kubus
                    i = -1;
                    do {
                        cube = i * i * i;
                        --i;
                    } while (cube > x);
                }
                else {
                    // Pārbauda pozitīvos kubus
                    i = 0;
                    do {
                        cube = i * i * i;
                        ++i;
                    } while (cube < x);
                }

                if (cube == x) {
                    // Skaitlis ir vesela skaitļa kubs, izvadām to
                    cout << x << endl;
                }
            }
        } 

        // Cikls, lai lietotājs varētu turpināt darbu, neaizverot programmu.
        while (true) {
            cout << "Do you want to restart (1) or end (0)? ";
            cin >> restart;

            // Pārbauda vai restart ievade izdevās un vai ievadīts 1 vai 0.
            if (cin.fail() || (restart != 0 && restart != 1)) {
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error! Please enter 1 to restart or 0 to end!" << endl;
            } else {
                // Ja ievade veiksmīga un pareiza, tad iziet no cikla.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                break;
            }
        }

    } while (restart == 1);
    
    cout << "End of program!" << endl;
    return 0;
}
