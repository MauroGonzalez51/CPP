#include <iostream>

using namespace std;

// prototipo de funciones
float calcularDefinitiva(float parcial, float quices, float trabajos);

string aprueba(float notaFinal);

bool validarNotas(float nota);

int main() {
    float notaP, quices, trabajos;

    // Hay que validar las notas ...
    do {
        cout << "Digite la nota del parcial del estudiante: ";
        cin >> notaP;
    } while (!validarNotas(notaP));

    do {
        cout << "Digite la nota del quiz: ";
        cin >> quices;
    } while (!validarNotas(quices));

    do {
        cout << "Digite la nota del taller del estudiante: ";
        cin >> trabajos;
    } while (!validarNotas(trabajos));

    float notaFinal = calcularDefinitiva(notaP, quices, trabajos);
    cout << aprueba(notaFinal) << " su nota final es de " << notaFinal;

    return 0;
}

float calcularDefinitiva(float parcial, float quices, float trabajos) {
    float notaFinal = (parcial * 0.5) + (quices * 0.3) + (trabajos * 0.2);
    return notaFinal;
}

string aprueba(float notaFinal) {
    if (notaFinal >= 3.0)
        return ("APRUEBA");
    else
        return ("NO APRUEBA");
}

bool validarNotas (float nota) {
    // Retornar true significa que la nota es valida
    if ((nota >= 0) && (nota <= 5.0))
        return true;
    else
        return false;
}