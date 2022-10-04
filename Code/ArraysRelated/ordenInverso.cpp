#include <bits/stdc++.h>

int main() {

    int cantidad;
    std::cout << "Ingrese la cantidad: ";
    std::cin >> cantidad;

    int numeros[cantidad];
    for (int i = 0; i < cantidad; i++) {
        std::cout << "-> ";
        std::cin >> numeros[i];
    }

    for (int i = cantidad - 1; i >= 0; i--)
        std::cout << numeros[i] << std::endl;

    return EXIT_SUCCESS;
}