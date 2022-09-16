//Escribe un programa que lea de entrada estandar un vector de numeros
//Y muestre en la salida estandar los numeros de ese vector con los
//Indices asociados

//En resumen
//Pedir los elementos del array y al final
//mostrarlos :>

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

    for (int i : numeros) {
        cout << i << endl;
    }
    

    getch();
    return 0;
}