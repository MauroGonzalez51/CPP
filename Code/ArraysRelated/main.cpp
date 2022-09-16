/**
 * @autor: Mauro Gonzalez  
 * @codigo: T00067622   
 * @programa: Ing. de Sistemas y Computacion
 * @descripcion: Menú con opciones a elegir
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>

using namespace std;


// Inicializando las funciones
void opcion1();
void opcion2();

int main() {
    int opcion;
    // Mostrando el Menú
    cout << "Menu Principal" << endl;
    cout << "1. Calcular Inversion" << endl;
    cout << "2. Cambiar valores de 3 numeros" << endl;
    cout << "-> ";
    cin >> opcion;
    
    // Evaluando las opciones usando swicth
    switch (opcion) {
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;

        default:
            cout << "Opcion no encontrada ..." << endl;
    }
    cout << "Presione cualquier tecla para salir (...)";
    getch();
    return 0;
}

void opcion1(){
    // Declarando variables
    int inversion, interesesTotal = 0;

    // Pidiendo los datos
    cout << "Cantidad a Invertir: ";
    cin >> inversion;

    cout << "Plazo Fijo de 12 meses" << endl;

    // Creando un bucle que se repita por cada uno de los 12 meses
    for (int i = 1; i <= 12; i++) {
        // Intereses del 1.9% mensual -> 1.9 / 100 = 0.019, entonces ...
        // Como cada mes aumenta el 1.9%, seria -> valor * (1 +  0.019)
        int intereses = (inversion * 1.019) - inversion;
        inversion += intereses;
        interesesTotal += intereses;
    }
    cout << "Dinero Final: " << inversion << endl;
    cout << "Intereses generados durante los 12 meses: " << interesesTotal << endl;
}


void opcion2(){
    // Declarando variables
    int numero1, numero2, numero3;
    
    // Pidiendo los datos
    cout << "Ingrese 3 numeros: ";
    cin >> numero1 >> numero2 >> numero3;

    // Mostrando los valores iniciales
    cout << endl;
    cout << "Valores iniciales" << endl;
    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;
    cout << "Numero 3: " << numero3 << endl;
    
    // Creando un array con los numeros ingresados
    int numeros[3] = {numero1, numero2, numero3};

    // Numero random de veces que se van a cambiar los numeros
    int cantidadVeces = rand() % 100;

    // Bucle para cambiar los numeros
    for (int i = 0; i <= cantidadVeces; i++) {
        // Usando la funcion swap() para cambiar los numeros, ademas de tomar un indice random de la lista
        // Pd: El cambiar numeros se puede hacer usando una variable AUX, pero asi es mas rapido :>
        swap(numeros[rand() % 3],numeros[rand() % 3]);
    }

    // Mostrando los valores finales
    cout << "Valores Finales" << endl;
    cout << "Numero 1: " << numeros[0] << endl;
    cout << "Numero 2: " << numeros[1] << endl;
    cout << "Numero 3: " << numeros[2] << endl;
    // Al ser totalmente random, puede que haya veces en las que cambie solo 2 numeros ...
}