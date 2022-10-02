#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void opcion1();
void opcion2();

int main() {
    int opcion;
    cout << "Programas a elegir" << endl;
    cout << "[1]: Llenar dos vectores y juntarlos" << endl;
    cout << "[2]: Llenar un vector y buscar un numero" << endl;

    cout << "-> ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            opcion1();
            break;
        }
        case 2: {
            opcion2();
            break;
        }
        default: {
            cout << "Opcion no encontrada" << endl;
        }
    }
    
    return 0;
}

void opcion1() {
    int cantidadA, cantidadB;

    do {
        do {
            cout << "Cantidad de datos del vector 1: ";
            cin >> cantidadA;
        } while (cantidadA < 0);

        do {
            cout << "Cantidad de datos del vector 2: ";
            cin >> cantidadB;
        } while (cantidadB < 0);

        if (cantidadA == cantidadB) {
            cout << "Los vectores deben tener diferente cantidad de datos" << endl;
        }
    } while (cantidadA == cantidadB);


    int vectorA[cantidadA];
    int vectorB[cantidadB];
    vector <int> vectorResultante;

    cout << endl << "Vector 1" << endl;
    for (int i = 0; i < cantidadA; i++) {
        cout << "-> ";
        cin >> vectorA[i];
    }

    cout << endl << "Vector 2" << endl;
    for (int i = 0; i < cantidadB; i++) {
        cout << "-> ";
        cin >> vectorB[i];
    }

    cout << endl << "Juntando los vectores" << endl;
    for (int i = 0; i < cantidadA; i++)
        vectorResultante.push_back(vectorA[i]);
    
    for (int i = 0; i < cantidadB; i++)
        vectorResultante.push_back(vectorB[i]);

    cout << endl << "Vector Resultante" << endl;
    for (int i : vectorResultante)
        cout << i << " ";
}

void opcion2() {
    int cantidadDatos;

    do {
        cout << "Ingrese la cantidad de datos: ";
        cin >> cantidadDatos;
    } while (cantidadDatos < 1);

    int numeros[cantidadDatos];

    for (int i = 0; i < cantidadDatos; i++) {
        cout << "-> ";
        cin >> numeros[i];
    }

    cout << endl;
    
    int numeroBuscar;
    cout << "Numero a buscar: ";
    cin >> numeroBuscar;

    bool flag = false;
    for (int i = 0; i < cantidadDatos; i++) {
        if (numeroBuscar == numeros[i]) {
            flag = true;
        }
    }

    if (flag) {
        cout << "El numero fue encotrado en el vector" << endl;
        int cantidadVeces = 0;

        for (int i = 0; i < cantidadDatos; i++) {
            if (numeroBuscar == numeros[i])
                cantidadVeces++;
        }

        cout << "Cantidad de veces: " << cantidadVeces << endl;
    } else {
        cout << "El numero no fue encontrado en el vector";
    }
}