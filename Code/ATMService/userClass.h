#include <bits/stdc++.h>

void clearBuffers();

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

class User {
    private:
        std::string username, password;
        double balance;

    public:
        User(bool accountCreated) {
            std::cout << std::endl;

            std::cout << "Enter username: ";
            std::cout << std::endl << "-> ";
            std::cin >> this -> username;

            std::cout << std::endl;

            std::cout << "Enter password: ";
            std::cout << std::endl << "-> ";
            std::cin >> this -> password;

            if (accountCreated) {
                std::cout << std::endl;

                do {
                    std::cout << "Enter initial balance: ";
                    std::cout << std::endl << "-> ";
                    std::cin >> this -> balance;
                } while (this -> balance < 0);
            }

            clearBuffers();
        }

        bool tryLogin() {
            bool success = false;
            try {
                std::ifstream userFile ("Code/ATMService/files/" + this -> username + ".txt");

                if (!userFile.is_open())
                    throw (std::string) ("File not found: " +  this -> username + ".txt | You must create an account first");
                else {
                    std::string auxUsername, auxPassword;

                    std::getline(userFile, auxUsername);
                    std::getline(userFile, auxPassword);

                    ((this -> username == auxUsername) && (this -> password == auxPassword)) ?
                        success = true : throw (std::string) ("Username or Password mismatch");

                    clearBuffers();
                }
                
                userFile.close();
            } catch (std::string msgError) {
                std::cout << std::endl << "Error: " << msgError << std::endl;
            }

            return success;
        }

        bool createAccount() {
            bool success = false;

            try {
                std::ofstream userFile ("Code/ATMService/files/" + this -> username + ".txt", std::ios::app);

                if (!userFile.is_open())
                    throw (std::string) ("File can not be opened: " + this -> username + ".txt");
                
                else {
                    userFile << this -> username << std::endl;
                    userFile << this -> password << std::endl;
                    userFile << this -> balance << std::endl;
                    userFile << "Moves: [...]" << std::endl;

                    success = true;
                }

                userFile.close();
            } catch (std::string msgError) {
                std::cout << "Error: " << msgError << std::endl;
            }

            return success;
        }

        bool deleteAccount() {
            clearBuffers();

            char msg[3];
            bool accountDeleted = false;

            std::cout << std::endl;
            std::cout << "Wanna delete this account?" << std::endl;
            std::cout << "-> ";
            std::cin >> msg[3];

            if (tryLogin()) {
                if (!validateMsg(msg)) {
                    std::string sfilePath = "Code/ATMService/files/" + this -> username + ".txt";

                    const char* cfilePath = sfilePath.c_str();

                    int result = remove(cfilePath);
                    
                    if (result == 0)
                        accountDeleted = true;

                }
            } 
            return accountDeleted;
        }

        std::string getUsername() { return this -> username; }

        int userDashboardMainMenu() {
            int choice;
            std::cout << std::endl;
            std::cout << "Dashboard Menu" << std::endl;
            std::cout << "1. See your account status" << std::endl;
            std::cout << "2. See previous moves" << std::endl;
            std::cout << "3. Add Money" << std::endl;
            std::cout << "4. Retire Money" << std::endl;
            std::cout << "5. Exit" << std::endl;

            return choice;
        }

        void userDashboard(ATM* atm);

};

void User::userDashboard(ATM* atm) {
    switch (userDashboardMainMenu()) {
        case 1: {
            try {
                std::ifstream accountStatus ("Code/ATMService/files/" + this -> username +  ".txt");

                (!accountStatus.is_open()) ?
                    throw (std::string) ("File Not found || Account Deleted") :
                        std::cout << "Status: Your account is activated " << std::endl;
            } catch (std::string msgError) {
                std::cout << "Status: " << msgError << std::endl;
            }

            break;
        }

        case 2: {
            std::ifstream moves ("Code/ATMService/files/" + this -> username + ".txt");

            std::string line;
            std::vector <std::string> movesDetailed;

            for (int i = 0; i < 4; i++)
                std::getline (moves, line);
            
            while (std::getline(moves, line)) {
                movesDetailed.push_back(line);
            }

            std::cout << movesDetailed.size() << std::endl;

            break;
        } 
            
        default:
            exit(EXIT_FAILURE);
    }
}