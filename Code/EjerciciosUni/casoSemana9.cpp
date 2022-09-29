#include <bits/stdc++.h>

using namespace std;

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

struct {
    float promedioEstatura, promedioPeso;
    
    float sumatoriaCovarianza = 0.0;

    float covarianza;

    float desviacionEstatura, desviacionPeso;

    float sumatoriaCuadradosEstatura = 0.0, sumatoriaCuadradosPeso = 0.0;
} variablesControl;

void pedirEstatura(Jugadores& jugador, int posicion) {
    cout << endl;
    cout << "[" << posicion + 1 << "] Estatura [M]" << endl;
    do {
        cout << "-> ";
        cin >> jugador.estatura;
    } while (jugador.validarEstatura());
}

void pedirPeso(Jugadores& jugador, int posicion) {
    cout << endl;
    cout << "[" << posicion + 1 << "] Peso [Kg]" << endl;
    do {
        cout << "-> ";
        cin >> jugador.peso;
    } while (jugador.validarPeso());
}

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

float coeficienteCorrelacion() {
    return ((variablesControl.covarianza)/(variablesControl.desviacionEstatura * variablesControl.desviacionPeso));
}


int main() {
    unsigned tiempoInicial, tiempoFinal;


    int cantidadJugadores;

    do {
        cout << "Ingrese la cantidad de jugadores: ";
        cin >> cantidadJugadores;
    } while (cantidadJugadores < 1);

    Jugadores jugadores[cantidadJugadores];

    for (int i = 0; i < cantidadJugadores; i++) {
        pedirEstatura(jugadores[i], i);
        pedirPeso(jugadores[i], i);
    }
    tiempoInicial = clock();
    
    float sumaTotalEstatura = 0.0;
    for (int i = 0; i < cantidadJugadores; i++)
        calcularPromedio(jugadores[i], sumaTotalEstatura, 1);

    variablesControl.promedioEstatura = sumaTotalEstatura / cantidadJugadores;

    float sumaTotalPeso = 0.0;
    for (int i = 0; i < cantidadJugadores; i++)
        calcularPromedio(jugadores[i], sumaTotalPeso, 0);

    variablesControl.promedioPeso = sumaTotalPeso / cantidadJugadores;

    for (int i = 0; i < cantidadJugadores; i++) 
        variablesControl.sumatoriaCovarianza += (jugadores[i].estatura - variablesControl.promedioEstatura) * (jugadores[i].peso - variablesControl.promedioPeso);

    variablesControl.covarianza = variablesControl.sumatoriaCovarianza / cantidadJugadores;


    for (int i = 0; i < cantidadJugadores; i++) {
        calcularDesviacion(jugadores[i], 1);
        calcularDesviacion(jugadores[i], 0);
    }

    variablesControl.desviacionEstatura = sqrt(variablesControl.sumatoriaCuadradosEstatura / cantidadJugadores);
    variablesControl.desviacionPeso = sqrt(variablesControl.sumatoriaCuadradosPeso / cantidadJugadores);

    cout << "Coeficiente de Correlacion: " << coeficienteCorrelacion() << endl;

    tiempoFinal = clock();
    double time = (double(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);

    cout << "Tiempo de Ejecucion [Calculos]: " << time << " (s)" << endl;

    return EXIT_SUCCESS;
}