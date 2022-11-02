#include <bits/stdc++.h>

class ATM;

class USER : public ATM {
    private:
        std::string username, password;
        double balance;
        bool accountStatus;

    public:
        USER (bool accountCreated) {
            std::cout << "Enter a username: ";
            std::getline(std::cin, this -> username);

            std::cout << "Enter a password: ";
            std::getline(std::cin, this -> password);

            if (accountCreated) {
                std::cout << "Enter a initial balance: ";
                std::cin >> this -> balance;
            }

            std::cin.ignore(std::numeric_limits <int>::max());
            this -> accountStatus = true;
        }
    
        USER (std::string username, std::string password, double balance) {
            this -> username = username;
            this -> password = password;
            this -> balance = balance;
            this -> accountStatus = true;
        }

        // -------------------------------------------------------------------------------------------------------------------------------|

        bool createAccount() {
            bool accountCreated = false;
            std::ofstream userFile (fileFolderPath + this -> username + ".txt");

            return accountCreated;
        }

        // -------------------------------------------------------------------------------------------------------------------------------|
};