#include <iostream>

using namespace std;

int main() {
    int cantidadNumerosSumar, sumaTotal = 0;
    cout << "Cantidad de numeros a sumar: ";
    cin >> cantidadNumerosSumar;

    for (int i = 0; i < cantidadNumerosSumar; i++) {
        int numero;
        cout << "Numero " << i + 1 << ": ";
        cin >> numero;

        sumaTotal += numero;
    }
    cout << "Suma Total: " <<  sumaTotal;

    return 0;
}