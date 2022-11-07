#include <bits/stdc++.h>

const std::string folderPath = "JornadaTrabajadores/files/";

// ------------------------- WORKER CLASS --------------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

// Description: This class is responsible for taking the code, hoursOfWork ..., pack'em in a string ant then write it to the file 

class Worker {
    private:
        std::string code;
        int daysOfWorkPerMonth;
        float totalHoursOfWork = 0;

        // ----------------------------------------------------------------------------------------------------------| >

        void writeLine(const std::string c, const int quantityCaracters) {
            std::cout << std::endl;
            for (int i = 0; i < quantityCaracters; i++)
                std::cout << c;
            std::cout << std::endl;
        }

        // ---------------------------------------------------------------| >
        
        void clearBuffers() {
            fflush(stdin);
        }
    
        // ----------------------------------------------------------------------------------------------------------| >

    public:
        Worker(int workersCount) {
            this -> writeLine("-", 50);
            std::cout << "Trabajador [" << workersCount << "]" << std::endl;

            std::cout << "Ingrese su codigo: ";
            std::cin >> this -> code;

            std::cout << "Ingrese la cantidad de dias trabajados al mes: ";
            std::cin >> this -> daysOfWorkPerMonth;

            for (int day = 0; day < this -> daysOfWorkPerMonth; day++) {
                float tempValue;
                std::cout << "Ingrese la cantidad de Horas Trabajadas [Dia " << day + 1 << "]: ";
                std::cin >> tempValue;

                this -> totalHoursOfWork += tempValue;
                clearBuffers();
            }
        }

        // ----------------------------------------------------------------------------------------------------------| >

        bool writeToFile() {
            int dataWritten = false;
            std::ofstream dataFile (folderPath + "dataFile.csv", std::ios::app);
            if (dataFile.is_open()) {
                dataFile << this -> code << "," << this -> totalHoursOfWork << "," << this -> daysOfWorkPerMonth << std::endl;
                dataWritten = true;
            }
            return dataWritten;
        }

        // ----------------------------------------------------------------------------------------------------------| >

        bool validateMsg(char msg[3]) {
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
};

// ------------------------- LOOP TO ASK DATA ----------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

// Description: this block is just for asking data to then it'll be written to a .csv file

void workerLoop() {
    // Falta pedir los datos para cada dia del mes
    int workersCount = 0;
    do {
        workersCount++;
        Worker* worker = new Worker(workersCount);
        (worker -> writeToFile()) ?
            std::cout << "[INFO] Datos guardados correctamente" << std::endl :
                std::cout << "[INFO] Error al momento de guardar los datos" << std::endl;
        
        char msg[3];
        std::cout << "Nuevo trabajador?" << std::endl;
        std::cout << "-> ";
        std::cin >> msg;

        if (!worker -> validateMsg(msg)) break;
    } while (true);
}

// ------------------------- STRUCT MODULE -------------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

// Description: Creating a struct, so all the data readed from file will be writed here

struct {
    std::vector <std::string> code;
    std::vector <float> totalHoursOfWork;
    std::vector <int> daysOfWorkPerMonth;
} allWorkersInfo;

// ----------------------------------------------------------------------------------------------------------| >

// ---------------------------------------------------------|

void writeLine(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

// ---------------------------------------------------------|


void readData() {
    std::string line;
    char delimiter = ',';
    std::ifstream dataFile (folderPath + "dataFile.csv");

    if (dataFile.is_open()) {
        std::getline(dataFile, line);
        while (std::getline(dataFile, line)) {
            std::stringstream streamLine (line);

            std::string code, totalHours, daysOfWork;
            std::getline(streamLine, code, delimiter);
            std::getline(streamLine, totalHours, delimiter);
            std::getline(streamLine, daysOfWork, delimiter);

            allWorkersInfo.code.push_back(code);
            allWorkersInfo.totalHoursOfWork.push_back(std::stof(totalHours));
            allWorkersInfo.daysOfWorkPerMonth.push_back(std::stoi(daysOfWork));
        }
    }
}

void showDataStored() {
    std::cout << std::endl;
    for (int i = 0; i < allWorkersInfo.code.size(); i++) {
        writeLine("*");
        std::cout << "Worker Code: " << allWorkersInfo.code.at(i) << std::endl;
        std::cout << "Total Hours: " << allWorkersInfo.totalHoursOfWork.at(i) << std::endl;
        std::cout << "Days of Work: " << allWorkersInfo.daysOfWorkPerMonth.at(i) << std::endl;
    }
}



// ------------------------- MAIN FUNCTION -------------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

int main(void) {
    workerLoop();
    readData();
    showDataStored();    
    return EXIT_SUCCESS;
}