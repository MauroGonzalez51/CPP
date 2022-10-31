#include <bits/stdc++.h>

const std::string fileFolderPath = "Code/ATMService/V2/files";

std::ofstream logFile (fileFolderPath + "logFile.txt", std::ios::app);

// ------------------------------------------------------------------------------------

class ATM {
    public:
        // ----------------------------------------------------------------|

        void writeLog() {
            time_t now = time(0);
            char* dateTime = ctime(&now);

            logFile << std::endl;
            for (int i = 0; i < 60; i++) 
                logFile << "-";
            logFile << std::endl;

            logFile << "Sesion Started at: " << dateTime << std::endl;
        }

        void writeLog(const std::string logMsg) {
            logFile << logMsg << std::endl;
        }

        // ----------------------------------------------------------------|

        bool checkCredentials(USER* user) {
            bool validCredentials = false;

            std::ifstream userFile (fileFolderPath +  user -> getUsername() +  ".txt");
            std::string auxUsername, auxPassword;

            std::getline(userFile, auxUsername);
            std::getline(userFile, auxPassword);

            if ((user -> getUsername() == auxUsername) && (user -> getPassword() == auxPassword))
                validCredentials = true;

            return validCredentials;
        }

        bool accountExists(USER* user) {
            bool accountExists = false;

            std::ifstream userFile (fileFolderPath + user -> getUsername() + ".txt");

            if (userFile.is_open())
                accountExists = true;
            
            return accountExists;
        }

        // ----------------------------------------------------------------|

        bool createAccount(USER* user) {
            bool accountCreated = false;

            
        }
};

// ------------------------------------------------------------------------------------

class USER : public ATM {
    private:
        std::string username, password;

    public:
        // ----------------------------------------------------------------|

        USER (const std::string username, const std::string password) {
            this -> username = username;
            this -> password = password;
        }

        USER (void) {
            std::cout << "Enter a username: ";
            std::getline(std::cin, this -> username);

            std::cout << std::endl;

            std::cout << "Enter a password: ";
            std::getline(std::cin, this -> password);
        }

        // ----------------------------------------------------------------|

        std::string getUsername() { return this -> username; }
        std::string getPassword() { return this -> password; }

        // ----------------------------------------------------------------|

};