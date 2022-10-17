/**
 *  //* groupMembers
 *      - Mauro Alonso Gonzalez Figueroa    T00067622
 *      - Juan Jose Jimenez Guardo          T00068278
 * 
 * 
 *   //* DISCLAIMER
 *      Since the program uses the std::cin function to 
 *      store the input data, there's no way it could
 *      handle the blank spaces.
 *      
 *      So, most likely the program will crash if some of these
 *      characters are inserted.
 * 
 *      It'll create a new .txt file with just the name inserted 
 *      (a line for each word), and the password inserted will be
 *      completely omitted.
 * 
 * 
*/

#include <bits/stdc++.h>

const std::string nombreArchivo = "Code/ArchivosRelated/.CSV/fullData.csv";

struct {
    std::vector <std::string> userName;
    std::vector <std::string> phoneNumber;
    std::vector <std::string> emailAddress;
    std::vector <std::string> country;
} dataArrays;

void readingFile();
void showFullData();

class User {
    private:
        std::string username, password;

    public:
        User(void) {
            std::cout << "Enter a username: ";
            std::cin >> this -> username;

            std::cout << "Enter a password: ";
            std::cin >> this -> password;
        }

        std::string getUsername() { return this -> username; }
        std::string getPassword() { return this -> password; }
};

bool isLoggedIn() {
    std::string lineUser, linePassword;
    std::string username, password;

    std::cout << "Enter a username: ";
    std::cin >> username;

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::ifstream read(username + ".txt");
    std::getline(read, lineUser);
    std::getline(read, linePassword);

    return ((username == lineUser) && (password == linePassword) ? true : false);
}

int mainMenu() {
    int choice;

    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Main Menu" << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << "-";

    std::cout << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "-> ";
    std::cin >> choice;

    return choice;
}


int main(void) {
    switch (mainMenu()) {
        case 1: {
            std::cout << std::endl << std::endl;
            std::cout << "Registration" << std::endl;
            std::cout << std::endl;

            User* user = new User();

            std::ofstream userFile (user -> getUsername() + ".txt", std::ios::app);
            userFile << user -> getUsername() << std::endl;
            userFile << user -> getPassword() << std::endl;

            userFile.close();

            std::cout << "Welcome " << user -> getUsername() << "!" << std::endl;
            break;
        }

        case 2: {
            if (!isLoggedIn()) {
                system("cls");
                std::cout << std::endl;
                std::cout << "Invalid Login!" << std::endl;
                main();
            } else {
                std::cout << std::endl;
                std::cout << "Succesfully logged in!" << std::endl << std::endl;

                std::cout << "Welcome back" << std::endl << std::endl;

                std::cout << "DASHBOARD" << std::endl;
                
                std::cout << "// Example ..." << std::endl;

                readingFile();

                system("pause");

                showFullData();

                int choice;

                std::cout << "1. Sign out" << std::endl;
                std::cout << "2. Back to main menu" << std::endl << std::endl;
                std::cout << "-> ";
                std::cin >> choice;

                switch (choice) {
                    case 1: 
                        system("pause");
                        exit(EXIT_SUCCESS);
                        break;
                    
                    case 2: 
                        main();
                        break;
                    
                    default:
                        system("pause");
                        main();
                }
            }
            break;
        }

        default: 
            exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

void readingFile() {
    unsigned startTime, endTime;
    std::ifstream archivoData(nombreArchivo);
    std::string line;
    char delimiter = ',';

    std::getline(archivoData, line);

    startTime = clock();
    while (std::getline(archivoData, line)) {
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
    endTime = clock();

    double readingTime = (double(endTime - startTime) / CLOCKS_PER_SEC);
    std::cout << "Reading data: " << readingTime << " (s)" << std::endl;
}

void showFullData() {
    unsigned startTime, endTime;

    std::cout << std::endl;
    std::cout << "Number of records: " << dataArrays.userName.size() << std::endl;
    system("pause");

    for (int i = 0; i < 40; i++)
        std::cout << "-";
    std::cout << std::endl;

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
    long double executionTime = (double(endTime - startTime) / CLOCKS_PER_SEC);
    std::cout << "Execution Time: " << executionTime << " (s)" << std::endl;
}