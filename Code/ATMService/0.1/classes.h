#include <bits/stdc++.h>

const std::string fileFolderPath = "Code/ATMService/V2/files";

std::ofstream logFile (fileFolderPath + "logFile.txt", std::ios::app);

// ------------------------------------------------------------------------------------

class ATM {
    private:
        bool validateMsg(char msg[3]) {
            std::array <std::string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
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

    public:
        // ----------------------------------------------------------------|

        const char* getCurrentTime() {
            time_t now = time(0);
            const char* dateTime = ctime(&now);

            return dateTime;
        }

        // ----------------------------------------------------------------|

        void writeLog() {
            logFile << std::endl;
            for (int i = 0; i < 60; i++) 
                logFile << "-";
            logFile << std::endl;

            logFile << "Sesion Started at: " << getCurrentTime() << std::endl;
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

            std::ofstream userFile (fileFolderPath + user -> getUsername() + ".txt", std::ios::app);

            if (userFile.is_open()) {
                userFile << user -> getUsername() << std::endl;
                userFile << user -> getPassword() << std::endl;
                userFile << user -> getBalance() << std::endl;
                userFile << "true" << std::endl;
                userFile << "Moves: [...]" << std::endl;

                accountCreated = true;
            }

            return accountCreated;
        }

        // ----------------------------------------------------------------|

        int userDashboardMainMenu() {
            unsigned int choice;

            std::cout << "Main Menu" << std::endl;
            std::cout << "1. See your account status" << std::endl;
            std::cout << "2. See previous moves" << std::endl;
            std::cout << "3. Add money" << std::endl;
            std::cout << "4. Retire money" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << std::endl << "-> ";
            std::cin >> choice;

            return choice;
        }

        // -------------------------------------|

        std::string accountStatus(USER* user) {
            std::string line;

            std::ifstream userFile (fileFolderPath +  user -> getUsername() + ".txt");

            for (int i = 0; i < 3; i++)
                std::getline(userFile, line);
            
            std::getline(userFile, line);
            userFile.close();

            return line;
        }

        // -------------------------------------|

        void accountMoves(USER* user, std::vector <std::string> &recordMoves) {
            std::string line;
            
            std::ifstream userFile (fileFolderPath + user -> getUsername() + ".txt")

            for (int i = 0; i < 4; i++)
                std::getline(userFile, line);

            while (std::getline(userFile, line)) {
                std::getline(userFile, line);
                recordMoves.push_back(line);
            }

            userFile.close();
        }

        // -------------------------------------|

        void addMoney(USER* user) {
            std::string line;
            std::ifstream userFile (fileFolderPath + user -> getUsername() + ".txt");
            for (int i = 0; i < 2; i++)
                std::getline (userFile, line);

            std::getline (userFile, line);

            double userCurrentMoney = (double) line;

            double addAmount;

            do { 
                std::cout << "Amount to add: ";
                std::cout << std::endl << "-> ";
                std::cin >> addAmount;
            } while (addAmount < 0);

            
        }

        // -------------------------------------|
        void userDashboard(USER* user) {
            do {
                switch (userDashboardMainMenu()) {
                    case 1: {
                        std::cout << std::endl;
                        std::cout << accountStatus(user) << std::endl;
                        break;
                    }

                    case 2: {
                        std::vector <std::string> recordMoves;

                        accountMoves(user, recordMoves);

                        if (recordMoves.size != 0) {
                            for (auto &record : recordMoves)
                                std::cout << "> " << record << std::endl;
                        } else 
                            std::cout << "There's no previous moves in this account" << std::endl;
                        
                        break;
                    }

                    case 3: {
                        addMoney(user);
                        break;
                    }


                    default:
                        break;
                }
            } while (true)
        }

        bool accessAccount(USER* user) {
            bool userInDashboard = false;

            if (checkCredentials(user) {
                this -> userDashboard(user);
                userInDashboard = true;
            }
            
            return userInDashboard;
        }

        // ----------------------------------------------------------------|

        bool deleteAccount(USER* user) {
            bool accountDeleted = false;
            if (checkCredentials(user)) {
                char msg[3];
                std::cout << "Wanna delete this account?" << std::endl;
                std::cout << "-> ";
                std::cin >> msg;

                if (!validateMsg(msg)) {
                    std::string sUserFilePath = fileFolderPath + user -> getUsername() + ".txt";

                    const char* cUserFilePath = sUserFilePath.c_str();

                    int result = remove(cUserFilePath);

                    if (result == 0)
                        accountDeleted = true;
                }
            }

            return accountDeleted;
        }

        // ----------------------------------------------------------------|
};

// ------------------------------------------------------------------------------------

class USER : public ATM {
    private:
        std::string username, password;
        double balance;

    public:
        // ----------------------------------------------------------------|

        USER (const std::string username, const std::string password) {
            this -> username = username;
            this -> password = password;
        }

        USER (bool createAccount) {
            std::cout << "Enter a username: ";
            std::getline(std::cin, this -> username);

            std::cout << std::endl;

            std::cout << "Enter a password: ";
            std::getline(std::cin, this -> password);

            if (createAccount) {
                std::cout << "Enter initial balance: ";
                std::cin >>this -> balance;
            }
        }

        // ----------------------------------------------------------------|

        std::string getUsername() { return this -> username; }
        std::string getPassword() { return this -> password; }
        double getBalance() { return this -> balance; }

        // ----------------------------------------------------------------|
};