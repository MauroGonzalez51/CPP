#include <bits/stdc++.h>

using namespace std;

class Trabajadores {
    public:
        string codigo;
        int grupo, salarioSemanal;

    bool validarGrupo () {
        return ((this -> grupo != 1) && (this -> grupo != 2) ? true : false);  
    }

    bool validarSalario() {
        return ((this -> salarioSemanal < 1) ? true : false);
    }
};

void llenarArrays(Trabajadores& trabajador, int i) {
    cout << "[EMPLEADO " << i + 1 << "] Ingrese su codigo: ";
    cin >> trabajador.codigo;

    do {
        cout << "[EMPLEADO " << i + 1 << "] Ingrese su grupo: ";
        cin >> trabajador.grupo;
    } while (trabajador.validarGrupo());

    do {
        cout << "[EMPLEADO " << i + 1 << "] Ingrese su salario semanal: ";
        cin >> trabajador.salarioSemanal;
    } while (trabajador.validarSalario());
}

void aplicarAumento(Trabajadores& trabajador) {
    (trabajador.grupo == 1) ? trabajador.salarioSemanal += 250000 : 
        trabajador.salarioSemanal += 150000;
}

void cambiosGrupo(Trabajadores& trabajador, int& cambiosGrupo, float promedioGrupo) {
    if ((trabajador.grupo == 1) && (trabajador.salarioSemanal > promedioGrupo)) {
        trabajador.grupo = 2;
        cambiosGrupo++;
    }
}

int main() {
    int cantidadTrabajadores, cambios = 0;

    // [0] -> Sumatoria | [1] -> Cantidad | [2] -> Resultado
    array <float, 3> Grupo1;
    array <float, 3> Grupo2;

    Grupo1.fill(0.0); Grupo2.fill(0.0);


    do {
        cout << "Ingrese la cantidad de trabajadores: ";
        cin >> cantidadTrabajadores;
    } while (cantidadTrabajadores < 1);

    Trabajadores trabajadores[cantidadTrabajadores];

    for (int i = 0; i < cantidadTrabajadores; i++) {
        llenarArrays(trabajadores[i], i);
        aplicarAumento(trabajadores[i]);

        // Calculando el promedio :>

        if (trabajadores[i].grupo == 1) {
            Grupo1[0] += trabajadores[i].salarioSemanal;
            Grupo1[1]++;
        } else {
            Grupo2[0] += trabajadores[i].salarioSemanal;
            Grupo2[1]++;
        }
    }

    if (Grupo1[1] != 0) {
        Grupo1[2] = Grupo1[0] / Grupo1[1];
    }

    if (Grupo2[1] != 0) {
        Grupo2[2] = Grupo1[0] / Grupo2[1];
    }

    for (int i = 0; i < cantidadTrabajadores; i++) {
        cambiosGrupo(trabajadores[i], cambios, (float) Grupo1[2]);
    }

    cout << endl;
    cout << "Salarios Finales [...]" << endl;
    cout << "Cambios de Grupo: " << cambiosGrupo << endl;
    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << "| Codigo: " trabajadores[i].codigo << " | Grupo: " << trabajadores[i].grupo << " | Salario: " << trabajadores[i].salarioSemanal << " |" << endl;
    }

    return 0;
}