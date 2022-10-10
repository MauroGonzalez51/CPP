#include <bits/stdc++.h>

bool validateMsg(char msg[3]);
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

        void balanceSub(int quantity) { this -> balance -= quantity; }
    
};

class GuessNumber {
    private:
        int gameModeLocal, randomNumber, tries = 5, multiplier;
        bool triesGameMode = false;
        float bettingAmount;
        std::array <std::string, 5> validEntries = {"Number 1-10  | 1 Try", "Number 1-10  | 5 Tries", "Number 1-100 | 1 Try", "Number 1-100 | 5 Tries", "Custom Game Mode"};

        bool validateGameMode() {
            bool isValid = false;
            for (int i = 0; i < validEntries.size(); i++) {
                if ((gameModeLocal - 1) == i)
                    isValid = true;
            }

            return isValid;
        }

        void gameRules() {
            for (int i = 0; i < 50; i++)
                std::cout << "-";
            std::cout << std::endl;
            std::cout << "Game Rules" << std::endl;
            std::cout << "1. You win depending on the Game Mode you select" << std::endl;
            std::cout << "2. If you lose, you lose all you had bet" << std::endl;
            std::cout << "3. Default Game Mode \"1\"" << std::endl;
            std::cout << "That's it!" << std::endl;
        }

        void randomizeNumber (int lowerLimit, int upperLimit) {
            srand(time(NULL));
            this -> randomNumber = lowerLimit + rand() % ((upperLimit + 1) - 1);
        }

    public:
        int getGameMode() { return this -> gameModeLocal; }

        int getRandomNumber() { return this -> randomNumber; }

        int getTries() { return this -> tries;}

        void triesSub() { this -> tries--;}

        void reFillTries(int value) { this -> tries = value; }

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

            if ((gameModeLocal == 2) || (gameModeLocal == 4) || (gameModeLocal == 5)) 
                this -> triesGameMode = true;
            
        }

        void guessNumberGame(Player* player) {
            int customTries = 5;
            std::cout << std::endl;
            this -> gameRules();
            this -> selectGameMode();
  
            std::cout << std::endl;
            std::cout << "[ DISCLAIMER ]: You win 10x regardless of the Game Mode" << std::endl;

            if (this -> gameModeLocal != 5) {
                multiplier = 10;
            } else {
                do {
                    std::cout << "Multiplier Value: ";
                    std::cin >> this -> multiplier;
                } while (this -> multiplier < 1);

                do {
                    std::cout << "Number of tries: ";
                    std::cin >> customTries;
                } while (customTries < 1);
            } 

            do {

                reFillTries(customTries);
                randomizeNumber(1, 10);
                
                std::cout << std::boolalpha << this -> triesGameMode << std::endl;

                bool playerWon = false;

                std::cout << std::endl;
                std::cout << "Initial balance: " << player -> getBalance() << "$" << std::endl;
                
                do {
                    std::cout << "Hey, " << player -> getName() << ", Enter amount to bet: ";
                    std::cin >> this -> bettingAmount;
                } while (bettingAmount < 1);

                player -> balanceSub(bettingAmount);

                do {
                    int guess;
                    std::cout << std::endl;
                    std::cout << "Enter a number: ";
                    std::cin >> guess;

                    this -> triesSub();


                    if (this -> randomNumber == guess) {
                        std::cout << "Congrats" << std::endl;
                        std::cout << "You Won!" << std::endl;
                        player -> balanceAdd(bettingAmount * multiplier);
                        playerWon = true;
                        break;
                    } else {
                        if (triesGameMode)
                            if (getTries() > 0)
                                std::cout << "You still have " << this -> getTries() << " (s) attemps left" << std::endl;
                            else 
                                std::cout << "You ran out of attemps" << std::endl;
                        else {
                            std::cout << "You have lost" << std::endl;
                            break;
                        }
                    }

                    std::cout << std::endl;

                } while (this -> getTries() > 0);

                if (!playerWon)
                    std::cout << "The winning number was " << this -> randomNumber << std::endl; 

                if (player -> getBalance() > 0) {
                    char msgOut[3];
                    std::cout << "Wanna play again?" << std::endl;
                    std::cout << "-> ";
                    std::cin >> msgOut;

                    if (!validateMsg(msgOut))
                        break;
                } else {
                    std::cout << "You ran out of money" << std::endl;
                    exit(EXIT_SUCCESS);
                }

            } while (true);
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
};