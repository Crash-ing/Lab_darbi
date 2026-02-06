/* Māris Priede, mp24063
C33. Izdrukāt pirmās n (n<16) Paskāla trijstūra rindiņas.
Paskāla trijstūris ir skaitļu trijstūris, kuram malās ir 1, katrs skaitlis rindiņā ir vienāds ar  divu virs viņa esošo skaitļu summu.
Darbs veikts: 12/11/2024
*/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void printPascTri(int n) {                  // Funkcija, kas rēķina skaitļus un printē piramīdu
    int pascNum[16][16] = {0};

    for (int i = 0; i < n; i++) {
        for (int a = 1; a <= n - i - 1; a++) {
            cout << "   ";                  // 3 tukšumzīmes, simetrijai ar 4 ciparu skaitļiem
        }

        pascNum[i][0] = 1;                  // Katrā rindā kā pirmo elementu ieliek '1'
        pascNum[i][i] = 1;                  // Katrā rindā pēdējais elements '1'

        for (int j = 1; j < i; j++) {
            pascNum[i][j] = pascNum[i - 1][j - 1] + pascNum[i - 1][j];
        }

        for (int j = 0; j <= i; j++) {
            cout << setw(4);                // Nosaka skaitlim atvēlēto minimālo garumu/vietu izvadē
                                            // (īsākiem skaitļiem priekšā tiek pievienotas tukšumzīmes)
            cout << pascNum[i][j] << "  ";
        }
        cout << endl << endl;               // Divas tukšas rindas pēc katras rindas, simetrijai
    }
}

int readIntegerValue() {                    // Funkcija, kas pārbauda ievadi
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
        int n;
        
        while (true) {
            cout << "Input pyramids height (1 - 16): ";
            n = readIntegerValue();
            if (n >= 1 && n <= 16) {
                break;
            }

            cout << "Input an integer between 1 and 16!" << endl;
        }

        printPascTri(n);
        
        while (true) {
            cout << "Do you want to restart (1) or end (0) the program? " << endl;
            restart = readIntegerValue();
            if (restart == 0 || restart == 1) break;

            cout << "You need to input 1 to restart or 0 to end the program!" << endl;
        }
    } while (restart == 1);

    cout << "Exiting..." << endl;

    return 0;
}
