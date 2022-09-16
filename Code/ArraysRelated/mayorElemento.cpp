#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int cantidadNumeros;
    cout << "Cantidad de elementos del array: ";
    cin >> cantidadNumeros;

    int numeros[cantidadNumeros], mayor = 0;
    
    for (int i = 0; i < cantidadNumeros; i++) {
        cout << "Digite un numero: ";
        cin >> numeros[i];
    }
    
    //Buscar el numero mayor ingresado
    for (int i = 0; i < cantidadNumeros; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }
    cout << "Numero mayor: " << mayor << endl;

    getch();
    return 0;
}