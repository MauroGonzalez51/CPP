#include <bits/stdc++.h>
#include <conio.h>  // Just for the getch() function ;)
// In case of error just comment this ^ include, and the getch() function as well
/*
*   #include <string>   // Needed to use strings
*   #include <cstdlib>  // Needed to use random numbers
*   #include <ctime>    // Time Library
*   #include <iostream>
*   
*   @autor: mauroGonzalez
* 
* */

using namespace std;

void rules();
bool getOut(char msg[3]);
void game(float &balance, string playerName);
int generateRandomNumber(int gameMode);

int main() {
    system("cls");
    cout << endl;
    cout << "Welcome to the Casino" << endl;
    string playerName;
    float balance;

    cout << "Hey, what's your name? -> ";
    getline(cin, playerName);

    do {
        cout << "Enter the starting balance to play the game (USD): ";
        cin >> balance;
    } while (balance < 1);

    cout << endl;
    cout << "Be sure to check out the rules first" << endl;
    rules();
    game(balance, playerName);

    cout << endl;
    cout << "Press any key to continue [...] " << endl;
    getch();

    return 0;
}
void rules() {
    cout << endl << "Choose a number between 1 to 10 (Normal) or 1 to 100 (Hard)" << endl;
    cout << "[ Depending on the mode (Hard mode win 25X, normal one 10X)" << endl;
    cout << "Wrong bet, you lose al the money you bet ..." << endl;
    cout << "You only get one chance to guess" << endl;
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

int generateRandomNumber(int gameMode) {
    srand(time(NULL));
    int randomNumber;
    switch(gameMode) {
        case 2:
            randomNumber = 1 + rand() % (101 - 1);
            break;
        default:
            randomNumber = 1 + rand() % (11 - 1);
            break;
    }
    return randomNumber;
}

void game(float &balance, string playerName) {
    float bettingAmount;
    int gameMode, multiplier;

    cout << "So... select the gamemode" << endl;
    cout << "1. Normal mode" << endl;
    cout << "2. Hard mode" << endl;
    cout << "[Any other option selects the normal mode]" << endl;
    cout << "-> ";
    cin >> gameMode;

    switch(gameMode) {
        case 2:
            multiplier = 25;
            break;
        default:
            multiplier = 10;
            break;
    }

    
    system("cls");
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
        string msg = (gameMode == 2) ? "Enter a number between 1 to 100" : "Enter a number between 1 to 10";
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