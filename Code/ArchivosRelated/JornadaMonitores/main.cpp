#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include "monitor.h"
#include "functions.h"
#include "search_info.h"

namespace fs = std::filesystem;

const std::string folderPath = "./JornadaMonitores/files/";

std::vector <Monitor> monitorList;


void initialize() {
    if (!directoryExists(folderPath)) { 
        std::cout << "[ INFO ] Error en el directorio" << std::endl;
    }
    
    readFile(folderPath, monitorList);

    SearchInfo searchInfo;

    std::cout << "Ingrese el [ ID ] del monitor: ";
    std::cin >> searchInfo.ID;

    std::cout << "Ingrese el [ Dia ] que desea buscar: ";
    std::cin >> searchInfo.day;

    std::transform(searchInfo.day.begin(), searchInfo.day.end(), searchInfo.day.begin(), ::tolower);
    searchInfo.day.erase(std::remove_if(searchInfo.day.begin(), searchInfo.day.end(), ::isspace), searchInfo.day.end());

    searchMonitor(monitorList, searchInfo);
}

int main(void) {
    initialize();
    return EXIT_SUCCESS;
}