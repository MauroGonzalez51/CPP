#include <bits/stdc++.h>

using namespace std;

class Estudiantes {
    public:
        string nombre, codigo;
        array <float, 5> notas;
        float promedioFinal;

        void calcularPromedio() {
            float sumaTotal = 0.0;
            for (int i : notas)
                sumaTotal += i;
            
            this -> promedioFinal = sumaTotal / notas.size();
        }

        bool validarNota(int i) {
            return (((this -> notas[i] >= 0.0) && (this -> notas[i] <= 5.0)) ? false : true)
        }
};

void llenarDatos(Estudiantes& estudiante, int posicion) {
    cout << "Estudiante " << posicion + 1 << ", Ingrese su nombre: ";
    cin >> estudiante.nombre;

    cout << "Estudiante " << posicion + 1 << ", Ingrese su codigo: ";
    cin >> estudiante.codigo;

    for (int i = 0; i < 5) {
        do {
            cout << "Nota " << i + 1 << ": ";
            cin >> estudiante.notas[i];
        } while (estudiante.validarNotas(i));
    }

    estudiante.calcularPromedio();
}

int main() {
    int cantidadEstudiantes;
    do {
        cout << "Cantidad de Estudiantes: ";
        cin >> cantidadEstudiantes;
    } while (cantidadEstudiantes < 1);

    Estudiantes estudiantes[cantidadEstudiantes];   
    float notasFinales[i];
    for (int i = 0; i < cantidadEstudiantes; i++) {
        llenarDatos(estudiantes[i]);
        notasFinales[i] = estudiantes[i].promedioFinal;
    }

    array <float, 2> notaMayor; notaMayor.fill(0.0);
    array <float, 2> notaMenor = {9999999.0, 0.0}

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedioFinal > notaMayor[0]) {
            notaMayor[0] = estudiantes[i].promedioFinal;
            notaMayor[1] = i; 
        }
    }

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedioFinal < notaMenor[0]) {
            notaMenor[0] = estudiantes[i].promedioFinal;
            notaMenor[1] = i;
        }
    }
    
    float promedioNotas = 0.0;
    int mayorPromedio = 0;
    for (int i : notasFinales) 
        promedioNotas += i;
    
    promedioNotas /= cantidadEstudiantes;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedioFinal > promedioNotas)
            mayorPromedio++;
    }

    
    
    

    return 0;
}