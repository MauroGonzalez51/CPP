#include <bits/stdc++.h>

std::ofstream logFile("logFile.txt", std::ios::app);

void setupLogger(const std::string msgToLog) {
    time_t now = time(0);
    char* dateTime = ctime(&now);

    if (msgToLog.empty()) {
        logFile << std::endl;
        logFile << "Sesion Started at " << dateTime << std::endl;
    } else 
        logFile << "[INFO] " << msgToLog << std::endl;
            
    if (msgToLog == "closeSession")
        logFile.close();
}

class User {
    private:
        std::string username, password;

        bool validateUsername() {
            bool isValid = false;

            if (!this -> username.empty()) 
                isValid = true;
            
            return isValid;
        }

        bool validatePassword() {
            bool isValid = false;

            if (!this -> password.empty()) 
                isValid = true;

            return isValid;
        }

    public:
        int selectedOption;
        bool logOut = false;

        void setupValues() {
            
            std::cout << "Enter Username";
            do {
                std::cout << "-> ";
                getline(std::cin, this -> username);

            } while (!this -> validateUsername());

            std::cout << "Enter Password: ";
            do {
                std::cout << "-> ";
                getline(std::cin, this -> password);

            } while (!this -> validatePassword());
        }

        std::string getUsername() { return this -> username; }
        std::string getPassword() { return this -> password; }
};

void mainMenu(User* user) {
    std::cout << std::endl;
    std::cout << "User Login App" << std::endl;
    std::cout << "[1]. Login" << std::endl;
    std::cout << "[2]. Sign up" << std::endl;
    std::cout << "[3]. Exit" << std::endl;
    std::cout << "-> ";
    std::cin >> user -> selectedOption;
}

void userApp(User* user) {


    switch (user -> selectedOption) {
        case 1: {
            try {
                std::ifstream userLog(user -> getUsername() + ".txt");

                if (!userLog.is_open()) 
                    throw (123);

            } catch (int errorMsg) { 
                std::cout << errorMsg << std::endl;
            }

            break;
        }

        case 2: {
            std::ofstream userFile (user -> getUsername() + ".txt", std::ios::app);

            userFile << user -> getUsername() << std::endl;
            userFile << user -> getPassword() << std::endl;

            break;
        }

        case 3: {
            user -> logOut = true;
            system("pause");

            break;
        }

        default:
            std::cout << "[...]" << std::endl;

    }
}


int main(void) {
    setupLogger("");

    User* user = new User();

    setupLogger("Creating a new user object");


    do {
        mainMenu(user);

        setupLogger("Option Selected");

        user -> setupValues();

        setupLogger("Asking for the username/password");

        userApp(user);

    } while (!user -> logOut);

    return EXIT_SUCCESS;
}