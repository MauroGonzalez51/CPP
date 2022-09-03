#include <iostream>
#include <cmath>

using namespace std;

float calcularIMC(float peso, float estatura);

int main()
{
    int pDelMuySevera = 0, pDelSevera = 0, pDelgadez = 0, pSaludable = 0, pSobrepeso = 0, pObesidad = 0;
    int sumEdadDelSevera = 0;
    float maxPeso = 0, maxEstatura, maxEdad;
    do
    {
        float peso, estatura;
        int edad;

        cout << "Ingrese su peso en KG: ";
        cin >> peso;

        cout << "Ingrese su estatura en M: ";
        cin >> estatura;

        cout << "Ingrese su Edad: ";
        cin >> edad;

        cout << endl;
        float IMC = calcularIMC(peso, estatura);

        if (IMC < 14.0)
        {
            cout << "Delgadez muy severa (" << IMC << ")" << endl;
            pDelMuySevera += 1;
        }
        else if ((IMC >= 14.0) && (IMC <= 16.9))
        {
            cout << "Delgadez severa (" << IMC << ")" << endl;
            pDelSevera += 1;
            sumEdadDelSevera += edad;
        }
        else if ((IMC >= 17.0) && (IMC <= 19.5))
        {
            cout << "Delgadez (" << IMC << ")" << endl;
            pDelgadez += 1;
        }
        else if ((IMC >= 19.6) && (IMC <= 25.9))
        {
            cout << "Peso saludable (" << IMC << ")" << endl;
            pSaludable += 1;
        }
        else if ((IMC >= 26.0) && (IMC <= 29.9))
        {
            cout << "Sobrepeso (" << IMC << ")" << endl;
            pSobrepeso += 1;
        }
        else
        {
            cout << "Obesidad (" << IMC << ")" << endl;
            pObesidad += 1;
        }

        if (peso > maxPeso)
        {
            maxPeso = peso;
            maxEstatura = estatura;
            maxEdad = edad;
        }

        cout << endl;
        int salir;
        cout << "Salir?" << endl;
        cout << "[0] Para Salir" << endl;
        cout << "[1] Para continuar" << endl;
        cout << "-> ";
        cin >> salir;

        salir = (salir == 0) ? true : false;

        if (salir)
            break;

    } while (true);

    int totalPersonas = pDelMuySevera + pDelSevera + pDelgadez + pSaludable + pSobrepeso + pObesidad;

    cout << "Personas en cada categoria" << endl;
    cout << "Delgadez muy Severa: " << pDelMuySevera << endl;
    cout << "Delgadez Severa: " << pDelSevera << endl;
    cout << "Delgadez: " << pDelgadez << endl;
    cout << "Saludable: " << pSaludable << endl;
    cout << "Sobrepeso: " << pSobrepeso << endl;
    cout << "Obesidad: " << pObesidad << endl;

    cout << "Porcentaje de personas con peso saludable: " << pSaludable / totalPersonas << "%" << endl;
    cout << "Edad promedio de las personas con delgadez severa: " << sumEdadDelSevera / pDelSevera << endl;
    cout << "Datos de la persona con mas peso del estudio" << endl;
    cout << "Peso: " << maxPeso << endl;
    cout << "Estatura: " << maxEstatura << endl;
    cout << "Edad: " << maxEdad << endl;

    return 0;
}
float calcularIMC(float peso, float estatura)
{
    float IMC = peso / (pow(estatura, 2));
    return IMC;
}