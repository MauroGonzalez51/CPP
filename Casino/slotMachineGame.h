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

void manageCoins(int& coins, int& bettingAmount, bool userWin, int checkedCase, int twoSame, int threeSame) {
    if (userWin) {
        switch (checkedCase) {
            case 2: {
                cout << "You bet " << bettingAmount << " coin" << endl;
                cout << "You win " << twoSame << " coins" << endl;
                coins += twoSame;
                break;
            }
            case 3: {
                cout << "You bet " << bettingAmount << " coin" << endl;
                cout << "You win " << threeSame * 2 << " coins" << endl;
                coins += threeSame * 2;
                break;
            }
            case 777: {
                cout << "You bet " << bettingAmount << " coin" << endl;
                cout << "You win 777 coins" << endl;
                coins += 777;
                break; 
            }
            default: {
                cout << "How did I get here?" << endl;
            }
        }
    } else {
        cout << "You have Lost one coin :>" << endl;
    }
}

void searchingCoincidences(int num1, int num2, int num3, int& coins, int& bettingAmount) { 
    // cout << num1 << " " << num2 << " " << num3 << endl;

    array <int, 3> numbers = { num1, num2, num3 };
    array <int, 3> repeatNumbers;
    repeatNumbers.fill(0);

    bool checkNextCase = true;
    // There are all different?
    {
        for (int i = 0; i < numbers.size(); i++) {
            int times = 0;
            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[i] == numbers[j])
                    times++;    
            }
            cout << "Number: " << numbers[i] << ", repeat: " << times << endl;

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
            cout << "There are all different :>" << endl;
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

        cout << "Pair: " << pairNumber << endl;
        manageCoins(int& coins, int& bettingAmount, true, 2, pairNumber, 0);
        checkNextCase = false;
    }

    // 2 Case: All the same
    if (checkNextCase) {
        int threeNumber, times = 0, sample = repeatNumbers[0];
        for (auto i : repeatNumbers) {
            if (i == sample)
                times++;
        }

        if (times == 3) {
            cout << "Three: " << threeNumber << endl;
            manageCoins(int& coins, int& bettingAmount, true, 3, 0, threeNumber);
        }
    }
    
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