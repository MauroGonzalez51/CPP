#include <bits/stdc++.h>

// ! All the info about the analisis functions goes to the logFile

/**
 * TODO:
 *      * Buscar la moda, y media (promedio) *
 *      * Mediana *
 *      * BUSCAR POR CADA ARCHIVO NO EN TODO LOS DATOS *
 * 
 * 
 * 
 * 
*/

void writeLog(const std::string folderPath, const std::string message);

void readLocalData(const float &dataFileName, const std::string folderPath, std::vector <float> &localDataStorage) {
    const std::string categoriesFolderPath = folderPath + "categoryFiles/";

    std::ifstream dataFile (categoriesFolderPath + std::to_string(dataFileName) + ".txt");
    std::vector <std::string> localDataParseString;

    if (dataFile.is_open()) {
        std::string line;
        while (std::getline (dataFile, line))
            localDataParseString.push_back(line);
    }

    for (std::string &dataString : localDataParseString) {
        std::stringstream streamLine (dataString);
        std::string line;
        char delimiter = ',';

        while (std::getline (streamLine, line, delimiter)) 
            localDataStorage.push_back(std::stof(line)); //
    }
}


void findMode(std::vector <float> &filesName, const std::string folderPath) {
    int maxRepetitions = 0;
    float maxRepetitionsValue;
    for (auto &fileName : filesName) {
        std::vector <float> localDataStorage;
        readLocalData(fileName, folderPath, localDataStorage);

        for (float &data : localDataStorage) {
            int localRepetitions = 0;
            for (float &iteration : localDataStorage) {
                if (data == iteration) localRepetitions++;
            }

            if (localRepetitions > maxRepetitions) {
                maxRepetitions = localRepetitions;
                maxRepetitionsValue = data;
            }
        }
    }

    writeLog(folderPath, "Mode: " + std::to_string(maxRepetitionsValue) + " | " + std::to_string(maxRepetitions) + " times(s)");
}



void analizeDataMain(std::vector <float> &categoriesFilesName, const std::string folderPath) {
    // const std::string categoriesFolderPath = folderPath + "categoryFiles/";
    writeLog(folderPath, "Finding the Mode ...");
    findMode(categoriesFilesName, folderPath);
}