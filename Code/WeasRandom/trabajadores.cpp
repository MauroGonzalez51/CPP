#include <bits/stdc++.h> 

using namespace std;

int main() {
    int cantidadTrabajadores, nuevoGrupo = 0;

    do {
        cout << "Ingrese la cantidad de trabajadores: ";
        cin >> cantidadTrabajadores;
    } while (cantidadTrabajadores < 1);

    system("cls");

    string codigoTrabajadores[cantidadTrabajadores];
    int grupo[cantidadTrabajadores];
    int salarioSemanal[cantidadTrabajadores];

    // Pidiendo los datos :>
    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << endl;
        cout << "[EMPLEADO " << i + 1 << "] Ingrese su codigo/identificacion: ";
        cin >> codigoTrabajadores[i];

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese el grupo al que pertenece: ";
            cin >> grupo[i];
        } while ((grupo[i] != 1) && (grupo[i] != 2));

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese su salario semanal: ";
            cin >> salarioSemanal[i];
        } while (salarioSemanal[i] < 1);
    }

    // Aplicando el aumento :>

    for (int i = 0; i < cantidadTrabajadores; i++) {
        (grupo[i] == 1) ? salarioSemanal[i] += 250000 : salarioSemanal[i] +=  150000;
    }

    // Verificar el promedio de salario de cada grupo :>

    float promedioGrupo1 = 0.0, promedioGrupo2 = 0.0;
    int cantidadGrupo1 = 0, cantidadGrupo2 = 0;

    for (int i = 0; i < cantidadTrabajadores; i++) {
        if (grupo[i] == 1) {
            promedioGrupo1 += salarioSemanal[i];
            cantidadGrupo1++;
        } else {
            promedioGrupo2 += salarioSemanal[i];
            cantidadGrupo2++;
        }
    }

    if (cantidadGrupo1 != 0)
        promedioGrupo1 /= cantidadGrupo1;

    if (cantidadGrupo2 != 0)
        promedioGrupo2 /= cantidadGrupo2;

    // cout << "PRE Aumento" << endl;
    // for (int i = 0; i < cantidadTrabajadores; i++) {
    //     cout << codigoTrabajadores[i] << " " << grupo[i] << " " << salarioSemanal[i] << " " << endl;
    // }


    // cout << "POST Aumento" << endl;
    // for (int i = 0; i < cantidadTrabajadores; i++) {
    //     cout << codigoTrabajadores[i] << " " << grupo[i] << " " << salarioSemanal[i] << " " << endl;
    // }

    // Verificando si algun empleado del grupo 1 tiene salario mayor al promedio de su grupo :> 

    for (int i = 0; i < cantidadTrabajadores; i++) {
        if ((salarioSemanal[i] > promedioGrupo1) && (grupo[i] == 1)) {
            grupo[i] = 2;
            nuevoGrupo++;
        }
    }

    // Imprimiendo los datos
    system("cls");
    cout << "Nuevo Sueldo" << endl;
    cout << "Cambiaron de Grupo: " << nuevoGrupo << " empleado(s)" << endl;


    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << "| Codigo: " << codigoTrabajadores[i] << " | Grupo: " << grupo[i] << " | Salario: " << salarioSemanal[i] << " |" << endl;
    }

    return 0;
}

/*
    PD: En el programa primero si aplica el aumento, luego se verifica si este "Nuevo"
    salario es mayor que el promedio de su grupo.

    En caso de que asi sea, se ca cambia al grupo 2

    Lo hice de esta manera ya que al probar hacerlo al reves, todos los empleados del grupo 1,
    pasaban directamente al grupo 2

    Asi que asumí que de esta manera habria algunos que se quedan en el mismo grupo, otros que no
*/