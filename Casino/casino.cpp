#include <bits/stdc++.h>
#include <string.h>
#include "modoJuegosCasino.h"
using namespace std;

// Cambios en Stage
int main() {
    system("cls");
    cout << "\n\tWelcome to the Casino" << endl;

    string playerName;
    float balance;

    cout << "But, before that ..." << endl; 
    cout << "Enter your name: ";
    getline(cin, playerName);


    switch(displayGames()) {
        case 1: {
            cout << "(You're playing the \"Guess a Number\" game mode)" << endl;
            cout << "(So, we recommend that the inicial balance should be bigger than 10)" << endl; 
            do {
                cout << "Enter your inicial balance to play [$]: ";
                cin >> balance;
            } while (balance < 1);

            displayGameModes();
            int gameMode, multiplier;
            cout << "So ... wich one you wanna play?" << endl;
            cout << "[Default gamemode is \"1\"]" << endl;
            cout << "-> ";
            cin >> gameMode;
            preGameHandler(gameMode, multiplier, playerName, balance);
            break;
        }
        default:
            cout << "There isn't any game mode which fits with the option entered ..." << endl;
    }
    return 0;
}