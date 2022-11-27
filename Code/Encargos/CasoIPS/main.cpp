#include <bits/stdc++.h>

struct Paciente {
    std::string numeroIdentificacion, nombrePaciente, codigoEmpresa, fechaExamen = "";
    int edad, intGenero, tipoExamen;
    float estatura, peso;
    std::string stringGenero;

    struct {
        float frecuenciaCardiaca, presionSistolica, precionDiastolica, IMC;
        std::string factorDeRiesgo;
    } datosMedicos;
};

#include "llenarDatos.h"
#include "registroDatos.h"
#include "analisisDatos.h"

void escribirLinea(const int n, const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << c;
    std::cout << std::endl;
}

bool validarMensaje(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    std::array <std::string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0){
                Flag = false;
            }
        }
    }
    return Flag;
}

void clearBuffers() { fflush(stdin); }
void tabularDatos(Paciente &paciente);
void analizarDatos();

void mainMenu() {
    escribirLinea(50, "*");
    std::cout << "Sistema MEGASALUD IPS" << std::endl;
    std::cout << std::endl << std::endl;
    do {
        Paciente paciente;
        llenarStruct(paciente);
        tabularDatos(paciente);
        char msg[3];
        std::cout << "Desea agregar otro paciente?" << std::endl;
        std::cout << "-> ";
        std::cin >> msg;

        if (!validarMensaje(msg))
            break;

    } while (true);
} 

int main(void) {
    mainMenu();
    std::cout << "Procediendo a hacer el analisis de datos" << std::endl;
    analizarDatos();
    return EXIT_SUCCESS;
}