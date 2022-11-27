#include <bits/stdc++.h>

const std::string filePath = "RandomStuff/Data.csv";

std::vector <int> dataStored;
std::vector <std::string> linesStored;

/**
 *  TODO: 
 *      Creas un vector de datos de tipo string en el que les todos las lineas del archivo 
 *      y las guardas ahí, luego volverias a leer cada una de las lineas para guardarlas  
 *      ahora si como numeros
 *      
 *      Puede ser mas tardado de esta manera, pero creo que es la solucion a seguir :>  
 * 
 * 
 * */

void readData() {
    std::ifstream dataFile (filePath);

    // Aqui se leen todas las lineas del archivo
    if (dataFile.is_open()) {
        std::string line;
        // Y aca se guardan en un arreglo de strings
        while (std::getline(dataFile, line))
            linesStored.push_back(line);
    }

    // std::cout << linesStored.at(0) << std::endl;

    // Ahora hay que separar cada una de esas lineas en pequeñas partes
    // que contienen los datos y luego guardarlos en otro arreglo 

    for (std::string &dataString : linesStored) {
        std::stringstream streamLine (dataString);
        std::string line;
        char delimiter = ',';

        while (std::getline (streamLine, line, delimiter))
            dataStored.push_back(std::stof(line));
    }

    int totalCount = 0;
    for (int &data : dataStored)
        totalCount += data;
    
    std::cout << totalCount << std::endl;
}


int main(void) {
    readData();
    return EXIT_SUCCESS;
}