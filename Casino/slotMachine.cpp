#include <bits/stdc++.h>

using namespace std;

int generateRandomNumber() {
    srand(time(NULL));
    return (rand() % (10 - 1));
}

class machineSlots {
    public:
        int number;
};

int main() {
    int FPS = 30;

    for (int i = 1; i <= FPS; i++) {
        int slot1, slot2, slot3;

        [slot1, slot2, slot3] = generateRandomNumber();

        cout << slot1 << " " << slot2 << " " << slot3 << endl;
    }


    return 0;
}