#include <iostream>
#include <string>

using namespace std;

int main()
{
    int pVotar = 0, pMVotar = 0, pFVotar = 0, pOVotar = 0;
    do {
    
        int edad, sexo;

        do
        {
            cout << "Ingrese su Edad: ";
            cin >> edad;
        } while (edad < 1);

        cout << "Ingrese su Sexo" << endl;
        cout << "[ 1 ] Masculino" << endl;
        cout << "[ 2 ] Femenino" << endl;
        cout << "[ 3 ] Otro" << endl;
        cout << "-> ";
        cin >> sexo;

        char nacionalidad[50];
        cout << "Ingrese su nacionalidad: ";
        cin >> nacionalidad;

        if (edad >= 18) {
            if (sexo == 1) {
                if (nacionalidad == "Colombiano" || nacionalidad == "colombiano") {
                    cout << "Apto para Votar" << endl;
                    pVotar += 1;
                    pMVotar += 1;
                }
            }
            if (sexo == 2) {
                if (nacionalidad == "Colombiana" || nacionalidad == "colombiana") {
                    cout << "Apta para Votar" << endl;
                    pVotar += 1;
                    pMVotar += 1;
                }
            }
            if (sexo == 3) {
                if (nacionalidad == "Colombiano" || nacionalidad == "colombiano" || nacionalidad == "Colombiana" || nacionalidad == "colombiana") {
                    cout << "Apt@ para Votar" << endl;
                    pVotar += 1;
                    pOVotar += 1;
                }
            }
        }
        int msgSalida;
        cout << "Salir?" << endl;
        cout << "[ 0 ] Para salir" << endl;
        cout << "[ 1 ] Para Continuar" << endl;
        cout << "-> ";
        cin >> msgSalida;

        if (msgSalida == 0)
            break;

    } while (true);

    cout << "Recapitulando los resultados" << endl;
    cout << "Personas aptas para votar: " << pVotar << endl;
    cout << "Cantidad de Hombres: " << pMVotar << endl;
    cout << "Cantidad de Mujeres: " << pMVotar << endl;

    return 0;
}