#include <bits/stdc++.h>

using namespace std;

class Numeros {
    public:
        int numero;
};

int sumar(Numeros& n1, Numeros& n2) {
    return (n1.numero + n2.numero);
}

int restar(Numeros& n1, Numeros& n2) {
    return (n1.numero - n2.numero);
}

int multiplicar(Numeros& n1, Numeros& n2) {
    return (n1.numero * n2.numero);
}

int dividir(Numeros& n1, Numeros& n2) {
    if (n2.numero == 0)
        exit(EXIT_FAILURE);
    else 
        return (n1.numero / n2.numero);
}


int main() {
    Numeros num1, num2;
    int opcion;
    cout << "Ingrese un numero: ";
    cin >> num1.numero;

    cout << "Ingrese un numero: ";
    cin >> num2.numero;

    cout << endl;
    cout << "[1]: Sumar" << endl;
    cout << "[2]: Restar" << endl;
    cout << "[3]: Multiplicar" << endl;
    cout << "[4]: Dividir" << endl;
    cout << "-> ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            cout << sumar(num1, num2);
            break;
        }
        case 2: {
            cout << restar(num1, num2);
            break;
        }
        case 3: {
            cout << multiplicar(num1, num2);
            break;
        }
        case 4: {
            cout << dividir(num1, num2);
            break;
        }
        default:
            cout << "Opcion no encontrada" <<  endl;
            exit(1);
    }
    return 0;
}