#include <bits/stdc++.h>

using namespace std;

void calcular(int, int, int&, int&);

int main() {
    int num1, num2, suma = 0, mult = 0;
    
    cout << "Digite 2 numeros: ";
    cin >> num1 >> num2;

    calcular(num1, num2, suma, mult);

    cout << suma << endl;
    cout << mult << endl;

    return 0;
}

void calcular(int num1, int num2, int& suma, int& mult) {
    suma = num1 + num2;
    mult = num1 * num2;
}