#include <iostream>

using namespace std;

int main() {
    cout << "Numero mayor de N numeros [ ... ]" << endl;

    float mayor = 0.0;
    int cantidadNumeros = 0;
    do {
        cantidadNumeros += 1;
        float numero;
        if (cantidadNumeros <= 1) {
            do {
                cout << "Ingrese un numero: ";
                cin >> numero;
            } while (numero < 1);
            if (numero > mayor) {
                mayor = numero;
            }
        } else {
            cout << "Ingrese un numero: ";
            cin >> numero;

            if (numero > mayor) {
                mayor = numero;
            }
            if (numero == 0)
                break;
        }
    } while (true);
    cout << "Numero Mayor: " << mayor << endl;
    return 0;
}