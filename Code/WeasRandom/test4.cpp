#include <iostream>

using namespace std;

int main() {
    int numeros[10];
    int numeroBuscar, posicion;
    bool flag = false;
    cout << "Numero Buscar: ";
    cin >> numeroBuscar;

    for (int i = 0; i < 10; i++) {
        if (numeroBuscar == numeros[i]) {
            flag = true;
            posicion = i;
            break;
        }
    }

    if (flag) {
        cout << "Numero encontrado" << endl;
        cout << "Posicion: " << posicion << endl;
    }




    return 0;
}