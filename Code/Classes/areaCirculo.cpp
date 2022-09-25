#include <bits/stdc++.h>

using namespace std;

const float PI = 3.14159265;

class Circulo {
    public:
        float radio;

        float calculateArea() {
            return PI * pow(this -> radio, 2);
        }
};

int main() {
    Circulo* circulo = new Circulo();

    cout << "Radio: ";
    cin >> circulo -> radio;

    cout << "Area: " << circulo -> calculateArea();

    delete circulo;
}