#include <iostream>
#include <vector>

void llenarVector(std::vector <float> &numeros, int& cantidadDatos) {
    for (int i = 0; i < cantidadDatos; i++) {
        float aux;
        std::cout << "[ " << i + 1 << " ] Ingrese un valor: ";
        std::cin >> aux;
        numeros.push_back(aux);
    }
}

void ordenarVector(std::vector <float> &numeros) {
    for (int dato = 0; dato < numeros.size() - 1; dato++) {
        for (int iteracion = 0; iteracion < numeros.size() - 1; iteracion++) {
            if (numeros[iteracion] > numeros[iteracion + 1]) {
                float aux = numeros[iteracion + 1];
                numeros[iteracion + 1] = numeros[iteracion];
                numeros[iteracion] = aux;
            }
        }
    }

    std::endl;
    std::cout << "Vector final [Ordenado Ascendentemente]" << std::endl;
    for (float &i : numeros)
        std::cout << i << " ";
}

int main() {
    int cantidadDatos;

    do {
        std::cout << "Ingrese la cantidad de datos: ";
        std::cin >> cantidadDatos;
    } while (cantidadDatos < 1);

    std::vector <float> numeros;
 
    llenarVector(numeros, cantidadDatos);

    ordenarVector(numeros);

    return EXIT_SUCCESS;
}