#include <bits/stdc++.h>

void clearBuffers();

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

                    success = true;
                }

                userFile.close();
            } catch (std::string msgError) {
                std::cout << "Error: " << msgError << std::endl;
            }

            return success;
        }
};