#include <bits/stdc++.h>
#include <string.h>
#include "modoJuegosCasino.h"
#include "slotMachineGame.h"

using namespace std;

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
        case 2: {
            int coins;
            cout << "(You're playing the \"Slot Machine\" game)" << endl;
            cout << "(Here, we're talking about coins, keep that in mind)" << endl;

            do {
                cout << "Enter your inicial balance to play [Coins]: ";
                cin >> coins;
            } while (coins < 1);

            slotMachineGame(playerName, coins);
            break;
        }
        default:
            cout << "There isn't any game mode which fits with the option entered ..." << endl;
    }
    cout << "Prees any key to exit ..." << endl;
    getch();
    return 0;
}