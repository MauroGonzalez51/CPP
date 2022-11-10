#include <bits/stdc++.h>

struct Provedores {
    std::string nombre;
    int cantidadVendida;
    float precioUnidad;
    double importeTotal;
};

int cantidadProvedores;

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

int main(void) {
    do {
        std::cout << "Ingrese la cantidad de provedores: ";
        std::cin >> cantidadProvedores;
    } while (cantidadProvedores < 1);

    Provedores provedores[cantidadProvedores];

    for (int i = 0; i < cantidadProvedores; i++) {
        escribirLinea("-");
        std::cout << "[ Provedor " << i + 1 << " ]" << std::endl;

        std::cout << "Escriba su nombre: ";
        std::cin >> provedores[i].nombre;

        std::cout << "Cantidad Vendida: ";
        std::cin >> provedores[i].cantidadVendida;

        std::cout << "Precio por Unidad: ";
        std::cin >> provedores[i].precioUnidad; 

        provedores[i].importeTotal = provedores[i].cantidadVendida * provedores[i].precioUnidad;
    }

    double mayorImporte = 0.0;
    int indice;
    for (int i = 0; i < cantidadProvedores; i++) {
        if (provedores[i].importeTotal > mayorImporte) {
            mayorImporte = provedores[i].importeTotal;
            indice = i;
        }
    }

    for (int i = 0; i < cantidadProvedores; i++) {
        escribirLinea("*");
        std::cout << "Nombre Provedor: " << provedores[i].nombre << std::endl;
        std::cout << "Cantidad Vendida: " << provedores[i].cantidadVendida << std::endl;;
        std::cout << "Precio Unidad: " << provedores[i].precioUnidad << std::endl;;
        std::cout << "Importe Total: " << provedores[i].importeTotal << std::endl;;
    }

    std::cout << std::endl << std::endl;
    std::cout << "Mayor Importe Total: " << provedores[indice].importeTotal << std::endl;
    std::cout << "Nombre del Provedor: " << provedores[indice].nombre << std::endl;

    return EXIT_SUCCESS;
}