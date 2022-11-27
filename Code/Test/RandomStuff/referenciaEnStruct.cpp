#include <bits/stdc++.h>

struct Persona {
    std::string codigo, nombre;
    int edad;
};

void llenarDatos(struct Persona &persona) {
    std::cout << std::endl;
    std::cout << "Ingrese su codigo: ";
    std::getline(std::cin, persona.codigo, '\n');

    std::cout << "Ingrese su nombre: ";
    std::getline(std::cin, persona.nombre, '\n');

    std::cout << "Ingrese su edad: ";
    std::cin >> persona.edad;
}

int main(void) {
    Persona persona;
    llenarDatos(persona);

    std::cout << persona.codigo << std::endl;

    return EXIT_SUCCESS;
}