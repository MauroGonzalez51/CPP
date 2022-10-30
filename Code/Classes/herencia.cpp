#include <bits/stdc++.h>

class Persona {
    private:
        std::string nombre;
        int edad;

    public:
        Persona(std::string nombre, int edad) {
            this -> nombre = nombre;
            this -> edad = edad;
        };

        void mostrarPersona();
};

void Persona::mostrarPersona() {
    std::cout << "Nombre: " << this -> nombre << std::endl;
    std::cout << "Edad: " << this -> edad << std::endl;
}

// ----------------------------------------------------------------------------------

class Alumno : public Persona {
    private:
        std::string codigoAlumno;
        float notaFinal;
    
    public:
        Alumno(std::string nombre, int edad, std::string codigoAlumno, float notaFinal) : Persona (nombre, edad) {
            this -> codigoAlumno = codigoAlumno;
            this -> notaFinal = notaFinal;
        }

        void mostrarAlumno();
};

void Alumno::mostrarAlumno() {
    mostrarPersona();
    std::cout << "Codigo Alumno: " << this -> codigoAlumno << std::endl;
    std::cout << "Nota Final: " << this -> notaFinal << std::endl;
} 

int main(void) {
    Alumno* alumno = new Alumno("Mauro Alonso",  17, "T00067622", 3.9);

    alumno -> mostrarAlumno(); 

    delete alumno;

    return EXIT_SUCCESS;
}