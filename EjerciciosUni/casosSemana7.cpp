#include <iostream>

using namespace std;

int mainMenu();
void lunchBlock(int opcion);

void tablaMult();
bool validarNumero(int numero);

int main() {
    lunchBlock(mainMenu());
    return 0;
}

int mainMenu() {
    int opcion;
    cout << "Ejercicios Semana 7" << endl;
    cout << "Ejercicio 1: Tabla de multiplicar de un numero" << endl;
    cout << "-> ";

    cin >> opcion;

    return opcion;
}

void lunchBlock(int opcion) {
    switch(opcion) {
        case 1:
            tablaMult();
            break;
        default:
            cout << "Opcion Invalida" << endl;
    }
}

bool validarNumero(int numero) {
    return (((numero > 0) && (numero < 100)) ? false : true);
}
void tablaMult() {
    int numero;

    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
    } while (validarNumero(numero));

    cout << endl;
    for (int i = 1; i <= 30; i++) {
        cout << numero << " * " << i << " = " << numero * i << endl;
    }
}
