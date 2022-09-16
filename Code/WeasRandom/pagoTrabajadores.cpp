#include <iostream>

using namespace std;

int main() {
    // int numero;

    // cout << "Digite un numero: ";
    // cin >> numero;

    // cout << "\n El numero que digito es " << numero;

    int numeroHorasTrabajadasAll, horaNormal = 16000, horaExtra = 20000, sueldo, horasNormalesTrabajadas, horasExtraTrabajadas;

    cout << "Ingrese la cantidad de horasTrabajadas: ";
    cin >> numeroHorasTrabajadasAll;

    if (numeroHorasTrabajadasAll <= 40) {
        sueldo = (numeroHorasTrabajadasAll * horaNormal);
    } else {
        horasExtraTrabajadas = numeroHorasTrabajadasAll - 40;
        horasNormalesTrabajadas = numeroHorasTrabajadasAll - horasExtraTrabajadas;

        sueldo = ((horasExtraTrabajadas * horaExtra) + (horasNormalesTrabajadas * horaNormal));
    }

    cout << "\n" << sueldo;

    return 0;
}