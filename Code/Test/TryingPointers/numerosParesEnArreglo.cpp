#include <bits/stdc++.h>

std::vector <int> vectorNumeros;

void llenarArray() {
    unsigned int cantidadNumeros;
    
    do {
        std::cout << "Ingrese la cantidad de numeros: ";
        std::cin >> cantidadNumeros;
    } while (cantidadNumeros < 0);

    for (int i = 0; i < cantidadNumeros; i++) {
        double auxValue;
        std::cout << "[" << i + 1 << "] Ingrese un numero: ";
        std::cin >> auxValue;

        vectorNumeros.push_back(auxValue);
    }
}

void numerosPares() {
    std::cout << "Numeros pares: [ ";
    for (auto it = vectorNumeros.begin(); it != vectorNumeros.end(); it++) {
        if (*it % 2 == 0) std::cout << *it << " ";
    }
    std::cout << "]";
}

int main(void) {
    llenarArray();
    numerosPares();

    return EXIT_SUCCESS;
}