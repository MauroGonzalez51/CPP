/*
    @Programa: Ing. de Sistemas y Computacion
    @ID: T00067622
    @NombreAutor: Mauro Alonso Gonzalez Figueroa
    @Fecha: 9/8/2022
*/

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    float sumaMayores = 0.0, sumaMenores = 0.0;
    for (int i = 0; i < 10; i++)
    {
        cout << "Ciclo " << i + 1 << " de 10" << endl;
        float a, b;
        cout << endl;
        cout << "Ingrese el valor de A: ";
        cin >> a;
        cout << "Ingrese el valor de B: ";
        cin >> b;
        cout << endl;

        if (a == b)
        {
            cout << "Los numero son Iguales" << endl;
        }
        else
        {
            if (a > b)
            {
                cout << "A es el Mayor (" << a << ")" << endl;
                sumaMayores += a;

                cout << "B es el Menor (" << b << ")" << endl;
                sumaMenores += b;
            }
            else
            {
                cout << "B es el Mayor (" << b << ")" << endl;
                sumaMayores += b;

                cout << "A es el Menor (" << a << ")" << endl;
                sumaMenores += a;
            }
        }
        cout << endl;
    }
    float promedioMayores = sumaMayores / 10, promedioMenores = sumaMenores / 10;
    cout << "La suma de los numeros mayores es: " << sumaMayores << endl;
    cout << "La suma de los numeros menores es: " << sumaMenores << endl;

    cout << "El promedio de los numeros mayores es: " << promedioMayores << endl;
    cout << "El promedio de los numeros menores es: " << promedioMenores << endl;

    return 0;
}