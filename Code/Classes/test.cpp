#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592654;

class Volume {
    public:
        float radius, height;

        float calculateVolume() {
            return (PI * (pow(this -> radius,2)) * (this -> height));
        }
};


int main(void) {
    Volume obj1;

    cout << "Radius: ";
    cin >> obj1.radius;

    cout << "Height: ";
    cin >> obj1.height;

    cout << "Volume: " << obj1.calculateVolume() << endl;

}