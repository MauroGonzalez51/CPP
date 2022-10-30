#include <bits/stdc++.h>

std::ofstream logFile("Code/Test/logFile.txt", std::ios::app);

class Parent {
    public:
        void writeLog() {
            if (logFile.is_open()) {
                time_t now = time(0);
                char* dateTime = ctime(&now);

                logFile << std::endl;
                for (int i = 0; i < 40; i++)
                    logFile << "-";
                logFile << std::endl;
                
                logFile << "Sesion Started at: " << dateTime << std::endl;
            }
        }

        void writeLog(std::string logMessage) {
            logFile << logMessage << std::endl;
        }
};

class Child : public Parent {
    private:
        std::string name, code;

    public:
        Child(const std::string name, const std::string code) {
            this -> name = name;
            this -> code = code;
        }
};


int main(void) {
    // Child accede a todas las propiedades publicas de "Parent"

    Child* child = new Child("Mauro", "23895");
    
    child -> writeLog();


    return EXIT_SUCCESS;
}