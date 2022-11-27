#include <bits/stdc++.h>

bool validarMensaje(const std::string mensajeIngresado) {
    bool esValido = false;
    std::vector <std::string> opcionesValidasTrue = {"Si", "si", "SI", "S", "s", "y", "Y", "YES", "yes", "Yes"};
    for (auto &opcion : opcionesValidasTrue) { if (mensajeIngresado == opcion) esValido = true; }
    return esValido;
}

int main(void) {
    std::string msgSalida;

    do {
        std::cout << "-> ";
        std::cin >> msgSalida;

        std::cout << std::boolalpha << validarMensaje(msgSalida) << std::endl;

        if (validarMensaje(msgSalida))
            break;
    } while (true);


    return EXIT_SUCCESS;
}