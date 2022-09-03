#include <iostream>

using namespace std;

int main() {
    // int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, cantidad = 0;
    
    // cout << "Ingrese un numero (1): ";
    // cin >> num1;

    // cout << "Ingrese un numero (2): ";
    // cin >> num2;

    // cout << "Ingrese un numero (3): ";
    // cin >> num3;

    // cout << "Ingrese un numero (4): ";
    // cin >> num4;

    // cout << "Ingrese un numero (5): ";
    // cin >> num5;

    // cout << "Ingrese un numero (6): ";
    // cin >> num6;

    // cout << "Ingrese un numero (7): ";
    // cin >> num7;

    // cout << "Ingrese un numero (8): ";
    // cin >> num8;

    // cout << "Ingrese un numero (9): ";
    // cin >> num9;

    // cout << "Ingrese un numero (10): ";
    // cin >> num10;

    // int buscar;
    // cout << "Numero a buscar: ";
    // cin >> buscar;

    // if (buscar == num1) 
    //     cantidad += 1;
    // if (buscar == num2) 
    //     cantidad += 1;
    // if (buscar == num3) 
    //     cantidad += 1;
    // if (buscar == num4) 
    //     cantidad += 1;
    // if (buscar == num5) 
    //     cantidad += 1;
    // if (buscar == num6) 
    //     cantidad += 1;
    // if (buscar == num7) 
    //     cantidad += 1;
    // if (buscar == num8) 
    //     cantidad += 1;
    // if (buscar == num9) 
    //     cantidad += 1;
    // if (buscar == num10) 
    //     cantidad += 1;

    // cout << "Cantidad de cantidad que se repite: " << cantidad << endl;

    int numeros[10];
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese un numero (" << i + 1 << "): ";
        cin >> numeros[i];
    }
    int cantidadVeces = 0, numeroBuscar;
    cout << "Numero a buscar: ";
    cin >> numeroBuscar;
    for (int i = 0; i < 10; i++) {
        if (numeroBuscar == numeros[i])
            cantidadVeces += 1;
    }
    cout << "Veces: " << cantidadVeces;

    return 0;
}