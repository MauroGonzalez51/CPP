#include <iostream>
#include <conio.h>
using namespace std;

//Definir un vector y sumar sus numeros
//En español array
int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int suma = 0;

    for (int i = 0; i < 5; i++) {
        suma += numeros[i];
    }
    cout << "Suma: " << suma << endl;


    int num[] = {1, 4, 3, 7, 9};
    int mult = 1;
    for (int j = 0; j < 5; j++) {
        mult *= num[j];
    }
    cout << "Multiplicacion: " << mult << endl;

    getch();
    return 0;
}