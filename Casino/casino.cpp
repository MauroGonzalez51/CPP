// Tengo que refactorizar todo el codigo, haciendo uso de los include
// Asi no queda tan largo este archivo :>

#include <bits/stdc++.h>
#include "funciones.h"
using namespace std;

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









