// Funciones en general para el programa :>

#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

int displayGames() {
    cout << endl;
    int option;
    cout << "Games" << endl;
    cout << "1. Guess a number" << endl;
    cout << "2. Slot machine" << endl;
    cout << "[...]" << endl;
    cout << "-> ";
    cin >> option;

    return option;
}

void displayGameModes() {
    cout << endl;
    cout << "1. Normal mode | Win 10X | One chance to win" << endl;
    cout << "2. Normal mode | Win 5X  | 5 Chances to win " << endl;
    cout << "3. Hard mode   | Win 25X | One chance to win" << endl;
    cout << "4. Hard mode   | Win 20X | 5 Chances to win " << endl;
    cout << "5. God mode    | Win 50X | One chance to win" << endl;
    cout << "6. Custom mode | ------- | -----------------" << endl;
}

int generateRandomNumber(int& gameMode, int lowerLimit, int upperLimit) {
    srand(time(NULL));
    int randomNumber;
    switch(gameMode) {
        case 2: 
            randomNumber = 1 + rand() % (11 - 1);
            break;
        case 3:
            randomNumber = 1 + rand() % (101 - 1);
            break;
        case 4:
            randomNumber = 1 + rand() % (101 - 1);
            break;
        case 5:
            randomNumber = 1 + rand() % (1001 - 1);
            break;
        case 6: 
            randomNumber = lowerLimit + rand() % ((upperLimit + 1) - 1);
            break;
        default:
            randomNumber = 1 + rand() % (11 - 1);
            break;
    }
    return randomNumber;
}

bool validateMsg(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    array <string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
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

void normalGameMode(bool triesEnabled, string& playerName, float& balance, int& gameMode, int& multiplier) {
    system("cls");
    float bettingAmount;
    if (triesEnabled) {
        do {
            int tries = 5;
            int randomNumber = generateRandomNumber(gameMode, 0, 0);
            cout << "Your current balance is " << balance << "$" << endl;
            do {
                cout << "Hey, " << playerName << ", enter amount to bet: ";
                cin >> bettingAmount;

                if (bettingAmount > balance) 
                    cout << "You can't bet money you don't have ..." << endl;
            } while ((bettingAmount < 1) || (bettingAmount > balance));

            balance -= bettingAmount;
            string msg = (gameMode == 4) ? "Enter a number between 1 to 100" : "Enter a number between 1 to 10";
            int guess;
            while (tries > 0) {
                do {
                    cout << msg << endl;
                    cout << "-> ";
                    cin >> guess;
                } while ((guess < 1) || (guess > 100));

                if (guess = randomNumber) {
                    cout << "You have won " << bettingAmount * multiplier << "$" << endl;
                    balance += bettingAmount * multiplier;
                    break;
                } else {
                    cout << "You still have " << tries-- << " tries left"<< endl;
                    tries--;
                }
            }
            if (guess != randomNumber) {
                cout << endl;
                cout << "Sorry, you hace lost " << bettingAmount << "$" << endl;
                cout << "The winning number was " << randomNumber << endl;
            }

            if (balance == 0) {
                cout << "You ran out of money" << endl;
                break;
            }

            if (balance >= 1) {
                char msgOut[3];
                cout << "Wanna bet some more?" << endl;
                cout << "-> ";
                cin >> msgOut;

                if (!validateMsg(msgOut))
                    break;
            }

        } while (true);
    } else {

        do {
        int randomNumber = generateRandomNumber(gameMode, 0, 0);
        cout << endl << "Your current balance is " << balance << "$" << endl;
        do {
            cout << "Hey!, " << playerName << ", enter amount to bet: ";
            cin >> bettingAmount;

            if (bettingAmount > balance) {
                cout << "Hmmm, How can you bet money you don't even have?" << endl;
                cout << "Let's try again" << endl;
                cout << "OK?" << endl;

                system("cls");
            }
        } while ((bettingAmount < 1) || (bettingAmount > balance));
        balance -= bettingAmount;
        string msg = (gameMode == 3) ? "Enter a number between 1 to 100" : "Enter a number between 1 to 10";
        int guess;
        do {
            cout << msg << endl;
            cout << "-> ";
            cin >> guess;
        } while ((guess < 1) || (guess > 100));

        if (randomNumber == guess) {
            cout << "You have won " << bettingAmount * multiplier << "$" << endl;
            balance += (bettingAmount * multiplier);
        } else {
            cout << "Sorry, you have lost " << bettingAmount << "$" << endl;
            cout << "The winning number was " << randomNumber << endl;
        }

        
        if (balance == 0) {
            cout << "You ran out of money" << endl;
            break;
        }

        if (balance >= 1) {
            char msgOut[3];
            cout << "Wanna bet some more?" << endl;
            cout << "-> ";
            cin >> msgOut;

            if (!validateMsg(msgOut))
                break;
        }

    } while (true);

    }
}

void godModeGameMode(string& playerName, float& balance, int& gameMode,int& multiplier) {
    cout << endl;
    cout << "God Mode Enabled" << endl;

    cout << "Just one chance to win" << endl;
    cout << "Do it carefully" << endl;

    float bettingAmount;
    do {
        cout << "Your balance: " << balance << endl;
        do {
            cout << "Hey, " << playerName << ", enter amount to bet: ";
            cin >> bettingAmount;
        } while ((bettingAmount < 0) || (bettingAmount > balance));

        int randomNumber = generateRandomNumber(gameMode, 0, 0);

        int guess;
        cout << "So..., what's your answer?" << endl;
        cout << "-> ";
        cin >> guess;

        if (guess == randomNumber) {
            cout << "Oh" << endl;
            cout << "You have won " << bettingAmount * multiplier << "$" << endl;
            cout << "Congrats" << endl;

            balance -= bettingAmount;
            balance += bettingAmount * multiplier;
        } else {
            cout << "Sorry, you hace lost " << bettingAmount << " * 10 = " << bettingAmount * 10 << endl;
            balance -= (bettingAmount * 10);
        }

        if (balance == 0) {
            cout << "You ran out of money" << endl;
                break;
        }

        if (balance >= 0) {
            char msgOut[3];
            cout << "Wanna play again?" << endl;
            cout << "-> ";
            cin >> msgOut;

            if (!validateMsg(msgOut)) 
                break;
        }
    } while (true);
}

void customGameMode(string& playerName, float& balance, int& gameMode) {
    cout << endl;
    cout << "Custom Game Mode" << endl;
    cout << "You select everything" << endl;

    int lowerLimit, upperLimit, tries, multiplier;
    bool triesEnabled;

    do {
        cout << "Select the Lower limit of the range of numbers: ";
        cin >> lowerLimit;
    } while(lowerLimit < 1);

    do {
        cout << "Select the Upper limit of the range of numbers: ";
        cin >> upperLimit;
    } while (upperLimit < 1);

    if (lowerLimit > upperLimit) {
        cout << "Swapping numbers [...]" << endl;
        swap(lowerLimit, upperLimit);
    }

    do {
        cout << "Multiplier?" << endl;
        cout << "-> ";
        cin >> multiplier;
    } while (multiplier < 1);

    char msgValidate[3];
    cout << "Wanna have more than one try?" << endl;
    cout << "-> ";
    cin >> msgValidate;

    if (!validateMsg(msgValidate)) {
        cout << "Ok ..." << endl;
        triesEnabled = true;
        do {
            cout << "How many btw?" << endl;
            cout << "-> ";
            cin >> tries;
        } while (tries < 1);
    }

    system("cls");
    cout << endl;

    do {
        cout << "Your balance: " << balance;
        bool userWon = false;
        if (triesEnabled) {
            float bettingAmount;
            cout << endl;
            do {
                cout << "Hey, " << playerName << ", enter amount to bet: ";
                cin >> bettingAmount;
            } while ((bettingAmount < 1) || (bettingAmount > balance));

            int randomNumber = generateRandomNumber(gameMode, lowerLimit, upperLimit);
            balance -= bettingAmount;
            do {
                int guess;
                cout << "Enter a number between " << lowerLimit << " and " << upperLimit << endl;
                cout << "-> ";
                cin >> guess;
                tries--;
                if (guess == randomNumber) {
                    cout << "You have won " << bettingAmount * multiplier << "$" << endl;
                    balance += bettingAmount * multiplier;
                    userWon = true;
                    break;
                } else {
                    cout << "Let's try again ..." << endl;
                }

            } while (tries > 0);

            if (!userWon) {
                cout << "YOu have lost " << bettingAmount << endl;
            }

            if (balance == 0) {
                cout << "You ran out of money" << endl;
                break;
            }

            if (balance >= 1) {
                char playAgain[3];
                cout << "Wanna play again?" << endl;
                cout << "-> ";
                cin >> playAgain;

                if (!validateMsg(playAgain))
                    break;
            }
        } else {
            float bettingAmount;
            cout << endl;
            do {
                cout << "Hey, " << playerName << ", enter amount to bet: ";
                cin >> bettingAmount;
            } while ((bettingAmount < 1) || (bettingAmount > balance));

            balance -= bettingAmount;
            int randomNumber = generateRandomNumber(gameMode, lowerLimit, upperLimit);

            int guess;
            cout << "Enter a number between " << upperLimit << " and " << lowerLimit << endl;
            cout << "-> ";
            cin >> guess;

            if (guess == randomNumber) {
                cout << "You hace won " << bettingAmount * multiplier << "$" << endl;
                balance += bettingAmount * multiplier;
            } else {
                cout << "You have lost " << bettingAmount << "$" << endl;
                cout << "The random number weas " << randomNumber << endl;
            }

            if (balance == 0) {
                cout << "You ran out of money" << endl;
                break;
            }

            if (balance >= 1) {
                char msgOut[3];
                cout << "Wanna bet some more? " << endl;
                cout << "-> ";
                cin >> msgOut;

                if (!validateMsg(msgOut))
                    break;
            }
        }
    } while (true);
}

void preGameHandler(int& gameMode, int& multiplier, string& playerName, float& balance) {
    cout << "You have selected option " << gameMode << endl;
    switch (gameMode) {
        case 2: 
            cout << "The system is gonna generate a random number (1-10), and then you're gonna have 5 chances to guess it" << endl;
            multiplier = 5;
            normalGameMode(true, playerName, balance, gameMode, multiplier);
            break;
        case 3:
            cout << "The system is gonna generate a random number (1-100), and then you're gonna hace one chance to guess it" << endl;
            multiplier = 25;
            normalGameMode(false, playerName, balance, gameMode, multiplier);
            break;
        case 4:
            cout << "The system is gonna generate a random number (1-100), and then you're gonna have 5 chances to guess it" << endl;
            multiplier = 20;
            normalGameMode(true, playerName, balance, gameMode, multiplier);
            break;
        case 5:
            cout << "The system is gonna generate a random number (1-1000), You win 50X but you lose 10X what you bet" << endl;
            multiplier = 50;
            godModeGameMode(playerName, balance, gameMode,multiplier);
            break;
        case 6:
            cout << "You select everything, the range of numbers, the no. of tries, and even how much you win" << endl;
            customGameMode(playerName, balance, gameMode);
            break;
        default:
            cout << "The system is gonna generate a random number (1-10), and then you're gonna hace one chance to guess it" << endl;
            multiplier = 10;
            normalGameMode(false, playerName, balance, gameMode, multiplier);
    }
}