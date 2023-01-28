
// ! Pedir n calificaciones y asignarlas en un arreglo dinamico

#include <bits/stdc++.h>

int numeroCalificaciones, *calificaciones;

void pedirCantidadNotas() {
    do {
        std::cout << "Ingrese el numero de calificaciones: ";
        std::cin >> numeroCalificaciones;
    } while (numeroCalificaciones < 0);
}

void reservarMemoria() {
    // * Creando el arrreglo de tipo dinamico
    calificaciones = new int[numeroCalificaciones];
}

void pedirNotas() {
    for (int i = 0; i < numeroCalificaciones; i++) {
        std::cout << "[" << i + 1 << "] Ingrese una nota: ";
        std::cin >> calificaciones[i];
    }
}

void mostrarNotas() {
    std::cout << std::endl << std::endl;
    for (int i = 0; i < numeroCalificaciones; i++) 
        std::cout << calificaciones[i] << " ";
}

void liberarMemoria() { delete[] calificaciones; }

int main(void) {
    pedirCantidadNotas();
    reservarMemoria();
    pedirNotas();
    mostrarNotas();
    liberarMemoria();
    return EXIT_SUCCESS;
}