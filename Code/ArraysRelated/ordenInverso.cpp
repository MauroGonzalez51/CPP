#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int cantidadNumeros;

    cout << "Cantidad de elementos del array: ";
    cin >> cantidadNumeros;

    int numeros[cantidadNumeros];

    for (int i = 0; i < cantidadNumeros; i++) {
        cout << "Ingrese un numero: ";
        cin >> numeros[i];
    }

    cout << "Orden Inverso" << endl;

    for (cantidadNumeros - 1; cantidadNumeros > 0; cantidadNumeros--){
        cout << cantidadNumeros - 1 << " -> " << numeros[cantidadNumeros-1] << endl;
    }



    getch();
    return 0;
}