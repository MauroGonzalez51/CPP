#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int rangoMin, rangoMax, intentos, numero, counter = 0;

    cout << "\nIngrese el rango minimo: \n";
    cin >> rangoMin;

    cout << "\nIngrese el rango maximo: \n";
    cin >> rangoMax;

    if (rangoMax < rangoMin) {
        swap(rangoMin, rangoMax);
    }
    
    // Variable = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior)
    int numeroRandom = rangoMin + rand() % ((rangoMax + 1) - rangoMin);
    
    do {
        cout << "\nIngrese un numero (Intento " << counter + 1 << "): \n";
        cin >> numero;

        if (numero > numeroRandom) {
            cout << "\nIngrese un numero menor\n";
        } else if ( numero < numeroRandom ) { 
            cout << "\nIngrese un numero mayor\n";
        }
        counter++;
    } while (numeroRandom != numero);
    
    return 0;
}
