#include <bits/stdc++.h>
#include <string>

using namespace std;

string generateNumbers(int& FPS);
void rules();
void game(int& coins, int& FPS, string playerName);
void getOut(char msg[3]);

int main() {
    int FPS = 30, coins;
    string playerName;
    cout << "Gambling game" << endl;
    cout << "Enter your name to play: ";
    getline(cin, playerName);

    rules();

    cout << "So, enter your inicial coins: ";
    cin >> coins;

    game(coins, FPS, playerName);
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

void rules() {
    system("cls");
    cout << "The rules are simple" << endl;
    cout << "You're gonna insert one coin"
    cout << "Then he machine are gona spin a lot of time" << endl;
    cout << "And if it somehow ends in 777 you win 5X" << endl;
}

string generateNumbers(int& FPS) {
    srand(time(NULL));
    int num1, num2, num3;
    for (int i = 0; i <= FPS; i++) {
        num1 = 1 + rand() % (11 - 1);
        num2 = 1 + rand() % (11 - 1);
        num3 = 1 + rand() % (11 - 1);
        
        string msg = "| " + num1 + " | " + num2 + " | " + num3 + " | ";
        return msg;
    }
}

void game(int& coins, int& FPS, string playerName) {

    do {
        int coinBet = 1;
        char msgIn[3];
        cout << "Your current balance is: " << coins << endl;
        cout << "Try your luck?" << endl;
        cout << "-> ";
        cin >> msgIn;

        if (!getOut(msgIn)) {
            coins -= coinBet;
            for (int i = 0; i < FPS; i++) {
                string displayGame = generateNumbers(int& FPS);
                cout << displayGame << endl;

            }

        }

    }
    
}