#include <bits/stdc++.h>

bool numeroEsPar(int* numero) {
    return ((*numero % 2 == 0) ? true : false);
}

int main(void) {
    int numero, *numeroPtr = NULL;

    // * Pediendo el numero al usuario
    std::cout << "Ingrese un numero: ";
    std::cin >> numero;

    // * Guardando la posicion en memoria en un puntero (int)
    numeroPtr = (&numero);

    // * A la funcion se le manda la posicion en memoria -> Se interpreta como un puntero
    (numeroEsPar(numeroPtr)) ?
        // ! Despues se accede al valor usando *
        std::cout << "El numero es PAR" << std::endl :
            std::cout << "El numero es IMPAR" << std::endl;
    
    std::cout << "Direccion en Memoria: " << numeroPtr << std::endl;

    return EXIT_SUCCESS;
}