#include <bits/stdc++.h>

using namespace std;

const int horaNormal = 16000;
const int horaExtra = 20000;

class Trabajador {
    private:
        int sueldo, horasTrabajadas, horasNormales, horasExtra;

    public: 
        Trabajador(void) {
            cout << endl;
            cout << "Cantidad de Horas Trabajadas: ";
            cin >> this -> horasTrabajadas;
        }

        void calcSueldo() {
            (this -> horasTrabajadas <= 40) ? 
                this -> sueldo = horasTrabajadas * horaNormal : 
                    this -> sueldo = (40 * horaNormal) + ((horasTrabajadas - 40) * horaExtra);     
        }

        int getSueldo() { return this -> sueldo; }
};

int main() {
    Trabajador* trabajador = new Trabajador();
    trabajador -> calcSueldo();
    cout << "Sueldo: " << trabajador -> getSueldo() << endl;
    return EXIT_SUCCESS;
}