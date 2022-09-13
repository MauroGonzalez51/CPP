#include <bits/stdc++.h>

using namespace std;

const int FPS = 30;

class slotMachine {
	public:
		int number;

	void generateRandomNumber() {
		this -> number = (1 + rand() % (11 -1));
	};

	
};

int main() {
	slotMachine slot1, slot2, slot3;
	srand(time(NULL));
	slot1.generateRandomNumber();
	slot2.generateRandomNumber();
	slot3.generateRandomNumber();

}


