#include <bits/stdc++.h>

const std::string nombreArchivo = "Code/ArchivosRelated/fullData.csv";

struct {
    std::vector <std::string> userName;
    std::vector <std::string> phoneNumber;
    std::vector <std::string> emailAddress;
    std::vector <std::string> country;
} dataArrays;

void showFullData();

int main() {
    std::ifstream archivoData(nombreArchivo);
    std::string line;
    char delimiter = ',';

    // Descartando la primera linea del archivo
    getline(archivoData, line);

    while (getline(archivoData, line)) {

        // Linea que permite leer un std::string como un stream
        // de datos, al puro estilo std::cin
        std::stringstream streamLine(line);

        std::array <std::string, 4> tempValues;

        std::getline(streamLine, tempValues[0], delimiter);
        std::getline(streamLine, tempValues[1], delimiter);
        std::getline(streamLine, tempValues[2], delimiter);
        std::getline(streamLine, tempValues[3], delimiter);

        dataArrays.userName.push_back(tempValues[0]);
        dataArrays.phoneNumber.push_back(tempValues[1]);
        dataArrays.emailAddress.push_back(tempValues[2]);
        dataArrays.country.push_back(tempValues[3]);

        tempValues.fill(" ");
    }

    archivoData.close();

    system("pause");

    showFullData();

    return EXIT_SUCCESS;
}

void showFullData() {
    std::cout << "Number of records: " << dataArrays.userName.size() << std::endl;
    system("pause");

    for (int i = 0; i < 40; i++)
        std::cout << "-";
    std::cout << std::endl;

    unsigned startTime, endTime;

    startTime = clock();

    for (int i = 0; i < dataArrays.userName.size(); i++) {
        std::cout << "Username: " << dataArrays.userName.at(i) << std::endl;
        std::cout << "Phone Number: " << dataArrays.phoneNumber.at(i) << std::endl;
        std::cout << "Email Address:" << dataArrays.emailAddress.at(i) << std::endl;
        std::cout << "Country: " << dataArrays.emailAddress.at(i) << std::endl;

        for (int i = 0; i < 40; i++)
            std::cout << "-";
        std::cout << std::endl;
    }

    endTime = clock();

    long double time = (double(endTime - startTime) / CLOCKS_PER_SEC);
    std::cout << "Execution Time: " << time << " (s)" << std::endl;
}