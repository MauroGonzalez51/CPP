#include <bits/stdc++.h>

void buscarDivisores(int *numeroIngresado, std::vector <int> &divisores) {
    for (int i = 1; i < *numeroIngresado + 1; i++) {
        if (*numeroIngresado % i == 0) divisores.push_back(i);
    }
}

int main(void) {
    int numeroIngresado, *numeroPtr = NULL;
    std::vector <int> divisores;

    std::cout << "Ingrese un numero: ";
    std::cin >> numeroIngresado;

    numeroPtr = (&numeroIngresado);

    buscarDivisores(numeroPtr, divisores);

    std::cout << "Divisores: ";
    for (auto &numero : divisores) std::cout << numero << " ";
    std::cout << std::endl;

    (divisores.size() > 2) ?
        std::cout << "Numero COMPUESTO" << std::endl : 
            std::cout << "Numero PRIMO" << std::endl;
    
    std::cout << "Posicion en memoria: " << numeroPtr << std::endl;
 
    return EXIT_SUCCESS;
}