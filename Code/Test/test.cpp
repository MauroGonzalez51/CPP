#include <bits/stdc++.h>

int main() {
    std::tipoArchivo identificador ("nombreArchivo.txt", metodoApertura);


    std::ifstream datosAlmacenados ("datosAlmacenados.csv");

    std::ofstream registroDatos;

    registroDatos.open("datos.txt", std::ios::app);

    if (registroDatos.is_open())
        std::cout << "El Archivo se abrio correctamente" << std::endl;
    // ................

    // ................

    registroDatos.close();

}