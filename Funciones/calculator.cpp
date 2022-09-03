#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

char mainMenu();

void lanzarOperacion(char numOperacion);

float suma();

float resta();

float mult();

float division();

void divisores();

void tablaMult();

float potenciacion();

int main() {
    lanzarOperacion(mainMenu());
    getch();
    return 0;
}

char mainMenu() {
    int operacion;
    cout << "Ingrese el numero con la operacion a realizar: " << endl;
    cout << "1. Sumar " << endl;
    cout << "2. Restar " << endl;
    cout << "3. Multiplicar " << endl;
    cout << "4. Dividir " << endl;
    cout << "5. Divisores de 1 numero " << endl;
    cout << "6. Tabla de Multiplicar de 1 numero " << endl;
    cout << "7. Potenciacion " << endl;
    cout << "-> ";

    cin >> operacion;
    return operacion;
}

void lanzarOperacion(char numOperacion) {
    switch (numOperacion) {
        case 1:
            cout << suma() << endl;
            break;

        case 2:
            cout << resta() << endl;
            break;

        case 3:
            cout << mult() << endl;
            break;

        case 4:
            cout << division() << endl;
            break;
        
        case 5:
            divisores();
            break;
        
        case 6:
            tablaMult();
            break;
        
        case 7:
            cout << potenciacion() << endl;
            break;

        default:
            cout << "Error al lanzar la operacion" << endl;
    }
}

float suma() {
    float num1, num2;
    cout << "Ingrese 2 numeros para sumarlos: ";
    cin >> num1 >> num2;
    return (num1 + num1);
}

float resta() {
    float num1, num2;
    cout << "Ingrese 2 numeros para restarlos: ";
    cin >> num1, num2;
    return (num1 - num2);
}

float mult() {
    float num1, num2;
    cout << "Ingrese 2 numeros para multiplicarlos: ";
    cin >> num1 >> num2;
    return (num1 * num2);
}

float division() {
    float dividendo, divisor;
    cout << "Dividendo: ";
    cin >> dividendo;

    cout << "Divisor: ";
    cin >> divisor;

    while (divisor == 0) {
        cout << "Eror, division por 0, Ingrese un valor valido: ";
        cin >> divisor;
    }

    return (dividendo / divisor);
}

void divisores() {
    int numero, cantidadDivisores = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        if ((numero % i) == 0) {
            cout << "Es divisible por " << i << endl;
            cantidadDivisores += 1;
        }
    }
    cout << "Es divisible por " << cantidadDivisores << " numeros" << endl;
}

void tablaMult() {
    int num, limit;
    cout << "Ingrese un numero para crear la tabla: ";
    cin >> num;

    cout << "Hasta que numero se va a multiplicar?: ";
    cin >> limit;

    for (int i = 1; i <= limit; i++) {
        cout << num << " * " << i << " = " << (num * i) << endl;
    }
}

float potenciacion() {
    float numero, elevado;
    cout << "Numero +  Elevado a: ";
    cin >> numero >> elevado;
    return (pow(numero, elevado));
}