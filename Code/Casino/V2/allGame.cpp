#include <iostream>
#include <array>
#include <vector>
#include <string.h>
#include <conio.h>
#include <set>

bool validateMsg(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    std::array <std::string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0) {
                Flag = false;
            }
        }
    }
    return Flag;
}

class Player {
    private:
        double balance;
        int coins, gameModeGeneral;
        std::string name;

    public:
        Player(const int gameMode) {

            switch (gameMode) {
                case 1: {
                    std::cout << "Enter your name: ";
                    std::cin >> this -> name;
                    std::cout << "Hey, " << this -> name << ", Enter your initial balance to play: ";
                    std::cin >> this -> balance;
                    this -> gameModeGeneral = 1;
                    break;
                }

                case 2: {
                    std::cout << "Enter your name: ";
                    std::cin >> this -> name;
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

        int getCoins() { return this -> coins; }

        void coinsAdd(int quantity) { this -> coins += quantity; }

        void coinsSub(int quantity) { this -> coins -= quantity; }
};

class GuessNumber {
    private:
        int gameModeLocal, randomNumber, tries = 5, multiplier, lowerLimit, upperLimit;
        bool triesGameMode = false;
        float bettingAmount;
        std::array <std::string, 6> validEntries = {"Number 1-10  | 1 Try", "Number 1-10  | 5 Tries", "Number 1-100 | 1 Try", "Number 1-100 | 5 Tries", "Custom Game Mode", "Exit"};

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

        void randomizeNumber () {
            srand(time(NULL));
            switch (gameModeLocal) {
                case 2: 
                    this -> randomNumber = 1 + rand() % (101 - 1);
                    break;
                
                case 3:
                    this -> randomNumber = 1 + rand() % (101 - 1);
                    break;

                case 5:
                    this -> randomNumber = this -> lowerLimit + rand() % ((this -> upperLimit + 1) - 1);
                    break;
                
                default:
                    this -> randomNumber = 1 + rand() % (11 - 1);
            }
        }

    public:
        int getGameMode() { return this -> gameModeLocal; }

        int getRandomNumber() { return this -> randomNumber; }

        int getTries() { return this -> tries;}

        void triesSub() { this -> tries--;}

        void reFillTries(int value) { this -> tries = value; }

        void displayGameModes() {
            std::cout << std::endl;
            for (int i = 0; i < this -> validEntries.size(); ++i) 
                std::cout << "[ " << i + 1 << " ] " << this -> validEntries.at(i) << std::endl;
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

            if (this -> gameModeLocal == 6)
                exit(EXIT_SUCCESS);
            
            std::cout << std::endl;
            std::cout << "[DISCLAIMER]: You win 10x regardless of the Game Mode" << std::endl;

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

                do {
                    std::cout << "Lower Limit: ";
                    std::cin >> this -> lowerLimit;
                } while (lowerLimit < 0);

                do {
                    std::cout << "Upper Limit: ";
                    std::cin >> this -> upperLimit;
                } while ((lowerLimit > upperLimit) || (upperLimit < 0));
            } 

            std::cout << "[INFO]  Tries Gamemode: " << std::boolalpha << this -> triesGameMode << std::endl;

            (this -> lowerLimit != 0) ? 
                std::cout << "[INFO]  Lower Limit: " << this -> lowerLimit << std::endl :
                    std::cout << "[INFO]  Lower Limit: NULL" << std::endl;

            (this -> upperLimit != 0) ? 
                std::cout << "[INFO]  Upper Limit: " << this -> upperLimit << std::endl :
                    std::cout << "[INFO]  Upper Limit: NULL" << std::endl;
            
            std::cout << "[INFO]  Multiplier Value: " << this -> multiplier << std::endl;

            do {

                reFillTries(customTries);
                randomizeNumber();
                // std::cout << "[INFO]  Random: " << this -> randomNumber << std::endl;

                bool playerWon = false;

                std::cout << std::endl;
                std::cout << "Initial balance: " << player -> getBalance() << "$" << std::endl;
                
                do {
                    std::cout << "Hey, " << player -> getName() << ", Enter amount to bet: ";
                    std::cin >> this -> bettingAmount;
                } while ((bettingAmount < 1) || (bettingAmount > player -> getBalance()));

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
                    break;
                }
            } while (true);
        }
};

class SlotMachine {
    private:
        int slot1, slot2, slot3;
        bool cheatingEnabled;
    
    public:
        void randomizeSlot(int times) {
            srand(time(NULL));
            
            for (int i = 0; i < times; i++) {
                this -> slot1 = 1 + rand() % (11 - 1);
                this -> slot2 = 1 + rand() % (11 - 1);
                this -> slot3 = 1 + rand() % (11 - 1);
            }
        }

        void displaySlots() {
            std::cout << "| " << this -> slot1 << " | " << this -> slot2 << " | " << this -> slot3 << " | "<< std::endl;
        }

        void searchCoincidences(Player* player) {
            // cout << num1 << " " << num2 << " " << num3 << endl;

            std::array <int, 3> numbers = { this -> slot1, this -> slot2, this -> slot3 };
            std::array <int, 3> repeatNumbers;
            repeatNumbers.fill(0);

            bool checkNextCase = true, userWin = false;
            // There are all different?
            {
                std::cout << std::endl;
                for (int i = 0; i < numbers.size(); i++) {
                    int times = 0;
                    for (int j = 0; j < numbers.size(); j++) {
                        if (numbers[i] == numbers[j])
                            times++;    
                    }
                    std::cout << "Number: " << numbers[i] << " -> repeat: " << times << std::endl;

                    if (times >= 2) 
                        repeatNumbers[i] = numbers[i];
                }
                // What all this code do is check for repeated numbers, and then pushing 
                // into a new array ...

                int counter = 0;
                for (auto i : repeatNumbers) {
                    if (i == 0)
                        counter++;
                }

                if (counter == 3) {
                    std::cout << std::endl << "There are all different :>" << std::endl;
                    std::cout << "You lost [1] coin" << std::endl;
                    checkNextCase = false;
                }

            };

            // Checking the "repeated numbers" ...

            // 1 Case: Pair of numbers
            if (checkNextCase) {   
                int pairNumber;
                for (auto i : repeatNumbers) {
                    if (i != 0) {
                        pairNumber = i;
                        break;
                    }
                }

                // cout << "Pair: " << pairNumber << endl;
                std::cout << "You have won!" << std::endl;
                std::cout << pairNumber << " coin(s) ..." << std::endl;
                player -> coinsAdd(pairNumber);
                
                checkNextCase = false;
                userWin = true;
            }

            // 2 Case: All the same
            if (checkNextCase) {
                int threeNumber, times = 0, sample = repeatNumbers[0];
                for (auto i : repeatNumbers) {
                    if (i == sample)
                        times++;
                }

                if (times == 3) {
                    // cout << "Three: " << threeNumber << endl;
                    
                    std::cout << "You have won!" << std::endl;
                    std::cout << threeNumber * 2 << " coin(s) ..." << std::endl;
                    player -> coinsAdd(threeNumber * 2);    

                    checkNextCase = false;   
                    userWin = true; 
                }
            }

            if (checkNextCase) {
                int sevenNumber = 0;
                for (auto i : repeatNumbers) {
                    if (i == 7)
                        sevenNumber++;
                }

                if (sevenNumber == 3) {
                    std::cout << "You have won!" << std::endl;
                    std::cout << "777 coins" << std::endl;
                    player -> coinsAdd(777);
                    checkNextCase = false;
                    userWin = true;
                }
            }

            if (!userWin) 
                std::cout << std::endl <<  "[...]" << std::endl;
        }

        void slotMachineGame(Player* player) {
            int timesPlayed = 0;

            do {
                int times;
                system("cls");
                std::cout << "Current coins: " << player -> getCoins() << std::endl;

                char msgIn[3];
                std::cout << "Wanna play?" << std::endl;
                std::cout << "-> ";
                std::cin >> msgIn;

                std::cout << "[INFO]  Launch Game: " << std::boolalpha << validateMsg(msgIn) << std::endl;

                if (!validateMsg(msgIn))
                    break;
                else if (player -> getCoins() < 1) {
                    std::cout << "You don't have enough coins to play!" << std::endl;
                    break;
                } else {
                    timesPlayed++;
                    player -> coinsSub(1);
                    if (timesPlayed > 5)
                        this -> cheatingEnabled = true;

                    (cheatingEnabled) ? times = ((timesPlayed * 10) / player -> getCoins()) : times = 44;

                    std::cout << "Press a key to insert a coin" << std::endl;
                    getch();

                    randomizeSlot(times);

                    displaySlots();

                    searchCoincidences(player);

                    system("pause");
                }
            } while (true);
        }
};

std::set <int> validGameModes;

bool validateGameMode(int option) {
    bool isValid = false;
    for (int i : validGameModes) {
        if (option == i)
            isValid = true;
    }

    return isValid;
}

int selectGameMode() {
    int option;

    do {
        std::cout << "-> ";
        std::cin >> option;
    } while (!validateGameMode(option));

    return option;
}

int displayGameModes() {
    system("cls");

    std::cout << std::endl;
    for (int i = 0; i < 50; i++)
        std::cout << "-";
    
    std::cout << std::endl;

    std::cout << "Game Modes" << std::endl;

    std::cout << "[1]. Guess a Number" << std::endl;
    validGameModes.insert(1);

    std::cout << "[2]. Slot Machine Game" << std::endl;
    validGameModes.insert(2);

    std::cout << "[3]. Exit" << std::endl;
    validGameModes.insert(3);

    return selectGameMode();
}

void gameLauncher(Player* player) {
    switch (player -> getGameMode()) {
        case 1: {
            GuessNumber* guessNumber = new GuessNumber();
            
            guessNumber -> guessNumberGame(player);
            // guessNumber -> selectGameMode();
            break;
        }
        
        case 2: {
            SlotMachine* slotMachine = new SlotMachine();

            slotMachine -> slotMachineGame(player);
            // slotMachine -> randomizeSlot();
            // slotMachine -> display();
            break;
        }

        case 3: {
            exit(EXIT_SUCCESS);
        }
    }
}

int main() {
    Player* player = new Player(displayGameModes());
    
    gameLauncher(player);

    std::cout << "Press any key to continue..." << std::endl;
    getch();

    return EXIT_SUCCESS;
}