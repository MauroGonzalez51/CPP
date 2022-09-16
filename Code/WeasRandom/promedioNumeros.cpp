#include <bits/stdc++.h>

using namespace std;

int main() {
    float sumaTotal = 0.0, cantidadNumeros = 0.0;
    int timesIngresedZero = 0;
    while (true) {
        float numero;
        cout << "Ingrese un numero: ";
        cin >> numero;

        if (cantidadNumeros >= 1.0) {
            if (numero == 0) {
                break;
            } else {
                sumaTotal += numero;
                cantidadNumeros += 1.0;
            }
        } else {
            do {
                cout << "Ingrese un numero valido: ";
                cin >> numero;
                timesIngresedZero += 1;
                if (timesIngresedZero >= 5)
                    abort();
            } while (numero == 0);
            sumaTotal += numero;
            cantidadNumeros += 1.0;
        }
    }
    float promedio = sumaTotal / cantidadNumeros;
    cout << "Promedio: " << promedio;
    return 0;
}