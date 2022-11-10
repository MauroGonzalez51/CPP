//**    Grupo:
//**        - María Paula Velasco Aldana - T00068782 - Ingeniería Industrial
//**        - Ronald Esteban Angarita Arrieta - T00069375 - Ingeniería Industrial
//**        - Camilo Andrés Vasquez Yepes - T00068241 - Ingeniería quimica
//**    
//**    Descripcion:
//**        - Programa para clasificar estudiantes dependiendo del promedio de cada uno
//**

#include <bits/stdc++.h>

using namespace std;

// Constante con ruta de la carpeta en la que andan todos los archivos
const string rutaCarpeta = "Taller/archivos/";

// structura con vectores en las que se guardan todas las notas de los estudiantes
struct {
    vector <float> nota1;
    vector <float> nota2;
    vector <float> nota3;
    vector <float> notaFinal;
} notas;

// funcion que lee todas las notas guardadas en el archivo notas.csv y las guarda en el struct
void leerNotas() {
    ifstream notasEstudiantes (rutaCarpeta + "notas.csv");

    if (notasEstudiantes.is_open()) {
        char delimitador = ';';
        string linea;
        
        getline(notasEstudiantes, linea);

        while (getline(notasEstudiantes, linea)) {
            stringstream streamLine (linea);

            string note1, note2, note3, notafinal;

            getline(streamLine, note1, delimitador);
            getline(streamLine, note2, delimitador);
            getline(streamLine, note3, delimitador);
            getline(streamLine, notafinal, delimitador);

            notas.nota1.push_back(stof(note1));
            notas.nota2.push_back(stof(note2));
            notas.nota3.push_back(stof(note3));
            
            notas.notaFinal.push_back((stof(note1) * 0.33) + (stof(note2) * 0.33) + (stof(note3) * 0.33));
        }
    }

    notasEstudiantes.close();
}

// funcion para determinar los estudiantes que sacaron mas de 3.0 y guardarlos en un nuevo archivo
void archivoGanadores() {
    ofstream ganadores (rutaCarpeta + "ganadores.csv", ios::app);
    for (int i = 0; i < notas.notaFinal.size(); i++) {
        if (notas.notaFinal.at(i) >= 3.0) {
            ganadores << notas.nota1.at(i) << ";" << notas.nota2.at(i) << ";" << notas.nota3.at(i) << ";" << notas.notaFinal.at(i) << endl;
        }
    }
    ganadores.close();
}

// funcion para determinar los estudiants que sacaron menos de 3.0 y guardarlos en un archivo
void archivoPerdedores() {
    ofstream perdedores (rutaCarpeta + "perdedores.csv", ios::app);
    for (int i = 0; i < notas.notaFinal.size(); i++) {
        if (notas.notaFinal.at(i) < 3.0) {
            perdedores << notas.nota1.at(i) << ";" << notas.nota2.at(i) << ";" << notas.nota3.at(i) << ";" << notas.notaFinal.at(i) << endl;
        }
    }
    perdedores.close();
}

// funcion para determinar cual es la mayor nota, haciendo uso de un ciclo
void mayorDefinitiva() {
    double mayorNota = 0;
    int indice;
    for (int i = 0; i < notas.notaFinal.size(); i++) {
        if (notas.notaFinal.at(i) > mayorNota) {
            mayorNota = notas.notaFinal.at(i);
            indice = i;
        }
    }

    ofstream mayor (rutaCarpeta + "mejor.csv", ios::app);
    mayor << notas.nota1.at(indice) << ";" << notas.nota2.at(indice) << ";" << notas.nota3.at(indice) << ";" << notas.notaFinal.at(indice) << endl;
    mayor.close();
}

// funcion para determinar la menor nota, haciendo uso de un ciclo
void menorDefinitiva() {
    double menorNota = 10.0;
    int indice = 0;
    for (int i = 0; i < notas.notaFinal.size(); i++) {
        if (notas.notaFinal.at(i) < menorNota) {
            menorNota = notas.notaFinal.at(i);
            indice = i;
        }
    }

    ofstream menor (rutaCarpeta + "peor.csv", ios::app);
    menor << notas.nota1.at(indice) << ";" << notas.nota2.at(indice) << ";" << notas.nota3.at(indice) << ";" << notas.notaFinal.at(indice) << endl; 
    menor.close();
}

// funcion que determina que estudiantes sacaron mas de 4.0 y los guarda en un nuevo archivo
void superiorDefinitiva() {
    ofstream mayorDefinitiva (rutaCarpeta + "superior.csv", ios::app);
    for (int i = 0; i < notas.notaFinal.size(); i++) {
        if (notas.notaFinal.at(i) >= 4.0) {
            mayorDefinitiva << notas.nota1.at(i) << ";" << notas.nota2.at(i) << ";" << notas.nota3.at(i) << ";" << notas.notaFinal.at(i) << endl;
        }
    }
    mayorDefinitiva.close();
}

// funcion main que gestiona los llamados de las otras funciones
int main(void) {
    leerNotas();

    archivoGanadores();
    archivoPerdedores(); 
    mayorDefinitiva();
    menorDefinitiva();
    superiorDefinitiva();

    return EXIT_SUCCESS;
}