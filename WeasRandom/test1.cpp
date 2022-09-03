#include <bits/stdc++.h>

using namespace std;
bool validarNota(float nota) 

int main() {
    // array <int, 4> numeros;

    // numeros[0] = 12;

    // for (auto i : numeros)
    //     cout << i << endl;

    // // int num[4] = {1, 2, 3, 4};
    // // cout << numeros.size() << endl;
    // // cout << num.size() << endl;

    // array <int, 4> numeros = {1, 2, 3, 4};
    // bool isEmpty = numeros.empty();
    // cout << uppercase << boolalpha << isEmpty << endl;

    // char msg[] = "buenos dias";
    // char msgUpperCase;
    // for (int i = 0; i < strlen(msg); i++) {
    //     msgUpperCase = toupper(msg[i]);
    //     cout << msgUpperCase;
    // }

    // array <int, 3> numeros;
    // numeros.fill(1);

    // for (int i : numeros)
    //     cout << numeros[i] << ' ';

    // numeros[0] = 4;

    // for (auto i : numeros)
    //     cout << i << ' ';

    return 0;
}

bool validarNota(float nota)
    return ((nota >= 0.0) && (nota <= 5.0)) ? true : false;
