#include <bits/stdc++.h>

using namespace std;

class numeros {
    public:
        float numero;

        float abs();
};

float numeros::abs() {
    return ((this -> numero < 0) ? -1 * this -> numero : numero);
}


int main() {
    numeros num1;
    cout << "Ingrese un numero: ";
    cin >> num1.numero;

    cout << num1.abs();
    return 0;
}