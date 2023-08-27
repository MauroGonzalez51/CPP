#include "functions.h"

const std::string fileName = "data.csv";

void clearInputStreamBuffer() { 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool directoryExists(const std::string& folderPath) {
    bool isValid = false;

    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                std::cout << std::endl << "[ INFO ] Archivo encontrado: " << entry.path() << std::endl << std::endl;
            }
        }

        isValid = true;
    } else {
        std::cout << "[ INFO ] Ruta no encontrada " << folderPath << std::endl;
    }

    return isValid;
}

void readFile(const std::string& folderPath, std::vector<Monitor>& monitorList) {
    std::string line;
    char delimiter = ',';

    std::ifstream dataFile(folderPath + fileName);

    if (!dataFile.is_open()) {
        std::cout << "[ Error ] Archivo no encontrado " << fileName << std::endl;
        return;
    }

    std::getline(dataFile, line);
    while (std::getline(dataFile, line)) {
        std::stringstream streamLine(line);

        std::string id, firstName, lastName, subjectName, daysList;
        std::vector<std::string> daysVector;

        std::getline(streamLine, id, delimiter);
        std::getline(streamLine, firstName, delimiter);
        std::getline(streamLine, lastName, delimiter);
        std::getline(streamLine, subjectName, delimiter);
        std::getline(streamLine, daysList, delimiter);

        std::stringstream dayStream(daysList);

        std::string day;

        while (std::getline(dayStream, day, '|')) {
            daysVector.push_back(day);
        }

        monitorList.emplace_back(id, firstName, lastName, subjectName, daysVector);
    }

    dataFile.close();
}

bool checkCase(Monitor monitor, SearchInfo searchInfo) {
    bool isValid = false;

    if (monitor.getID() == searchInfo.ID) {
        const std::vector<std::string>& days = monitor.getDaysList();
        for (const auto& day : days) {
            if (day == searchInfo.day) {
                isValid = true;
                break;
            }
        }
    }

    return isValid;
}

void convertToInt(const std::string& str, int& result) {
    try {
        result = std::stoi(str);
    } catch (const std::exception& e) {
        std::cout << "[ ERROR ] " << e.what() << std::endl;
        result = -1;
    }
}

void searchMonitor(std::vector<Monitor>& monitorList, SearchInfo searchInfo) {
    std::vector<Monitor> coincidences;

    int left = 0, right = monitorList.size() - 1;

    int searchID;
    convertToInt(searchInfo.ID, searchID);

    while (left <= right) {
        int position = left + (right - left) / 2;

        int monitorID;
        convertToInt(monitorList.at(position).getID(), monitorID);

        if (checkCase(monitorList.at(position), searchInfo)) {
            coincidences.push_back(monitorList.at(position));
        }

        (monitorID < searchID) ? left = position + 1 : right = position - 1;
    }

    if (coincidences.size() == 0) { 
        std::cout << std::endl << "[ INFO ] No se encontraron monitores" << std::endl << std::endl;
        return;
    }

    for (int i = 0; i < coincidences.size(); i++) {
        std::cout << std::endl;
        std::cout << "[ " << i + 1 << " ] ---------------------------" << std::endl;
        std::cout << "Monitor ID: " << coincidences.at(i).getID() << std::endl;
        std::cout << "Dias de la semana: ";

        const std::vector<std::string>& days = coincidences.at(i).getDaysList();

        for (auto &day : days) {
            std::cout << day << " | ";
        }

        std::cout << std::endl;
    }
}

