/**
 *  @autor mauroGonzalez
 *  @code T00067622
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

class Trabajadores {
    public:
        string codigo;
        int grupo, salarioSemanal;
        
        bool validarGrupo() { 
            return (((this -> grupo != 1) && (this -> grupo != 2)) ? true : false);
        }

        bool validarSalario() {
            return ((this -> salarioSemanal < 1) ? true : false);
        }
};

int main() {
    int cantidadTrabajadores, cambiosGrupo = 0;

    array <float, 3> promedioGrupoUno;
    array <float, 3> promedioGrupoDos;

    promedioGrupoUno.fill(0.0);
    promedioGrupoDos.fill(0.0);

    do {
        cout << "Cantidad de Trabajadores: ";
        cin >> cantidadTrabajadores;
    } while (cantidadTrabajadores < 1);

    Trabajadores trabajadores[cantidadTrabajadores];
    system("cls");
    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << endl;
        cout << "[EMPLEADO " << i + 1 << "] Ingrese su codigo: ";
        cin >> trabajadores[i].codigo;

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese el grupo al que pertenece: ";
            cin >> trabajadores[i].grupo;
        } while (trabajadores[i].validarGrupo());

        do {
            cout << "[EMPLEADO " << i + 1 << "] Ingrese su salario semanal: ";
            cin >> trabajadores[i].salarioSemanal;
        } while (trabajadores[i].validarSalario());

        if (trabajadores[i].grupo == 1) {
            trabajadores[i].salarioSemanal += 250000;
            promedioGrupoUno[0] += trabajadores[i].salarioSemanal;
            promedioGrupoUno[1]++;
        } else {
            trabajadores[i].salarioSemanal += 150000;
            promedioGrupoDos[0] += trabajadores[i].salarioSemanal;
            promedioGrupoDos[1]++;
        }

        for (int i = 0; i < 60; i++) 
            cout << "-";
        
    }

    if (promedioGrupoUno[1] != 0.0)
        promedioGrupoUno[2] = promedioGrupoUno[0] / promedioGrupoUno[1];
    
    if (promedioGrupoDos[1] != 0.0) 
        promedioGrupoDos[2] = promedioGrupoDos[0] / promedioGrupoDos[1];

    for (int i = 0; i < cantidadTrabajadores; i++) {
        if ((trabajadores[i].grupo == 1) && (trabajadores[i].salarioSemanal > promedioGrupoUno[2])) {
            trabajadores[i].grupo = 2;
            cambiosGrupo++;
        }
    }
    cout << endl;
    for (int i = 0; i < 60; i++)
        cout << "*";
    
    cout << endl;
    cout << "Salarios [...]" << endl;
    cout << "Cambios de Grupo: " << cambiosGrupo << endl;

    for (int i = 0; i < cantidadTrabajadores; i++) {
        cout << "Codigo: " << trabajadores[i].codigo << " | Grupo: " << trabajadores[i].grupo << " | Salario: " << trabajadores[i].salarioSemanal << endl;
    }
    
    return 0;
}