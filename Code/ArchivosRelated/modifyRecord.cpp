#include <bits/stdc++.h>
#define filePath "Code/ArchivosRelated/.CSV/test.csv"

/*
    Notas ...
        !IMPORTANT:
            - usar archivo.is_open() para verificar de que el archivo se abrio
                correctamente, despues de eso usar un try o cualquier wea que 
                quieras uwu
*/

int mainMenu() {
    unsigned int choice;
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Modificar un registro" << std::endl;
    std::cout << std::endl << "-> ";
    std::cin >> choice;

    return choice;
}

void modificarRegistro() {
    std::ifstream dataFile (filePath, std::ios::in);
    std::string nombreUsuario, edadUsuario, cedulaUsuario;
    std::string nombreUsuarioAux, cedulaUsuarioAux;

    std::ofstream dataFileAux ("dataFileAux.txt", std::ios::app);

    if (dataFile.is_open()) {
        std::cout << "Cedula: ";
        std::cout << std::endl << "-> ";
        std::cin >> cedulaUsuarioAux;

        dataFile >> nombreUsuario;
        while (!dataFile.eof()) {
            dataFile >> edadUsuario;
            dataFile >> cedulaUsuario;

            if (cedulaUsuario == cedulaUsuarioAux) {
                std::cout << "Nuevo Nombre: ";
                std::cout << std::endl << "-> ";
                std::cin >> nombreUsuarioAux;

                dataFileAux << nombreUsuarioAux << "," << edadUsuario << "," << cedulaUsuarioAux << std::endl;
            } else
                dataFileAux << nombreUsuario << "," << edadUsuario << "," << cedulaUsuarioAux << std::endl;

        }

        dataFile.close(); dataFileAux.close();
    } else 
        std::cout << "Error" << std::endl; 

    remove(filePath);
    rename("dataFileAux.txt", "dataFile.txt");
}

int main() {
    do {
        switch (mainMenu()) {
            case 1: {
                modificarRegistro();
                break;
            }
            default:
                exit(EXIT_SUCCESS);
        }
    } while (true);

    return EXIT_SUCCESS;
}