#include <bits/stdc++.h>

const int cantidadNumeros = 10;

int numeros[10];

bool numeroEsPar(int numero) { return ((numero % 2 == 0) ? true : false); }

void llenarDatos() {
    for (int i = 0; i < cantidadNumeros; i++) {
        std::cout << i + 1 << ") Ingrese un numero: ";
        std::cin >> numeros[i];
    }
}

void numerosPares() {
    std::cout << std::endl << "Numeros Pares: " << std::endl;
    int *ptr = numeros;

    for (std::size_t i = 0; i < cantidadNumeros; i++) {
        if (numeroEsPar(*ptr)) {
            std::cout << "[ Numero: " << *ptr << " | Posicion: " << ptr << " ]" << std::endl;
        }
        ptr++;
    }
}

int main(void) {
    llenarDatos();
    numerosPares();
    return EXIT_SUCCESS;
}