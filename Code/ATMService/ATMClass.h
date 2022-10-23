#include <bits/stdc++.h>

std::ofstream logFile ("Code/ATMService/files/logFile.txt", std::ios::app);
void clearBuffers();

class ATM {
    private:
        double valueToRetire;
    
    public:
        void writeLog() {
            time_t now = time(0);
            char* dateTime = ctime(&now);

            // (msgToLog == "Setup.log") ?
            //         logFile << "[INFO] " << msgToLog << std::endl;

            logFile << std::endl;
            for (int i = 0; i < 60; i++)
                logFile << "*";
            logFile << std::endl;

            logFile << "Sesion Started at: " << dateTime << std::endl;
        }

        void writeLog(const std::string msgToLog) {
            logFile << "[INFO] " << msgToLog << std::endl;
        }
};