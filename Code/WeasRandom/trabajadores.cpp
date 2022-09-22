#include <bits/stdc++.h>

using namespace std;

void llenarArrays(string& codigoTrabajadores, int& grupo, int& salarioSemanal, int& cantidadTrabajadores);

int main() {
    int cantidadTrabajadores;
    
    do {
        cout << "Ingrese la cantidad de Trabajadores: ";
        cin >> cantidadTrabajadores;
    } while ((cantidadTrabajadores < 1) || (cantidadTrabajadores > 50));

    string codigoTrabajadores[cantidadTrabajadores];
    int grupo[cantidadTrabajadores];
    int salarioSemanal[cantidadTrabajadores];

    system("cls");

    llenarArrays(codigoTrabajadores, grupo, salarioSemanal, cantidadTrabajadores);
}

void llenarArrays(string& codigoTrabajadores, int& grupo, int& salarioSemanal, int& cantidadTrabajadores) {
    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << endl;
        cout << "[EMPLEADO " << i + 1 << "] Ingrese su Codigo/Identificacion: ";
        cin >> codigoTrabajadores[i];

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese el grupo al que pertenece (1/2): ";
            cin >> grupo;
        } while ((grupo != 1) && (grupo != 2));

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese su salario semanal: ";
            cin >> salarioSemanal;
        } while (salarioSemanal < 1);
    }

    for (auto i : codigoTrabajadores) {
        cout << endl << i << endl;
    }
}