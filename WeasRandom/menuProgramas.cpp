/*
*   @descripcion: Menu con 6 Programas a elegir
*   @grupo:
*       - Mauro Alonso Gonzalez Figueroa    T00067622
*       - Maria Isabel Barrios Verbel       T00068465
*       - Juan Jose Jimenez Guardo          T00068278
*
*/

#include <bits/stdc++.h>

using namespace std;

// Funciones de control + ayudantes
const float PI = 3.141592654;

int mainMenu();

void lunchBlock(int opcion);

bool salir(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    string options[] = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < 20; i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0){
                Flag = false;
            }
        }
    }
    return Flag;
}

bool verificarTriangulo(float lado1, float lado2, float lado3) {
    return (((lado1 + lado2) > lado3) ? true : false);
}

float encontrarHipotenusa(float lado1, float lado2, float lado3) {
    float mayorLado = 0.0;
    if (lado1 > mayorLado)
        mayorLado = lado1;
    if (lado2 > mayorLado) 
        mayorLado = lado2;
    if (lado3 > mayorLado)
        mayorLado = lado3;
    
    return mayorLado;
}

// Funciones para lanzar los programas

void volumenSilos();
void verificarNumeroPrimo();
void ladosTriangulos();
void examenPersonas();
void calcularKwh();
void tablaMult();

int main() {
    do {
        lunchBlock(mainMenu());
        char msgSalida[3];
        cout << "Salir?" << endl;
        cout << "-> ";
        cin >> msgSalida;
        
        if (salir(msgSalida))
            break;
    } while (true);
    return 0;
}


int mainMenu() {
    int opcion;
    
    cout << endl;
    cout << "Menú Principal" << endl;
    cout << "Caso 1: Construccion de Silos" << endl;
    cout << "Caso 2: Verificar si un numero es Primo" << endl;
    cout << "Caso 3: Verificar Hipotenusa" << endl;
    cout << "Caso 4: Examen 50 Preguntas" << endl;
    cout << "Caso 5: Energia electrica consumida" << endl;
    cout << "Caso 6: Tabla de multiplicar de un numero" << endl;
    cout << "Programa a lanzar: ";
    cin >> opcion;
    
    return opcion;
}

void lunchBlock(int opcion) {
    switch (opcion) {
        case 1: 
            volumenSilos();
            break;
        case 2: 
            verificarNumeroPrimo();
            break;
        case 3: 
            ladosTriangulos();
            break;
        case 4: 
            examenPersonas();
            break;
        case 5:
            calcularKwh();
            break;
        case 6: 
            tablaMult();
            break;
        default: 
            cout << endl;
            cout << "Opcion no encontrada" << endl;
        
    }
}

void volumenSilos() {
    
    cout << endl;
    cout << "Caso 1: Volumen de un Silo" << endl;
    
    float diametroCilindro, alturaCilindro, alturaCono; 
    do {
        cout << "Ingrese el Diametro del Cilindro [M]: ";
        cin >> diametroCilindro;
    } while (diametroCilindro < 0);
    
    do {
        cout << "Ingrese la Altura del Cilindro [M]: ";
        cin >> alturaCilindro;
    } while (alturaCilindro < 0);
    
    do {
        cout << "Ingrese la Altura del Cono: ";
        cin >> alturaCono;
    } while (alturaCono < 1);
    
    float volumenTotal = (PI * pow((diametroCilindro / 2), 2) * alturaCilindro) + ((1/3) * alturaCono * PI * pow((diametroCilindro / 2), 2));
    cout << "Volumen total del Silo: " << volumenTotal << endl;
}

void verificarNumeroPrimo() {
    
    cout << endl;
    cout << "Caso 2: Verificar si un numero es primo" << endl;
    int numero, cantidadDivisores = 0;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    for (int i = 1; i <= numero; i++) {
        if ((numero % i) == 0) {
            cantidadDivisores++;
        }
    }
    
    if (cantidadDivisores > 2) {
        cout << "El numero " << numero << " No es primo" << endl;
    } else {
        cout << "El numero " << numero << " es primo" << endl;
    }
}

void ladosTriangulos() {
    
    cout << endl;
    cout << "Caso 3: Verificar Hipotenusa de N cantidad de triangulos" << endl;
    
    do {
        float lado1, lado2, lado3;
        do {
            cout << "Ingree el valor del cateto1: ";
            cin >> lado1;
        } while (lado1 < 1);
        
        do {
            cout << "Ingrese el valor del cateto2: ";
            cin >> lado2;
        } while (lado2 < 1);
        
        do {
            cout << "Ingrese el valor del cateto3: ";
            cin >> lado3;
        } while (lado3 < 1);
        
        if (verificarTriangulo(lado1, lado2, lado3)) {
            cout << endl;
            cout << "Los datos pueden formar un triangulo" << endl;
            cout << "Valor de la Hipotenusa: " << encontrarHipotenusa(lado1, lado2, lado3) << endl;
        } else {
            cout << "Los datos no pueden formar un triangulo" << endl;
        }
        
        cout << endl;
        char nuevoRegistro[3];
        cout << "Nuevo registro?" << endl;
        cout << "-> ";
        cin >> nuevoRegistro;
        
        if (!salir(nuevoRegistro))
            break;
            
    } while (true);
}

void examenPersonas() {
    
    cout << endl;
    cout << "Caso 4: Examen a N Personas" << endl;
    
    int cantidadPersonas = 0, sumaPuntuaciones = 0;
    do {
        cantidadPersonas++;
        int cantidadAcertadas, cantidadErradas, cantidadBlanco;
        
        do {
            cout << "Ingrese la cantidad de preguntas Acertadas [Registro" << cantidadPersonas << "]: ";
            cin >> cantidadAcertadas;
        } while (cantidadAcertadas < 1);
        
        do {
            cout << "Ingrese la cantidad de preguntas Erradas [Registro" << cantidadPersonas << "]: ";
            cin >> cantidadErradas;
        } while (cantidadErradas < 1);
        
        do {
            cout << "Ingrese la cantidad de Preguntas en Blanco [Registro" << cantidadPersonas << "]: ";
            cin >> cantidadBlanco;
        } while (cantidadBlanco < 1);
        
        int puntajeTotal = (cantidadAcertadas * 4) - (cantidadErradas * 2) - (cantidadBlanco * 1);
        sumaPuntuaciones += puntajeTotal;
        string msgSalida;
        
        if (puntajeTotal > 140)
            msgSalida = "Puntaje [Sobresaliente]";
        else if ((puntajeTotal >= 80) && (puntajeTotal < 140))
            msgSalida = "Puntaje [Aprobado]";
        else if (puntajeTotal < 80)
            msgSalida = "Puntaje [Reprobado]";
        
        cout << msgSalida << " | Puntuacion: " << puntajeTotal << endl;
        
        cout << endl;
        char nuevoRegistro[3];
        cout << "Nuevo registro?" << endl;
        cout << "-> ";
        cin >> nuevoRegistro;
        
        if (!salir(nuevoRegistro))
            break;
        
    } while (true);
    cout << "Promedio General de las " << cantidadPersonas << " = " << sumaPuntuaciones / cantidadPersonas << endl;
}

void calcularKwh() {
    
    cout << endl;
    float tarifaComercial, tarifaResidencial
    long int contadorComercial = 0, contadorResidencial = 0;
    int tipoUso, cantidadElec;
    cout << "Caso 5: Calcular Kwh" << endl;
    
    cout << "Valor de la Tarifa Comercial: ";
    cin >> tarifaComercial;
    
    cout << "Valor de la Tarifa Residencial: ";
    cin >> tarifaResidencial;
    
    cout << "Tipo de uso" << endl;
    cout << "[1] Residencial" << endl;
    cout << "[2] Comercial" << endl;
    cout << "-> ";
    cin >> tipoUso;
    
    cout << "Cantidad de Electrodomesticos que usan energia: ";
    cin >> cantidadElec;
    
    for (int i = 0; i < cantidadElec; i++) {
        int consumoEnergia, cantidadHoras;
        do {
            cout << endl;
            cout << "Consumo de energia del electrodomestico " << i + 1 << " (Watts): ";
            cin >> consumoEnergia;
        } while (consumoEnergia < 1);
        
        do {
            cout << endl;
            cout << "Tiempo que el electrodomestico estubo en uso (Horas): ";
            cin >> cantidadHoras;
        } while (cantidadHoras < 1);
        
        contadorComercial += (consumoEnergia * cantidadHoras * tarifaComercial);
        contadorResidencial += (consumoEnergia * cantidadHoras * tarifaResidencial);
    }
    
    switch(tipoUso) {
        case 1: {
            cout << endl;
            cout << "Tarifa Residencial" << endl;
            cout << "Valor total a pagar: " << contadorResidencial << endl;
            break;
        }
        case 2: {
            cout << endl;
            cout << "Tarifa Comercial" << endl;
            cout << "Valor total a pagar: " << contadorComercial << endl;
            break;
        }
        default: {
            cout << "Opcion no valida [...]" << endl;
            cout << "Debe ingresar un tipo de instalacion correcto" << endl;
        }
    }
    
}

void tablaMult() {
    
    float numero;
    cout << endl;
    cout << "Caso 6: Tabla de multiplicar de un Numero" << endl;
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    for (int i = 1; i <= 10; i++) {
        cout << numero << " * " << i << " = " << numero * i << endl;
    }
}