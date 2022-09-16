#include <bits/stdc++.h>

using namespace std;

int cantidadVeces = 30;
bool cheatingEnabled = false;

class slotMachine {
	public:
		int number;

	void generateRandomNumber() {
		this -> number = (1 + rand() % (10 - 1));
	}
};


void rules() {
    cout << "[Rules]" << endl;
    cout << endl;
    cout << "1. Insert a coin [1] to play" << endl;
    cout << "2. There is many ways to win" << endl;

    cout << endl;

    cout << "Case 1: Pair of numbers" << endl;
    cout << "   - You win that many coins, that's it" << endl;

    cout << endl;

    cout << "Case 2: All the same" << endl;
    cout << "   - You win that many coins multiplied by two" << endl;

    cout << endl;

    cout << "Case 3: 777" << endl;
    cout << "   - You win 777 coins :D" << endl;

    cout << endl;

    cout << "Default: No coincidences" << endl;
    cout << "   - You lost what you bet [1 Coin]" << endl;
}

void searchingCoincidences(int num1, int num2, int num3, int& coins, int& bettingAmount) { 
    
}

void slotMachineGame(string& playerName, int& coins) {
    rules();
    do {
        char msgIn[3];
        cout << endl;
        cout << "Coins: " << coins << endl;
        cout << "Hey, " << playerName << ", wanna play?" << endl;
        cout << "-> ";
        cin >> msgIn;

        if(validateMsg(msgIn)) {
            cout << "[...]" << endl;
            int bettingAmount = 1;
            coins -= bettingAmount;

            if(!cheatingEnabled) {
                slotMachine slot1, slot2, slot3;
                int cantidadVeces = 30;

                srand(time(NULL));

                for (int i = 0; i < cantidadVeces; i++) {
                    slot1.generateRandomNumber();
                    slot2.generateRandomNumber();
                    slot3.generateRandomNumber();
                }
                cout << "| " << slot1.number << " | " << slot2.number << " | " << slot3.number << " |"<< endl;

                searchingCoincidences((int) slot1.number, (int) slot2.number, (int) slot3.number, coins, bettingAmount);
            }


        } else {
            cout << "OK" << endl;
            break;
        }

    } while (true);
}