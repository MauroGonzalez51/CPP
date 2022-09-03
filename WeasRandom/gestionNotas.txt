#include <iostream>

using namespace std;

int main() {
    int opcion;
    cout << "Gestor Universidad" << endl;
    cout << "1. Promedio ponderado de un Estudiante" << endl;
    cout << "2. Promedio Simple de un curso" << endl;
    cout << "3. Nota Minima" << endl;
    cout << "4. Salir del Programa" << endl;
    cout << "-> ";
    cin >> opcion;

    switch(opcion) {
        case 1:
        {
            int cantidadNotas, sumaPorcentajes = 0;
            float promedioPonderado = 0.0;
            cout << "Promedio Ponderado de un Estudiante" << endl;
            do {
                cout << "Cantidad de notas: ";
                cin >> cantidadNotas;
            } while (cantidadNotas < 1);
            for (int i = 0; i < cantidadNotas; i++) {
                float nota, porcentaje;
                cout << "Nota No. " << i + 1 << ": ";
                cin >> nota;
                cout << "Valor de esa nota (0-100%): ";
                cin >> porcentaje;

                sumaPorcentajes += porcentaje;
                promedioPonderado += (nota * (porcentaje / 100));
            }
            if (sumaPorcentajes != 100) {
                cout << "La suma de los porcentajes no suma 100%" << endl;
            } else {
                if (promedioPonderado >= 3.0) {
                    cout << "Felicidades, usted aprobo || Nota: " << promedioPonderado << endl;
                } else {
                    cout << "Lo sentimos, reprobo || Nota: " << promedioPonderado << endl;
                }
            }
            break;
        }
        case 2: 
        {
            int cantidadEstudiantes, cantidadNotas;
            do {
                cout << "Cantidad Estudiantes: ";
                cin >> cantidadEstudiantes;
            } while (cantidadEstudiantes < 1);

            do {
                cout << "Cantidad de Notas: ";
                cin >> cantidadNotas;
            } while (cantidadNotas < 1);
            
            float valorCadaNota = (100 / cantidadNotas);

            float sumaNotasTotal = 0.0;

            for (int estudiante = 0; estudiante < cantidadEstudiantes; estudiante++) {
                float promedioEstudiante = 0.0;
                cout << endl;
                cout << "Estudiante " << estudiante + 1 << endl;

                for (int nota = 0; nota < cantidadNotas; nota++) {
                    float notaEstudiante;
                    cout << "Nota No. " << nota + 1 << ": ";
                    cin >> notaEstudiante;

                    promedioEstudiante += (notaEstudiante * (valorCadaNota / 100));
                }
                cout << endl;
                sumaNotasTotal += promedioEstudiante;
            }
            float promedioGeneral = sumaNotasTotal / cantidadEstudiantes;
            cout << "Promedio General: " << promedioGeneral << endl;
            break;
        }
        case 3:
        {
            float notaPrimerCorte, notaSegundoCorte, notaTercerCorte;
            float porcentajePrimerCorte, porcentajeSegundoCorte, porcentajeTercerCorte;

            cout << "Nota del Primer Corte: ";
            cin >> notaPrimerCorte;
            cout << "Valor del Primer Corte (0-100%): ";
            cin >> porcentajePrimerCorte;

            cout << "Nota del Segundo Corte: ";
            cin >> notaSegundoCorte;
            cout << "Valor del Segundo Corte (0-100%): ";
            cin >> porcentajeSegundoCorte;

            cout << "Valor del Tercer Corte (0-100%): ";
            cin >> porcentajeTercerCorte;

            if ((porcentajePrimerCorte + porcentajeSegundoCorte + porcentajeTercerCorte) != 100) {
                cout << "La sumatoria de los porcentajes de cada corte es diferente de 100" << endl;
            } else {
                notaTercerCorte = (3.0 - (notaPrimerCorte * (porcentajePrimerCorte / 100)) - (notaSegundoCorte * (porcentajeSegundoCorte / 100)))/ (porcentajeTercerCorte / 100);
                cout << "Debe sacar un " << notaTercerCorte << " para aprobar la materia con 3.0";
            }
            break;
        }
        default:
            cout << "Ok" << endl;
            exit(0);
            break;
    }
    return 0;
}