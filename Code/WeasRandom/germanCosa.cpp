#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, grupo1 = 0, grupo2 = 0, sum1 = 0, sum2 = 0, cambio = 0;
    float prom1 = 0, prom2 = 0;
    do
    {
        cout << "Ingresa la cantidad de trabajadores: ";
        cin >> n;
    } while (n < 1 || n > 50);
    string id[n];
    int grupo[n];
    int sueldo[n];
    for (int i = 0; i < n; i++)
    {
        cout << "El codigo del empleado " << i + 1 << " es: ";
        cin >> id[i];
        do
        {
            cout << "El grupo al que pertenece es ";
            cin >> grupo[i];
        } while (grupo[i] != 1 && grupo[i] != 2);
        do
        {
            cout << "El salario semanal del empleado " << i + 1 << " es: ";
            cin >> sueldo[i];
        } while (sueldo[i] < 1);
    }
    for (int x = 0; x < n; x++)
    {
        if (grupo[x] == 1)
        {
            sueldo[x] += 250000;
            grupo1++;
        }
        if (grupo[x] == 2)
        {
            sueldo[x] += 150000;
            grupo2++;
        }
    }
    for (int x = 0; x < n; x++)
    {
        if (grupo[x] == 1)
        {
            sum1 += sueldo[x];
        }
        else
        {
            sum2 += sueldo[x];
        }
    }
    
    prom1 = sum1 / grupo1;
    prom2 = sum2 / grupo2;

    for (int i = 0; i < n; i++)
    {
        if ((grupo[i] == 1) && (sueldo[i] > prom1))
        {
            grupo[i] = 2;
            cambio++;
        }
    }

    cout << "Cantidad de personas que hay en cada grupo: " << endl;
    cout << "Grupo1 = " << grupo1 << endl;
    cout << "Grupo2 = " << grupo2 << endl;
    cout << "El promedio de salario del grupo 1 es: " << prom1 << endl;
    cout << "El promedio de salario del grupo 2 es: " << prom2 << endl;
    cout << "El numero de cambios fue: " << cambio << endl;

    cout << "////////////////////////////////////////////////////////" << endl;
    cout << "Datos actualizados";

    for (int x = 0; x < n; x++) {
        cout << "Codigo: " << id[x] << " - Grupo: " << grupo[x] << " - Salario: " << sueldo[x] << endl; 
    }
}