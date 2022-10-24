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

        // void userDashboard() {
        //     switch (userDashboardMainMenu()) {
        //         case 1: {
        //             std::ifstream moves ("Code/ATMService/files/" +  user -> getName() +  ".txt");
        //             std::string line;

        //             for (int i = 0; i < 4; i++)
        //                 std::getline(moves, line);

        //             std::vector <std::string> movesDetailed;
        //             while (std::getline(moves, line)) {
        //                 if (!line.empty()) {
        //                     std::getline (moves, line);

        //                     movesDetailed.push_back(line);
        //                 }
        //             }

        //             moves.close();

        //             std::cout << movesDetailed.size() << std::endl;
        //         }
        //     }

        // };   
};