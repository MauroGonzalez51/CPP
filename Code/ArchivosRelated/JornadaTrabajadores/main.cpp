#include <bits/stdc++.h>


// Declarando una constante -> Ruta de la carpeta con el resto de archivos
const std::string folderPath = "JornadaTrabajadores/files/";

// ------------------------- WORKER CLASS --------------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

// Description: This class is responsible for taking the code, hoursOfWork ..., pack'em in a string ant then write it to the file 

// Clase que gestiona la entrada de la informacion de cada trabajador, ademas de ser la respondable de escribir esta misma informacion al archivo .csv
class Worker {
    private:
        std::string code;
        int daysOfWorkPerMonth;
        float totalHoursOfWork = 0;

        // ----------------------------------------------------------------------------------------------------------| >
            // Funcion para escribir una linea en consola
        void writeLine(const std::string c, const int quantityCaracters) {
            std::cout << std::endl;
            for (int i = 0; i < quantityCaracters; i++)
                std::cout << c;
            std::cout << std::endl;
        }

        // ---------------------------------------------------------------| >
            // Funcion para limpiar el buffer
        void clearBuffers() {
                // std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            fflush(stdin);
        }
    
        // ----------------------------------------------------------------------------------------------------------| >

    public:
            // Constructor de la clase -> Inicializar el codigo, dias y horas de cada trabajador
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
            // Funcion encargada especificamente de escribir informacion al archivo .csv
        bool writeToFile() {
            int dataWritten = false;
            std::ofstream dataFile (folderPath + "dataFile.csv", std::ios::app);
            if (dataFile.is_open()) {
                dataFile << this -> code << "," << this -> totalHoursOfWork << "," << this -> daysOfWorkPerMonth << std::endl;
                dataWritten = true;
            }
            dataFile.close();
            return dataWritten;
        }

        // ----------------------------------------------------------------------------------------------------------| >
            // Funcion encargada de validar la salida, para despues proceder con el analisis de datos
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
    // Loop en el que se piden los datos :>
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

// ------------------------- STRUCT / ANALIZE DATA MODULE ----------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >

// Description: Creating a struct, so all the data readed from file will be writed here

// Struct en el que se guardan todo los datos leidos del archivo
    // !IMPORTANT -> El struct tiene que ser anonimo para que peuda tener un scope global
struct {
    std::vector <std::string> code;
    std::vector <float> totalHoursOfWork;
    std::vector <int> daysOfWorkPerMonth;
} allWorkersInfo;

// ----------------------------------------------------------------------------------------------------------| >

// ---------------------------------------------------------|
    // Funcion para escribir una linea en consola -> con escope global
void writeLine(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

// ---------------------------------------------------------|
    // Funcion para leer la informacion guardada en el archivo .csv y ahi mismo guardarla en el struct
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
    dataFile.close();
}
    // Funcion para mostrar todo lo gaurdado en el struct
void showDataStored() {
    std::cout << std::endl;
    for (int i = 0; i < allWorkersInfo.code.size(); i++) {
        writeLine("*");
        std::cout << "Worker Code: " << allWorkersInfo.code.at(i) << std::endl;
        std::cout << "Total Hours: " << allWorkersInfo.totalHoursOfWork.at(i) << std::endl;
        std::cout << "Days of Work: " << allWorkersInfo.daysOfWorkPerMonth.at(i) << std::endl;
    }
}

// ----------------------------------------------------------------------------------------------------------| >

// ---------------------------------------------------------|
    // Funcion que se encarga de contar el total de horas entre todos los trabajadores
    // ! Para eso es un contador en el que itera en el struct
double totalHoursOfWork() {
    double totalHours = 0.0;
    for (auto &value : allWorkersInfo.totalHoursOfWork) totalHours += value;
    return totalHours;
}

// ---------------------------------------------------------|
    // Funcin "main" que llama al resto de las funciones del analisis :>
void analizeData() {
    showDataStored();
    writeLine("-");
    std::cout << std::endl << "Total Hours of Work: " << totalHoursOfWork() << std::endl;
}

// ---------------------------------------------------------|

// ------------------------- MAIN FUNCTION -------------------------------------------------------------------------------------------------------------------|
// -------------------------------------------------------------------------------------------------| >
    // Funcion main que controla todo el programa :>
int main(void) {
    workerLoop();
    readData(); 
    analizeData(); 
    return EXIT_SUCCESS;
}