#include <bits/stdc++.h>

bool readingFile(std::vector <float> &dataVector, std::vector <std::string> &dataVectorParseString, const std::string folderPath) {
    bool success = false;
    std::ifstream dataFile (folderPath + "standard-3dZ.csv");

    // Opening the file and saving all the lines in one vector
    if (dataFile.is_open()) {
        std::string line;
        // Here ...
        while (std::getline(dataFile, line))
            dataVectorParseString.push_back(line);
    }
    
    // Then, converting all the lines stored "string", to values
    for (std::string &dataString : dataVectorParseString) {
        std::stringstream streamLine (dataString);
        std::string line;
        char delimiter = ',';

        while (std::getline(streamLine, line, delimiter))
            dataVector.push_back(std::stof(line));
        success = true;
    }

    dataFile.close();
    return success;
}