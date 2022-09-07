/**
 * @brief  Mauro Gonzalez
 * @note Just as it sounds, including more files   
 * @retval 0
 */

#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int num1, num2;
    cout << "Ingrese dos numeros: ";
    cin >> num1 >> num2;

    cout << sumarNumeros(num1, num2);

    return 0;
}