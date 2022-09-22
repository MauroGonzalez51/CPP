#include <iostream>

using namespace std;

int main() {
    // Llenar una matriz 4 x 6
    //      fila x columna
    int numeros[4][6];

    for (int columna = 0; columna < 6; columna++) {
        for (int fila = 0; fila < 4; fila++) {
            cout << "Elemento " << fila + 1 << columna + 1 << ": ";
            cin >> numeros[fila][columna];
        }
    }

    cout << endl;
    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 6; columna++) {
            cout << numeros[fila][columna] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    for (int fila = 0; fila < 4; fila++) {
        float sumaTotal = 0.0;
        for (int columna = 0; columna < 6; columna++) {
            sumaTotal += numeros[fila][columna];
        }

        float promedioFila = sumaTotal / 6;

        cout << "Promedio Fila " << fila + 1 << ": " << promedioFila << endl;
    }

    return 0;
}