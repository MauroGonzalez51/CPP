#include <iostream>
#include <time.h>
#include <string.h>
#include <array>

using namespace std;

bool cheatingEnabled = false;

class slotMachine {
	public:
		int number;

	void generateRandomNumber() {
		this -> number = (1 + rand() % (10 - 1));
	}
};
bool validateMsg(char msg[3]);

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

void searchingCoincidences(int num1, int num2, int num3, int& coins) { 
    // cout << num1 << " " << num2 << " " << num3 << endl;

    array <int, 3> numbers = { num1, num2, num3 };
    array <int, 3> repeatNumbers;
    repeatNumbers.fill(0);

    bool checkNextCase = true, userWin = false;
    // There are all different?
    {
        cout << endl;
        for (int i = 0; i < numbers.size(); i++) {
            int times = 0;
            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[i] == numbers[j])
                    times++;    
            }
            cout << "Number: " << numbers[i] << " -> repeat: " << times << endl;

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
            cout << endl << "There are all different :>" << endl;
            cout << "You lost [1] coin" << endl;
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
        cout << "You have won!" << endl;
        cout << pairNumber << " coin(s) ..." << endl;
        coins += pairNumber;
        
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
            
            cout << "You have won!" << endl;
            cout << threeNumber * 2 << " coin(s) ..." << endl;
            coins += threeNumber * 2;    

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
            cout << "You have won!" << endl;
            cout << "777 coins" << endl;

            checkNextCase = false;
            userWin = true;
        }
    }

    if (!userWin) 
        cout << endl <<  "[...]" << endl;
}

void slotMachineGame(string& playerName, int& coins) {
    rules();
    int timesPlayed = 0;
    do {
        if (timesPlayed >= 5) {
            cheatingEnabled = true;
        }

        if (coins >= 1) {
            char msgIn[3];
            cout << endl;
            cout << "Coins: " << coins << endl << endl;
            cout << "Hey, " << playerName << ", wanna play?" << endl;
            cout << "-> ";
            cin >> msgIn;

            if(validateMsg(msgIn)) {
                cout << "[...]" << endl << endl;
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

                    searchingCoincidences(slot1.number, slot2.number, slot3.number, coins);

                    timesPlayed++;

                } else {
                    slotMachine slot1, slot2, slot3;
                    int cantidadVeces = (timesPlayed / (timesPlayed * 10000)) + 1;

                    srand(time(NULL));

                    for (int i = 0; i < cantidadVeces; i++) {
                        slot1.generateRandomNumber();
                        slot2.generateRandomNumber();
                        slot3.generateRandomNumber();
                    }

                    cout << "| " << slot1.number << " | " << slot2.number << " | " << slot3.number << " | "<< endl;

                    searchingCoincidences(slot1.number, slot2.number, slot3.number, coins);
                
                    timesPlayed++;
                }

            } else {
                cout << "OK" << endl;
                break;
            }
        }

        if (coins == 0) {
            cout << "No coins found" << endl;
            break;
        }

    } while (true);
}
