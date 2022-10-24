#include <bits/stdc++.h>

int main() {

    std::ifstream archivoDatos ("datos.txt");

    std::string linea;
    char delimitador[] = ',';
    std::vector <std::string> datos;

    while (getline(archivoDatos, linea)) {
        std::stringstream ss(linea);

        std::string aux;

        getline(ss, aux, delimitador);

        datos.push_back(aux); 
    }

    archivoDatos.close();


    return EXIT_SUCCESS;
}