#include <bits/stdc++.h>

const std::string fileFolderPath = "0.2/files/";

std::ofstream logFile (fileFolderPath + "logFile.txt", std::ios::app);

class ATM {
    public:
        const char* getCurrentTime() {
            time_t now = time(0);
            const char* dateTime = ctime(&now);

            return dateTime;
        }

        void writeLine() {
            logFile << std::endl;
            for (int i = 0; i < 60; i++) 
                logFile << "*";
            logFile << std::endl;
        }

        void writeLine(const std::string msg) {
            std::cout << std::endl;
            for (int i = 0; i < 60; i++) 
                logFile << msg;
            std::cout << std::endl;
        }

        void writeLog() {
            this -> writeLine();
            logFile << "Sesion Started at: " << this -> getCurrentTime() << std::endl;
        }

        void writeLog(const std::string msg) {
            logFile << "[INFO] " << msg << std::endl;
        }
};