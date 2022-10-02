/**
 *  @group:
 *       - Mauro Alonso Gonzalez Figueroa       T00067622   Ing. Sistemas
 *       - Juan Jose Jimenez Guardo             T00068278   Ing. Sistemas
 *       - Maria Isabel Barrios Verbel          T00068465   Ing. Industrial
 * 
 *  @date: 02/10/2022
 *  @description: calcular el coeficiente de correlacion
 *
 * */

#include <bits/stdc++.h>

using namespace std;

// Se crea un template de Jugadores, para incializarlos con sus propiedades
class Jugadores {
    public:
        float estatura, peso;

        bool validarEstatura() {
            return ((this -> estatura > 0.0) ? false : true);
        }

        bool validarPeso() {
            return ((this -> peso > 0.0) ? false : true);
        }
};

// Estructura de control que guarda las variables "Importantes"
// En resumen, se agrupan varias variables en un solo lugar con scope global
struct {
    float promedioEstatura, promedioPeso;
    
    float sumatoriaCovarianza = 0.0;

    float covarianza;

    float desviacionEstatura, desviacionPeso;

    float sumatoriaCuadradosEstatura = 0.0, sumatoriaCuadradosPeso = 0.0;
} variablesControl;

// Funcion para pedir la estatura de cada uno de los jugadores
void pedirEstatura(Jugadores& jugador, int posicion) {
    cout << endl;
    cout << "[" << posicion + 1 << "] Estatura [M]" << endl;
    do {
        cout << "-> ";
        cin >> jugador.estatura;
    } while (jugador.validarEstatura());
}

// Funcion para pedir el peso de cada uno de los jugadores
void pedirPeso(Jugadores& jugador, int posicion) {
    cout << endl;
    cout << "[" << posicion + 1 << "] Peso [Kg]" << endl;
    do {
        cout << "-> ";
        cin >> jugador.peso;
    } while (jugador.validarPeso());
}

// Funcion para calcular el promedio dependiendo de lo que se requiera
// La variable proceso controla que promedio se va a calcular :>
void calcularPromedio(Jugadores& jugador, float& sumaTotal, int proceso) {
    switch(proceso) {
        case 1: {
            sumaTotal += jugador.estatura;
            break;
        }
        case 0: {
            sumaTotal += jugador.peso;
            break;
        }
        default: {
            cout << "[...]" << endl;
        }
    }
}

// Funcion para calcular la desviacion dependiendo de lo que se requiera
// La variable proceso controla la desviacion que se va a calcular :>
void calcularDesviacion(Jugadores& jugador, int proceso) {
    switch (proceso) {
        case 1: {
            variablesControl.sumatoriaCuadradosEstatura += pow((jugador.estatura - variablesControl.promedioEstatura), 2);
            break;
        }
        case 0: {
            variablesControl.sumatoriaCuadradosPeso += pow((jugador.peso - variablesControl.promedioPeso), 2);
            break;
        }
        default: {
            cout << "[...]" << endl;
        }
    }
}

// Funcion para calcular el coeficiente de correlacion, despues de haber obtenido las variables necesarias
// Como las variables tienen scope global, no es necesario pasar parametros a la funcion :>
float coeficienteCorrelacion() {
    return ((variablesControl.covarianza)/(variablesControl.desviacionEstatura * variablesControl.desviacionPeso));
}


int main() {

    // Variables que solo pueden guardar datos positivos o cero
    unsigned tiempoInicial, tiempoFinal;

    // Variable de control que guarda la cantidad de jugadores que se van a estudiar
    int cantidadJugadores;

    do {
        cout << "Ingrese la cantidad de jugadores: ";
        cin >> cantidadJugadores;
    } while (cantidadJugadores < 1);

    // Se crea un array de objetos con el tamaño de la cantidad de jugadores
    Jugadores jugadores[cantidadJugadores];

    // Se le pide a cada uno de los jugadores el peso y la estatura
    // Llamando a las funciones respectivas
    for (int i = 0; i < cantidadJugadores; i++) {
        pedirEstatura(jugadores[i], i);
        pedirPeso(jugadores[i], i);
    }

    // Tiempo de ejecucion = tiempoFinal - tiempoInicial
    tiempoInicial = clock();
    
    // Se calcula el promedio de la estatura
    float sumaTotalEstatura = 0.0;
    for (int i = 0; i < cantidadJugadores; i++)
        calcularPromedio(jugadores[i], sumaTotalEstatura, 1);

    // Se guarda el promedio de la estatura calculado en la estructura de control
    variablesControl.promedioEstatura = sumaTotalEstatura / cantidadJugadores;

    // Se calcula el promedio del peso 
    float sumaTotalPeso = 0.0;
    for (int i = 0; i < cantidadJugadores; i++)
        calcularPromedio(jugadores[i], sumaTotalPeso, 0);

    // Se guarda el promedio de el peso calculado en la estructura de control
    variablesControl.promedioPeso = sumaTotalPeso / cantidadJugadores;

    // Se ejecuta la sumatoria para calcular la covarianza
    for (int i = 0; i < cantidadJugadores; i++) 
        variablesControl.sumatoriaCovarianza += (jugadores[i].estatura - variablesControl.promedioEstatura) * (jugadores[i].peso - variablesControl.promedioPeso);

    // Se guarda el valor de la covarianza despues de calcularla :>
    variablesControl.covarianza = variablesControl.sumatoriaCovarianza / cantidadJugadores;

    // Se calcula la desviacion de cada una de las variables :>
    for (int i = 0; i < cantidadJugadores; i++) {
        calcularDesviacion(jugadores[i], 1);
        calcularDesviacion(jugadores[i], 0);
    }

    // Se guarda cada una de las desviaciones en la estructura de control
    variablesControl.desviacionEstatura = sqrt(variablesControl.sumatoriaCuadradosEstatura / cantidadJugadores);
    variablesControl.desviacionPeso = sqrt(variablesControl.sumatoriaCuadradosPeso / cantidadJugadores);

    // Se imprime el coeficiente de correlacion, haciendo uso de la funcion :>
    cout << endl << "Coeficiente de Correlacion: " << coeficienteCorrelacion() << endl;

    // Estructura final para verificar el tiempo de ejecucion en los calculos
    tiempoFinal = clock();
    double time = (double(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);

    cout << "Tiempo de Ejecucion [Calculos]: " << time << " (s)" << endl;

    return EXIT_SUCCESS;
}