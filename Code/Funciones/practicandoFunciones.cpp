//Encontrar el mayor de 2 numeros

#include <iostream>
#include <conio.h>
using namespace std;

//Prototipo de funcion
int encontrarMax(int x, int y);

int main() {
    int n1, n2;

    cout << "Digite 2 numeros: ";
    cin >> n1 >> n2;

    cout << "El mayor de los 2 numeros es "<< encontrarMax(n1, n2) << endl;

    getch();
    return 0;
}

//Definicion de funcion
int encontrarMax(int x, int y) {
    return (x > y) ? x : y;
}