#include <bits/stdc++.h>

const char* getCurrentTime() {
    time_t now = time(0);
    const char* dateTime = ctime(&now);
    return dateTime;
}

void writeLog(const std::string folderPath) {
    std::ofstream logFile (folderPath + "logFile.txt", std::ios::app);
    if (logFile.is_open())
        logFile << std::endl << "Program Started at: " << getCurrentTime() << std::endl;
    logFile.close();
}

void writeLog(const std::string folderPath, const std::string message) {
    std::ofstream logFile (folderPath + "logFile.txt", std::ios::app);
    if (logFile.is_open()) 
        logFile << "[INFO] " << message << std::endl;
    logFile.close();
}