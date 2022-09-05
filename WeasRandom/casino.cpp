#include <bits/stdc++.h>

using namespace std;

void displayGameModes();

void preGameHandler(int& gameMode, int& multiplier);

int generateRandomNumber(int& gameMode);

void getOut(char msg[3]);

void normalGamemode(bool triesEnabled, string& playerName, float& balance, int& gameMode, int& multiplier);

int main() {
    string playerName;
    float balance;
    cout << "\n\tWelcome to the Casino" << endl;
    cout << "Enter your name to play: ";
    getline(cin, playerName);

    do {
        cout << "Enter your inicial balance to play: ";
        cin >> balance;
    } while (balance < 1);

    displayGameModes();
    int gameMode, multiplier;
    cout << "So ... wich one you wanna play?" << endl;
    cout << "[Default gamemode is \"1\"]" << endl;
    cout << "-> ";
    cin >> gameMode;
    preGameHandler(gameMode, multiplier);
    return 0;
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

void preGameHandler(int& gameMode, int& multiplier) {
    string msg;
    cout << "You have selected option " << gameMode << endl;
    switch (gameMode) {
        case 2: 
            msg = "The system is gonna generate a random number (1-10), and then you're gonna have 5 chances to guess it";
            multiplier = 5;
            break;
        case 3:
            msg = "The system is gonna generate a random number (1-100), and then you're gonna hace one chance to guess it";
            multiplier = 25;
            break;
        case 4:
            msg = "The system is gonna generate a random number (1-100), and then you're gonna have 5 chances to guess it";
            multiplier = 20;
            break;
        case 5:
            msg = "The system is gonna generate a random number (1-1000), next you select if you wanna have multiple tries or not, and then you have to guess it";
            multiplier = 50;
            break;
        case 6:
            msg = "You select everything, the range of numbers, the no. of tries, and even how much you win";
            break;
        default:
            msg = "The system is gonna generate a random number (1-10), and then you're gonna hace one chance to guess it";
            multiplier = 10;
            break;
    }
    cout << endl;
    cout << msg << endl;
}

int generateRandomNumber(int& gameMode) {
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
            int lowLimit, upperLimit;
            do {
                cout << "Enter lower limit: ";
                cin >> lowLimit;

                cout << "Enter upper limit: ";
                cin >> upperLimit;
            } while ((lowLimit == upperLimit) || (lowLimit > upperLimit));
            randomNumber = lowLimit + rand() % ((upperLimit + 1) - 1);
        default:
            randomNumber = 1 + rand() % (11 - 1);
            break;
    }
    return randomNumber;
}

bool getOut(char msg[3]) {
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

void normalGamemode(bool triesEnabled, string& playerName, float& balance, int& gameMode, int& multiplier) {
    system("cls");
    float bettingAmount;
    if (triesEnabled) {
        do {
            int tries = 5;
            int randomNumber = generateRandomNumber(gameMode);
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

                if (!getOut(msgOut))
                    break;
            }

        } while (true);
    } else {

        do {
        int randomNumber = generateRandomNumber(gameMode);
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

            if (!getOut(msgOut))
                break;
        }

    } while (true);

    }
}