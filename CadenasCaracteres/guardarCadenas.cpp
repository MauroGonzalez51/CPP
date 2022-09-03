#include <iostream>
#include <conio.h>
#include <string.h>


using namespace std;

int main() {
    char palabra1[] = "Maurito";
    char palabra2[] = {'M', 'a', 'u', 'r', 'i', 't', 'o'};

    // cout << palabra1 << endl;
    //  cout << palabra2 << endl;


    //Digitando el nombre del usuario
    char nombre[20];
    cout << "Digite su nombre: ";
    cin.getline(nombre, 20, '\n');

    cout << nombre << endl;

    getch();
    return 0;
}