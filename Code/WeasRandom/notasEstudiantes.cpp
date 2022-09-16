/**
 * @grupo
 *      - Mauro Gonzalez T00067622
 *      - name
 *      - name
 * @descripcion
 *      Programa para calcular la nota definitiva de un estudiante
 */

#include <bits/stdc++.h>

using namespace std;

// Declarando los prototipos de funcion
bool validarNota(float nota);
bool salir(char msg[2]);
void datosFinales(int aprobados, int reprobados);
float notaDefinitiva(float notaParcial, float notaQuices, float notaTalleres);



int main() {
    // variable que controla la salida del programa
    char msgSalida[2];

    cout << endl;
    cout << "Programa para Calcular la Nota Definitiva Individual" << endl;
    cout << endl;

    // Variables de control
    int canEstAprobado = 0, canEstReprobado = 0, canEst = 0;;
    float sumNotasDefinitivas = 0.0;

    // Bucle que se repite "infinitas" veces, dependiendo de cuando queramos salir
    do {
        canEst += 1;
        float notaParcial, notaQuices, notaTalleres;

        cout << endl;
        // Pidiendo todos los datos, ademas de validarlos al momento
        do {
            cout << "Ingrese la nota de los Parciales [Estudiante " << canEst << "]: ";
            cin >> notaParcial;
        } while (validarNota(notaParcial));

        do {
            cout << "Ingrese la nota de los Quices [Estudiante " << canEst << "]: ";
            cin >> notaQuices;
        } while (validarNota(notaQuices));

        do {
            cout << "Ingrese la nota de los Trabajos o Talleres [Estudiante " << canEst << "]: ";
            cin >> notaTalleres;
        } while (validarNota(notaTalleres));

        // Determinando si el estudiante aprobo o no haciendo uso de condicionales
        float notaFinalEstudiante = notaDefinitiva(notaParcial, notaQuices, notaTalleres);
        if (notaFinalEstudiante >= 3.0) {
            canEstAprobado += 1;
            cout << "APRUEBA su nota es de " << notaFinalEstudiante << endl;
        }
        else {
            canEstReprobado += 1;
            cout << "NO APRUEBA su nota es de " << notaFinalEstudiante << endl;
        }

        // Incrementando la variable contador que lleva registro de los promedios
        sumNotasDefinitivas += notaFinalEstudiante;
        cout << "Salir?" << endl;
        cout << "-> ";
        cin >> msgSalida; 

        // Salida del Programa
        if (salir(msgSalida))
            break;

    } while (true);
    
    // Analizando los datos finales despues de que se sale del programa
    cout << endl;
    cout << "Promedio de Notas Definitivas -> " << sumNotasDefinitivas / canEst << endl;
    datosFinales(canEstAprobado, canEstReprobado);
    return 0;
}

// Funcion para validar si la nota esta entre 0.0 y 5.0
bool validarNota(float nota) {
    return ((nota >= 0.0) && (nota <= 5.0)) ? false : true;
}

// Funcion para simplemente mostrar por consola los datos finales
void datosFinales(int aprobados, int reprobados) {
    cout << endl;
    cout << "Datos Finales" << endl;
    cout << "Cantidad de estudiantes que APROBARON -> " << aprobados << endl;
    cout << "Cantidad de estudiantes que REPROBARON -> " << reprobados << endl; 
}

// Funcion para calcular la nota definitiva, haciendo uso de los parametros
float notaDefinitiva(float notaParcial, float notaQuices, float notaTalleres) {
    float nota = ((notaParcial * 0.5) + (notaQuices * 0.3) + (notaTalleres * 0.2));
    return nota;
}

// Funcion para controlar la salida, dependiendo de lo que usuario ingrese
bool salir(char msg[2]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    array <string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0){
                Flag = false;
            }
        }
    }
    return Flag;
}