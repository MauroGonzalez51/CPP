#include <bits/stdc++.h>

class Player {
    private:
        float balance;
        int coins, gameModeGeneral;
        std::string name;

    public:
        Player(const int gameMode) {
            std::cout << "Enter your name: ";
            std::cin >> this -> name;

            switch (gameMode) {
                case 1: {
                    std::cout << "Hey, " << this -> name << ", Enter your initial balance to play: ";
                    std::cin >> this -> balance;
                    this -> gameModeGeneral = 1;
                    break;
                }

                case 2: {
                    std::cout << "Hey, " << this -> name << ", Enter your initial coins to play: ";
                    std::cin >> this -> coins;
                    this -> gameModeGeneral = 2;
                    break;
                }

                default: 
                    exit(EXIT_FAILURE);
            }
        }
        std::string getName() { return this -> name; }

        int getGameMode() { return this -> gameModeGeneral; }

        float getBalance() { return this -> balance; }
        
        void balanceAdd(int quantity) { this -> balance += quantity; }

        void balanceSub(int quantity) { this -> balance += quantity; }
    
};

class GuessNumber {
    private:
        int gameModeLocal;
        std::array <std::string, 5> validEntries = {"Number 1-10  | 1 Try", "Number 1-10  | 5 Tries", "Number 1-100 | 1 Try", "Number 1-100 | 5 Tries", "Custom Game Mode"};

        bool validateGameMode() {
            bool isValid = false;
            for (int i = 0; i < validEntries.size(); i++) {
                if ((gameModeLocal - 1) == i)
                    isValid = true;
            }

            return isValid;
        }

    public:
        void displayGameModes() {
            std::cout << std::endl;
            for (int i = 0; i < this -> validEntries.size(); ++i) {
                std::cout << "[ " << i + 1 << " ] " << this -> validEntries.at(i) << std::endl;
            }
            std::cout << std::endl;
        }

        void selectGameMode() {
            displayGameModes();
            do {
                std::cout << "-> ";
                std::cin >> this -> gameModeLocal;
            } while (!this -> validateGameMode());
        }
};

class SlotMachine {
    private:
        int slot1, slot2, slot3;
        bool cheatingEnabled;
    
    public:
        void randomizeSlot() {
            srand(time(NULL));
            this -> slot1 = 1 + rand() % (11 - 1);
            this -> slot2 = 1 + rand() % (11 - 1);
            this -> slot3 = 1 + rand() % (11 - 1);
        }

        void display() {
            std::cout << this -> slot1 << std::endl;
            std::cout << this -> slot2 << std::endl;
            std::cout << this -> slot3 << std::endl;
        }
};

