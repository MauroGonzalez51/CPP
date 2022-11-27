// -------------------------- ENCABEZADOS Y CONSTANTES DEL PROGRAMA ---------------------------------------------------------------------------|
//------------------------------------------------------------------------------------------------|

#include <bits/stdc++.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 5;

struct {
    std::string nombre;
    std::string clave;
    std::string genero;
    std::string nombreAsignatura;
    int asignatura;
    double notaFinal;
} estudiantes[cantidadEstudiantes];

struct {
    int excelente = 0;
    int sobresaliente = 0;
    int regular = 0;
    int insuficiente = 0;
    int deficiente = 0;
} categoriasEstudiantes;

// -------------------------- FUNCIONES PARA INICIALIZAR Y ESCRIBIR EN EL LOG -----------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

std::ofstream logFile (folderPath +  "logFile.txt", std::ios::app);

// -----------------------------------------------------------------------------------------------| >

void escribirLinea(const int cantidadCaracteres, const std::string c) {
    logFile << std::endl;
    for (int i = 0; i < cantidadCaracteres; i++) 
        logFile << c;
    logFile << std::endl;
}

// -----------------------------------------------------------------------------------------------| >

const char* horaActual() {
    time_t now = time(0);
    const char* horaActual = ctime(&now);

    return horaActual;
}

// -----------------------------------------------------------------------------------------------| >

void escribirLog() {
    if (logFile.is_open()) {
        escribirLinea(80, "-");
        logFile << "Programa iniciado: " << horaActual() << std::endl;
    }
}

// -----------------------------------------------------------------------------------------------| >

void escribirLog(const std::string mensaje) {
    if (logFile.is_open())
        logFile << "[INFO] " << mensaje << std::endl;

}

// -------------------------- FUNCIONES PARA CREAR LAS INSTANCIAS DE LOS USUARIOS -------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

bool usuarioExiste(const std::string nombreUsuario, const std::string clave) {
    std::ifstream archivo (folderPath + nombreUsuario + ".txt");
    bool archivoExiste = false;
    if (archivo.is_open()) {
        std::string auxUsuario, auxClave;

        std::getline(archivo, auxUsuario);
        std::getline(archivo, auxClave);

        if ((nombreUsuario == auxUsuario) && (clave == auxClave)) archivoExiste = true;
    }

    return archivoExiste;
}

// -----------------------------------------------------------------------------------------------| >

bool crearUsuario(const std::string usuario, const std::string clave) {
    bool archivoCreado = false;

    if (usuarioExiste(usuario, clave))
        escribirLog("El usuario: " + usuario +  " ya existe -> no se creara un nuevo archivo");
    else {
        std::ofstream archivo (folderPath + usuario + ".txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << usuario << std::endl;
            archivo << clave << std::endl;
            archivoCreado = true;
        }
        archivo.close();
    } 


    return archivoCreado;
}

// -----------------------------------------------------------------------------------------------| >

void inicializarUsuarios() {
    std::vector <std::string> usuarios = {"luis", "jorge", "james", "johan", "kevin"};
    std::vector <std::string> claves = {"123", "456", "789", "abc", "efg"};

    for (int i = 0; i < 5; i++) {
        if (crearUsuario(usuarios.at(i), claves.at(i)))
            escribirLog("Usuario Creado: " +  usuarios.at(i));
    }
}

// -------------------------- FUNCIONES AUXILIARES PARA INGRESAR DATOS ------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++) 
        std::cout << c;
    std::cout << std::endl;
} 

// -------------------------- FUNCIONES DE VALIDACION -----------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------| >

bool validarNombre(const std::string usuario) {
    std::ifstream archivo (folderPath + usuario + ".txt");
    bool esValido = false;

    if (archivo.is_open()) {
        std::string auxUsuario;

        std::getline(archivo, auxUsuario);
        if (usuario == auxUsuario) esValido = true;
    }

    return esValido;
}

// ---------------------------------------------------------------------| >

bool validarGenero(const std::string c) {
    bool esValido = false;
    if ((c == "m") || (c == "f")) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------| >
bool validarAsignatura(const int asignatura, const int indice) {
    bool esValido = false;

    std::vector <int> opcionesValidas = {1, 2, 3};
    for (int &i : opcionesValidas) {
        if (asignatura == i) esValido = true;
    }
    
    if (esValido) {
        std::vector <std::string> asignaturas = {"Informatica", "Fisica", "Quimica"};
        estudiantes[indice].nombreAsignatura = asignaturas.at(asignatura - 1);
    }

    return esValido;
}

// ---------------------------------------------------------------------| >

bool validarNota(const double notaFinal) {
    bool esValido = false;
    if ((notaFinal >= 0.0) && (notaFinal <= 100.0)) esValido = true;
    return esValido;
}

// ---------------------------------------------------------------------| >

bool validarClave(const std::string usuario, const std::string clave) {
    bool esValido = false;
    std::ifstream archivo (folderPath + usuario + ".txt");

    if (archivo.is_open()) {
        std::string linea, auxClave;
        std::getline(archivo, linea);
        std::getline(archivo, auxClave);
        if (clave == auxClave) esValido = true;
    }

    return esValido;
}


// -------------------------- ALGORITMO PARA PEDIR DATOS --------------------------------------------------------------------------------------|
// ---------------------------------------------------------------------| >

void pedirDatos() {
    // std::cout << "Login de Usuario" << std::endl << std::endl;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        escribirLinea("*");
        int cantidadIntentos = 3;

        do {
            std::cout << "Estudiante [" << i + 1 << "]" << std::endl;

            // -------------------- NOMBRE --------------------------| >
            do {
                std::cout << "Ingrese su nombre: ";
                std::getline(std::cin, estudiantes[i].nombre, '\n');

                if (validarNombre(estudiantes[i].nombre)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- CLAVE ---------------------------| >
            do {
                std::cout << "Ingrese su clave: ";
                std::getline(std::cin, estudiantes[i].clave, '\n');

                if (validarClave(estudiantes[i].nombre, estudiantes[i].clave)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- GENERO --------------------------| >
            do {
                std::cout << "Ingrese su genero (m/f): ";
                std::cin >> estudiantes[i].genero;

                if (validarGenero(estudiantes[i].genero)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- ASIGNATURA ----------------------| >
            std::cout << "Ingrese la asignatura" << std::endl;
            std::cout << "1. Informatica" << std::endl;
            std::cout << "2. Fisica" << std::endl;
            std::cout << "3. Quimica" << std::endl;
            do {
                std::cout << "-> ";
                std::cin >> estudiantes[i].asignatura;

                if (validarAsignatura(estudiantes[i].asignatura, i)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));
            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            // -------------------- NOTA FINAL ----------------------| >
            do {
                std::cout << "Ingrese su Nota Final: ";
                std::cin >> estudiantes[i].notaFinal;

                if (validarNota(estudiantes[i].notaFinal)) break;
                else cantidadIntentos--;
            } while ((true) && (cantidadIntentos > 0));

            if (cantidadIntentos < 0) exit(EXIT_FAILURE);

            break;

        } while (cantidadIntentos > 0);
    }

}

// -------------------------- ANALIZAR DATOS --------------------------------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

void categorizarEstudiante(const double notaFinal) {
    if (notaFinal <= 30) categoriasEstudiantes.deficiente++;
    else if (notaFinal <= 60) categoriasEstudiantes.insuficiente++;
    else if (notaFinal <= 80) categoriasEstudiantes.regular++;
    else if (notaFinal <= 90) categoriasEstudiantes.sobresaliente++; 
    else categoriasEstudiantes.excelente++;
}

// -----------------------------------------------------------------------------------------------| >

double porcentajeAprobacion(const double notaMinimaAprobar) {
    int cantidadAprobados = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].notaFinal >= notaMinimaAprobar)
            cantidadAprobados++; 
    }
    escribirLog("Porcentaje de Aprobacion: " + std::to_string((double) ((cantidadAprobados / cantidadEstudiantes) * 100)) + "%");
    return (double) ((cantidadAprobados / cantidadEstudiantes) * 100);
}

// -----------------------------------------------------------------------------------------------| >

double porcentajeExcelente() {
    escribirLog("Porcentaje Excelente: " + std::to_string((double) ((categoriasEstudiantes.excelente / cantidadEstudiantes) * 100)) + "%");
    return (double) ((categoriasEstudiantes.excelente / cantidadEstudiantes) * 100);
}

// -----------------------------------------------------------------------------------------------| >

std::string asignaturaMasAprobados(const double notaMinimaAprobar) {
    std::string asignaturaAprobados;
    std::vector <std::string> asignaturas = {"Informatica", "Fisica", "Quimica"};
    
    // int mayorCantidadAprobados = 0;
    // for (int i = 0; i < asignaturas.size(); i++) {
    //     int cantidadAprobados = 0;
    //     if (estudiantes[i].asignatura == (i + 1)) {
    //         if (estudiantes[i].notaFinal >= notaMinimaAprobar)
    //             cantidadAprobados++;
    //     }

    //     if (cantidadAprobados > mayorCantidadAprobados) {
    //         mayorCantidadAprobados = cantidadAprobados;
    //         asignaturaAprobados = asignaturas.at(i);
    //     }
    // }

    int mayorCantidadAprobados = 0;
    for (int asignatura = 0; asignatura < asignaturas.size(); asignatura++) {
        int cantidadAprobados = 0;
        for (int estudiante = 0; estudiante < cantidadEstudiantes; estudiante++) {
            if (estudiantes[estudiante].asignatura == asignatura) {
                if (estudiantes[estudiante].notaFinal >= notaMinimaAprobar) 
                    cantidadAprobados++;
            }
        }
        if (cantidadAprobados > mayorCantidadAprobados) {
            mayorCantidadAprobados = cantidadAprobados;
            asignaturaAprobados = asignaturas.at(asignatura - 1);
        }
    }

    escribirLog("Asignatura mas aprobados: " + asignaturaAprobados);

    return asignaturaAprobados;
}

// -----------------------------------------------------------------------------------------------| >

int estudianteMenorNota(const int asignaturaBuscar) {
    int indiceEstudianteMenorNota;
    std::vector <std::string> asignaturas = {"Informatica", "Fisica", "Quimica"};

    double menorNota = 101.0;
    for (int estudiante = 0; estudiante < cantidadEstudiantes; estudiante++) {
        if (estudiantes[estudiante].asignatura == asignaturaBuscar) {
            if (estudiantes[estudiante].notaFinal < menorNota) {
                menorNota = estudiantes[estudiante].notaFinal;
                indiceEstudianteMenorNota = estudiante;
            }
        }
    }

    escribirLog("Estudiante con la menor nota: " + estudiantes[indiceEstudianteMenorNota].nombre);

    return indiceEstudianteMenorNota;
}

// -----------------------------------------------------------------------------------------------| >

void analizarDatos() {
    for (int i = 0; i < cantidadEstudiantes; i++) 
        categorizarEstudiante(estudiantes[i].notaFinal);
    
    escribirLog("Cantidad de Estudiantes en EXCELENTE: " +  std::to_string(categoriasEstudiantes.excelente));
    escribirLog("Cantidad de Estudiantes en SOBRESALIENTE: " +  std::to_string(categoriasEstudiantes.sobresaliente));
    escribirLog("Cantidad de Estudiantes en REGULAR: " +  std::to_string(categoriasEstudiantes.regular));
    escribirLog("Cantidad de Estudiantes en INSUFICIENTE: " +  std::to_string(categoriasEstudiantes.insuficiente));
    escribirLog("Cantidad de Estudiantes en DEFICIENTE: " +  std::to_string(categoriasEstudiantes.deficiente));

    escribirLinea("-");
    std::cout << "Analisis de datos" << std::endl;
    // ------------- No se cual es la menor nota para aprobar asi que hay que pasarsela a la funcion como parametro -------| > 
    std::cout << "Porcentaje de Aprobacion: " << porcentajeAprobacion(50.0) << std::endl;
    std::cout << "Porcentaje de Excelentes: " << porcentajeExcelente() << std::endl;
    std::cout << "Asignatura con mas estudiantes aprobados: " << asignaturaMasAprobados(50.0) << std::endl; 
    // ------------- Aqui igual, la funcion funciona para cualquier asignatura, solo hay que pasarle el indice de esta ----| >
    std::cout << "Estudiante con la menor nota en Informatica: " << estudiantes[estudianteMenorNota(1)].nombre << std::endl;
}

// -------------------------- FUNCION MAIN ----------------------------------------------------------------------------------------------------|
// -----------------------------------------------------------------------------------------------| >

int main(void) {
    escribirLog();
    inicializarUsuarios();
    pedirDatos();
    analizarDatos();
    return EXIT_SUCCESS;
}