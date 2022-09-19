#include <iostream>
#include <array>

using namespace std;

int main(void) {
    
    int cantidadNumeros;

    do {
        cout << "Cantidad Numeros: ";
        cin >> cantidadNumeros;
    } while (cantidadNumeros < 1);

    int numeros[cantidadNumeros];

    for (int i = 0; i < cantidadNumeros; i++) {
        numeros[i] = i;
    }

    for (auto i : numeros) {
        cout << i << " ";
    }
}