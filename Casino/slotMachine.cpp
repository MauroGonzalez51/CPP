#include <bits/stdc++.h>

using namespace std;


class slotMachine {
	public:
		int number;

	void generateRandomNumber() {
		this -> number = (1 + rand() % (10 - 1));
	};

	
};

void showSlots(bool cheatingEnabled) {
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
	}
}

int main() {
	showSlots(false);
	return 0;
}


