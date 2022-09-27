#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Fracciones {
    public:
        int numerador, denominador;
};  

void setDivisores(Fracciones& fraccion) {
    vector <int> numerador;
    vector <int> denominador;

    for (int i = 0; i < fraccion.numerador; i++) {
        if ((fraccion.numerador % i) == 0) {
            numerador.push_back(i);
            cout << i << endl;
        }
    }

    for (int i = 0; i < fraccion.denominador; i++) {
        if ((fraccion.denominador % i) == 0) {
            denominador.push_back(i);
        }
    }

    
}

int main() {
    system("cls");
    cout << "Simplificador de Fracciones" << endl;

    Fracciones fraccion;

    cout << "Numerador: ";
    cin >> fraccion.numerador;

    do {
        cout << "Denominador: ";
        cin >> fraccion.denominador;
    } while (fraccion.denominador == 0);

    setDivisores(fraccion);


    return 0;
}