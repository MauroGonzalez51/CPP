#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ofstream logFile("logFile.txt", ios::app);
int main() { 
    // Buscando los divisores de un numero?

    int numero;

    cout << "Ingrese un numero: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        try {
            if (numero % i == 0) {
                cout << "Es divisible por " << i << endl;
            } else {
                throw (i);
            }
        }
        catch (int i) {
            logFile << "Error: " << i << endl;
        }
    }

    return 0;
}