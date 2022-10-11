#include <iostream>
#include <vector>

int mainMenu() {
    int opcion;
    std::cout << std::endl;
    std::cout << "Menu Opciones" << std::endl;
    std::cout << "[1]  Mostrar el mayor numero del vector A" << std::endl;
    std::cout << "[2]  Llenar y mostrar el vector B" << std::endl;
    std::cout << "[3]  Promedio del vector B" << std::endl;
    std::cout << "[4]  Cantidad de veces que se repite un nombre en el vector C" << std::endl;
    std::cout << "[5]  Convertir a 0 los elementos mayores a 5 en el vector A" << std::endl;
    std::cout << "Ingrese 0 para salir" << std::endl;
    std::cout << "-> ";
    std::cin >> opcion;

    return opcion;
}

void mayorVectorA(std::vector <float> vectorA) {
    float mayorNumero = 0.0;

    for (int i : vectorA) {
        if (i > mayorNumero)
            mayorNumero = i;
    }

    std::cout << "Numero Mayor: " << mayorNumero << std::endl;
}

void llenarVector(std::vector <float> &vectorB) {
    int cantidadDatos;

    do {
        std::cout << "Ingrese la cantidad de datos: ";
        std::cin >> cantidadDatos;
    } while (cantidadDatos < 1);

    for (int i = 0; i < cantidadDatos; i++) {
        float aux;
        std::cout << "[ " << i + 1 << "] Ingrese un numero: ";
        std::cin >> aux;

        vectorB.push_back(aux);
    }

    std::cout << std::endl;

    std::cout << "Datos almacenados" << std::endl;
    for (int i : vectorB)
        std::cout << i << " ";
    
    std::cout << std::endl;
}

void promedioVector(std::vector <float> &vectorB) {
    if (!vectorB.empty()) {
        float sumaTotal = 0.0;
        for (int i : vectorB) 
            sumaTotal += i;
        
        float promedio = sumaTotal / vectorB.size();

        std::cout << "Promedio Vector B: " << promedio << std::endl;
    } else {
        std::cout << "El vector B no tiene datos almacenados" << std::endl;
    }
}

void numeroVeces (std::vector <std::string> vectorC) {
    std::cout << std::endl;

    std::string nombreBuscar;
    std::cout << "Nombre a buscar: ";
    std::cin >> nombreBuscar;

    bool nombreEnArray = false;
    for (std::string i : vectorC) {
        if (nombreBuscar == i) {
            nombreEnArray = true;
        }
    }

    if (nombreEnArray) {
        int cantidadVeces = 0;
        for (std::string i : vectorC) {
            if (nombreBuscar == i)
                cantidadVeces++;
        }
        
        std::cout << "Cantidad de veces: " << cantidadVeces << std::endl;
    } else {
        std::cout << "El nombre no se encuentra en el array" << std::endl;
    }
}

void convertirCero(std::vector <float> vectorA) {
    for (int i = 0; i < vectorA.size(); i++) {
        if (vectorA.at(i) > 5)
            vectorA.at(i) = 0;
    }

    for (int i : vectorA) 
        std::cout << i << std::endl;
}

int main() {
    std::vector <float> vectorA = {8, 3, 6, 50, 42, 35, 29, 33, 12, 4.4};
    std::vector <float> vectorB;
    std::vector <std::string> vectorC = {"Carlos", "Sebastian", "Antonio", "Jesus", "Antonio", "Antonio", "Luis"};

    do {
        switch (mainMenu()) {
            case 1: 
                mayorVectorA(vectorA); break;
            
            case 2: 
                llenarVector(vectorB); break;
            
            case 3: 
                promedioVector(vectorB); break;
            
            case 4:
                numeroVeces(vectorC); break;
            
            case 5:
                convertirCero(vectorA); break;
            
            default: 
                exit(EXIT_FAILURE);
        }
    } while (true);


    return 0;
}