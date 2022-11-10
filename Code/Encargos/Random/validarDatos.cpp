#include <iostream>

// --------------------------------------------------------------------
struct {
    std::string nombre;
    int genero, nivelEducativo, estrato, estadoCivil;
    float salarioMensual;

    struct {
        int anio, mes, dia;
        bool esBisiesto;
    } fechaNacimiento;

} datos;

// --------------------------------------------------------------------
// Funciones para validar
bool validarNombre();
bool validarGenero();
bool validarNivelEducativo();
bool validarEstrato();
bool validarAnio();
bool validarMes();
bool validarDia();
bool validarEstadoCivil();
bool validarSalario(int salarioMinimo);

// --------------------------------------------------------------------
void pedirDatos() {
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su nombre: ";
        std::cout << std::endl << "-> ";
        std::cin >> datos.nombre;
    } while (!validarNombre());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su genero: " << std::endl;
        std::cout << "1. Masculino" << std::endl;
        std::cout << "2. Femenino" << std::endl;
        std::cout << std::endl << "-> ";
        std::cin >> datos.genero;
    } while (!validarGenero());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su nivel educativo: " << std::endl;
        std::cout << "1. Sin Educacion" << std::endl;
        std::cout << "2. Basica" << std::endl;
        std::cout << "3. Universitaria" << std::endl;
        std::cout << "4. Posgrado" << std::endl;
        std::cout << std::endl << "-> ";
        std::cin >> datos.nivelEducativo;
    } while (!validarNivelEducativo());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su estrato: " << std::endl;
        std::cout << "1. Bajo-Bajo" << std::endl;
        std::cout << "2. Bajo" << std::endl;
        std::cout << "3. Medio-Bajo" << std::endl;
        std::cout << "4. Medio" << std::endl;
        std::cout << "5. Medio-Alto" << std::endl;
        std::cout << "6. Alto" << std::endl;
        std::cout << std::endl << "-> ";
        std::cin >> datos.estrato;
    } while (!validarEstrato());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    std::cout << "Fecha Nacimiento: " << std::endl;
    do {
        std::cout << "Anio: " << std::endl;
        std::cout << "-> ";
        std::cin >> datos.fechaNacimiento.anio;
    } while (!validarAnio());

    do {
        std::cout << "Mes: " << std::endl;
        std::cout << "-> ";
        std::cin >> datos.fechaNacimiento.mes;
    } while (!validarMes());

    do {
        std::cout << "Dia: " << std::endl;
        std::cout << "-> ";
        std::cin >> datos.fechaNacimiento.dia;
    } while (!validarDia());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su estado civil: " << std::endl;
        std::cout << "1. Soltero" << std::endl;
        std::cout << "2. Casado" << std::endl;
        std::cout << "3. Separado" << std::endl;
        std::cout << "4. Viudo" << std::endl;
        std::cout << "5. Otro" << std::endl;
        std::cout << std::endl << "-> ";
        std::cin >> datos.estadoCivil;
    } while (!validarEstadoCivil());

    // ----------------------------------------------------------------
    std::cout << std::endl << std::endl;
    do {
        std::cout << "Ingrese su salario: " << std::endl;
        std::cout << "Minimo Mensual: 1000000" << std::endl;
        std::cout << std::endl << "-> ";
        std::cin >> datos.salarioMensual;
    } while (!validarSalario(1000000));

}

// --------------------------------------------------------------------
int main() {
    std::cout << "Programa para validar Datos" << std::endl;
    pedirDatos();


    return 0;
}

// --------------------------------------------------------------------
bool validarNombre() {
    bool esValido = false;

    if (datos.nombre.size() <= 50)
        esValido = true;
    
    int cantidadEspacios = 0;
    for (int i = 0; i < datos.nombre.size(); i++) {
        if (datos.nombre[i] == ' ')
            cantidadEspacios++;
    }

    if (cantidadEspacios != datos.nombre.size())
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarGenero() {
    bool esValido = false;
    if ((datos.genero == 1) || (datos.genero == 2))
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarNivelEducativo() {
    bool esValido = false;
    if ((datos.nivelEducativo == 1) || (datos.nivelEducativo == 2) || (datos.nivelEducativo == 3) || (datos.nivelEducativo == 4))
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarEstrato() {
    bool esValido = false;
    if ((datos.estrato >= 1) && (datos.estrato <= 6))
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarAnio() {
    bool esValido = false;
    if (datos.fechaNacimiento.anio >= 1)
        esValido = true;

    if ((datos.fechaNacimiento.anio % 4 == 0) && (datos.fechaNacimiento.anio % 100 != 0) || (datos.fechaNacimiento.anio % 400 == 0))
        datos.fechaNacimiento.esBisiesto = true;
    else
        datos.fechaNacimiento.esBisiesto = false;

    return esValido;
}

// --------------------------------------------------------------------
bool validarMes() {
    bool esValido = false;
    if ((datos.fechaNacimiento.mes >= 1) && (datos.fechaNacimiento.mes <= 12))
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarDia() {
    bool esValido = false;

    if ((datos.fechaNacimiento.mes == 1) || (datos.fechaNacimiento.mes == 3) || (datos.fechaNacimiento.mes == 5) || (datos.fechaNacimiento.mes == 7) || (datos.fechaNacimiento.mes == 8) || (datos.fechaNacimiento.mes == 10) || (datos.fechaNacimiento.mes == 12)) {
        if ((datos.fechaNacimiento.dia >= 1) && (datos.fechaNacimiento.dia <= 31))
            esValido = true;
    }

    if ((datos.fechaNacimiento.mes == 4) || (datos.fechaNacimiento.mes == 6) || (datos.fechaNacimiento.mes == 9) || (datos.fechaNacimiento.mes == 11)) {
        if ((datos.fechaNacimiento.dia >= 1) && (datos.fechaNacimiento.dia <= 30))
            esValido = true;
    }

    if ((datos.fechaNacimiento.mes == 2) && (datos.fechaNacimiento.esBisiesto == false)) {
        if ((datos.fechaNacimiento.dia >= 1) && (datos.fechaNacimiento.dia <= 28))
            esValido = true;
    }

    if ((datos.fechaNacimiento.mes == 2) && (datos.fechaNacimiento.esBisiesto == true)) {
        if ((datos.fechaNacimiento.dia >= 1) && (datos.fechaNacimiento.dia <= 29))
            esValido = true;
    }

    return esValido;
}

// --------------------------------------------------------------------
bool validarEstadoCivil() {
    bool esValido = false;
    if ((datos.estadoCivil >= 1) && (datos.estadoCivil <= 5))
        esValido = true;

    return esValido;
}

// --------------------------------------------------------------------
bool validarSalario(int salarioMinimo) {
    bool esValido = false;
    if (datos.salarioMensual >= salarioMinimo)
        esValido = true;

    return esValido;
}