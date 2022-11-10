#include <bits/stdc++.h>

void ordenarAscendente(std::vector <std::string> codigos, std::vector <double> notas) {
    for (int dato = 0; dato < codigos.size() - 1; dato++) {
        for (int iteracion = 0; iteracion < codigos.size() - 1; iteracion++) {
            if (notas[iteracion] > notas[iteracion + 1]) {
                float aux = notas[iteracion + 1];
                notas[iteracion + 1] = notas[iteracion];
                notas[iteracion] = aux;
            }
        }
    }

    std::cout << "Codigo  | Nota" << std::endl;
    for (int i = 0; i < codigos.size(); i++)
        std::cout << codigos[i] << "       " << notas[i] << std::endl;
}
 
void ordenarDescentente(std::vector <std::string> codigos, std::vector <double> notas) {
    for (int dato = 0; dato < codigos.size() - 1; dato++) {
        for (int iteracion = 0; iteracion < codigos.size() - 1; iteracion++) {
            if (notas[iteracion] < notas[iteracion + 1]) {
                float aux = notas[iteracion + 1];
                notas[iteracion + 1] = notas[iteracion];
                notas[iteracion] = aux;
            }
        }
    }

    std::cout << "Codigo  | Nota" << std::endl;
    for (int i = 0; i < codigos.size(); i++)
        std::cout << codigos[i] << "     | " << notas[i] << std::endl;
}

void encontrarModa(std::vector <std::string> codigos, std::vector <double> notas) {
    float notaModa;
    int cantidadMayorVeces = 0;

    for (int dato = 0; dato < codigos.size(); dato++) {
        int cantidadVeces = 0;
        for (int iteracion = 0; iteracion < codigos.size(); iteracion++) {
            if (notas[dato] == notas[iteracion])
                cantidadVeces++;
        }

        if (cantidadVeces > cantidadMayorVeces) {
            cantidadMayorVeces = cantidadVeces;
            notaModa = notas[dato];
        }
    }

    std::cout << "Nota Moda: " << notaModa << std::endl;
    std::cout << "Cantidad de veces que se repite: " << cantidadMayorVeces << std::endl;
    std::cout << "Estudiantes con esta nota" << std::endl;
    for (int i = 0; i < codigos.size(); i++) {
        if (notas[i] == notaModa)
            std::cout << codigos[i] << "       " << notas[i] << std::endl;
    }
}

int mainMenu() {
    int opcion;
    std::cout << std::endl;
    std::cout << "Registro Notas" << std::endl;
    std::cout << "1. Ordenar notas Ascendentemente" << std::endl;
    std::cout << "2. Ordenar notas Descendentemente" << std::endl;
    std::cout << "3. Nota Moda" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "-> ";
    std::cin >> opcion;

    return opcion;
}

int main() {
    std::vector <std::string> codigosEstudiantes = {"T01", "T02", "T03", "T04", "T05", 
        "T06", "T07", "T08", "T09", "T10", "T11", "T12", "T13", 
        "T14", "T15", "T16", "T17", "T18", "T19", "T20", "T21", 
        "T22", "T23", "T24", "T25",  "T26", "T27", "T28", "T29", 
        "T30", "T31", "T32", "T33", "T34", "T35", "T36", "T37", 
        "T38", "T39", "T40", "T41", "T42", "T43", "T44", "T45", 
        "T46", "T47", "T48", "T49", "T50",  "T51", "T52", "T53", 
        "T54", "T55", "T56", "T57", "T58", "T59", "T60"} ;

    std::vector <double> definitivasEstudiantes = {3.9, 4.0, 3.9, 3.6, 3.7, 4.0, 3.7, 
        4.3, 4.3, 4.9, 5.0, 0.5, 3.0, 4.3, 3.7, 3.0, 4.6, 4.6, 5.0, 
        3.0, 5.0, 4.9, 3.2, 3.7, 4.3, 4.6, 3.6, 5.0, 3.2, 4.6, 3.3, 
        5.0, 3.3, 3.3, 1.7,   2.5, 4.2, 3.3, 5.0, 4.2, 2.5, 2.5, 3.3, 
        3.3, 4.2, 4.2, 3.3, 3.3, 3.3, 4.2, 4.2, 3.3, 5.0, 0.8, 3.3, 
        3.3, 3.3, 3.3, 2.5, 3.8};

    do {
        switch (mainMenu()) {
            case 1: 
                ordenarAscendente(codigosEstudiantes, definitivasEstudiantes); break;

            case 2: 
                ordenarDescentente(codigosEstudiantes, definitivasEstudiantes); break;

            case 3:
                encontrarModa(codigosEstudiantes, definitivasEstudiantes); break;

            case 4:
                exit(EXIT_SUCCESS); break;

            default:
                std::cout << "Opcion no encontrada" << std::endl; 
        }
    } while (true);

    return EXIT_SUCCESS;
}