#include <iostream>

const int cantidadEstudiantes = 20;

// -------------------------------------------------------------------------
struct Estudiantes {
    struct {
        float primerCorte, segundoCorte, tercerCorte, examenFinal;
    } notas;

    std::string nombreEstudiante;
};

Estudiantes estudiantes[cantidadEstudiantes];

void llenarDatos();
bool validarNota(const float notaEstudiante);
void calcularNotaFinal();
void mostrarDatos();

// -------------------------------------------------------------------------
int main() {
    std::cout << "Calcular la Nota del Examen Final" << std::endl;

    llenarDatos();
    calcularNotaFinal();
    mostrarDatos();

    return 0;
}

// -------------------------------------------------------------------------
void llenarDatos() {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        std::cout << std::endl << std::endl;
        std::cout << "Estudiante " << i + 1 << ": " << std::endl;
        std::cout << "Ingresa tu nombre: ";
        std::cin >> estudiantes[i].nombreEstudiante;

        do {
            std::cout << "Nota del PRIMER CORTE: ";
            std::cin >> estudiantes[i].notas.primerCorte;
        } while (!validarNota(estudiantes[i].notas.primerCorte));

        do {
            std::cout << "Nota del SEGUNDO CORTE: ";
            std::cin >> estudiantes[i].notas.segundoCorte;
        } while (!validarNota(estudiantes[i].notas.segundoCorte));

        do {
            std::cout << "Nota del TERCER CORTE: ";
            std::cin >> estudiantes[i].notas.tercerCorte;
        } while (!validarNota(estudiantes[i].notas.tercerCorte));
    }
}

bool validarNota(const float notaEstudiante) {
    bool esValida = false;
    if ((notaEstudiante >= 0) && (notaEstudiante <= 5))
        esValida = true;

    return esValida;
}

void calcularNotaFinal() {
    for (int i = 0; i < cantidadEstudiantes; i++) 
        estudiantes[i].notas.examenFinal = (3.0 - ((0.25 * estudiantes[i].notas.primerCorte) + (0.25 * estudiantes[i].notas.segundoCorte) + (0.2 * estudiantes[i].notas.tercerCorte))) / (0.3);
}

void mostrarDatos() {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        std::cout << std::endl;
        for (int j = 0; j < 40; j++) 
            std::cout << "-";
        std::cout << std::endl;

        std::cout << "Estudiante [" << i + 1 << "]: " << estudiantes[i].nombreEstudiante << std::endl;
        std::cout << "Nota Minima EXAMEN FINAL: " << estudiantes[i].notas.examenFinal << std::endl;
    }
}