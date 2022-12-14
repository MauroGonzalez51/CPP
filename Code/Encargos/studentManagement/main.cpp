// ------------------------------ ENCABEZADOS Y CONSTANTES DEL PROGRAMA --------------------------------------------|>
//-------------------------------------------------------------------------|>

#include <bits/stdc++.h>

const std::string folderPath = "studentManagement/files/";

const int cantidadEstudiantes = 1;

std::vector <std::string> asignaturasGeneral = {"Informatica", "Fisica", "Quimica"};

struct {
    std::string nombre;
    std::string clave;
    int cantidadIntentos = 3;
} datosProfesor;

struct {
    std::string nombre;
    std::string codigo;
    std::array <float, 3> notasFinales;
    std::vector <std::string> categoriaPorAsignatura;
} estudiantes[cantidadEstudiantes];

std::vector <std::string> nombreCategorias = {"Deficiente", "Insuficiente", "Regular", "Sobresaliente", "Excelente"};

// ------------------------------ FUNCIONES PARA INICIALIZAR Y ESCRIBIR EN EL LOG ----------------------------------|>
//-------------------------------------------------------------------------|>

std::ofstream logFile (folderPath + "logFile.txt", std::ios::app);

//-------------------------------------------------------------------------|>

void escribirLinea(const int cantidadCaracteres, const std::string c) {
    logFile << std::endl;
    for (int i = 0; i < cantidadCaracteres; i++)
        logFile << c;
    logFile << std::endl;
}

//-------------------------------------------------------------------------|>

const char* horaActual() {
    time_t now = time(0);
    const char* horaActual = ctime(&now);
    return horaActual;
}

//-------------------------------------------------------------------------|>

void escribirLog() {
    if (logFile.is_open()) {
        escribirLinea(80, "-");
        logFile << "Programa Iniciado: " << horaActual() << std::endl;
    }
}

//-------------------------------------------------------------------------|>

void escribirLog(const std::string mensaje) {
    if (logFile.is_open()) 
        logFile << "[INFO] " << mensaje << std::endl;
}

// ------------------------------ FUNCIONES PARA INICIALIZAR LOS USUARIOS - PROFESORES -----------------------------|>
//-------------------------------------------------------------------------|>

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

//-------------------------------------------------------------------------|>

bool crearUsuario(const std::string usuario, const std::string clave) {
    bool archivoCreado = false;
    if (usuarioExiste(usuario, clave)) escribirLog("El usuario " + usuario + " ya existe -> No se creara un nuevo archivo");
    else {
        std::ofstream archivo (folderPath + usuario + ".txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << usuario << std::endl;
            archivo << clave << std::endl;
            archivoCreado = true;
        }
    }
    return archivoCreado;
}

//-------------------------------------------------------------------------|>

void inicializarUsuarios() {
    std::vector <std::string> usuarios = {"luis", "jorge", "james", "johan", "kevin"};
    std::vector <std::string> claves = {"123", "456", "789", "abc", "efg"};

    for (int i = 0; i < 5; i++) {
        if (crearUsuario(usuarios.at(i), claves.at(i)))
            escribirLog("Usuario Creado: " +  usuarios.at(i));
    }
}

// ------------------------------ FUNCIONES AUXILIARES -------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void escribirLinea(const std::string c) {
    std::cout << std::endl;
    for (int i = 0; i < 40; i++)
        std::cout << c;
    std::cout << std::endl;
}

// ------------------------------ FUNCIONES DE VALIDACION - PROFESORES ---------------------------------------------|>
//-------------------------------------------------------------------------|>

bool validarUsuarioProfesor(const std::string usuario) {
    std::ifstream archivo (folderPath + usuario + ".txt");
    bool esValido = false;
    if (archivo.is_open()) {
        std::string auxUsuario;
        std::getline(archivo, auxUsuario);
        if (usuario == auxUsuario) esValido = true;
    }
    return esValido;
}

//-------------------------------------------------------------------------|>

bool validarClaveProfesor(const std::string usuario, const std::string clave) {
    std::ifstream archivo (folderPath + usuario + ".txt");
    bool esValido = false;
    if (archivo.is_open()) {
        std::string dummyItem, auxClave;
        std::getline(archivo, dummyItem);
        std::getline(archivo, auxClave);
        if (clave == auxClave) esValido = true;
    }
    return esValido;
}

// ------------------------------ DATOS PROFESOR -------------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void datosProfesorMain() {
    escribirLinea("/");
    std::cout << "[PROFESOR]" << std::endl;

    do {
        // ------------- NOMBRE USUARIO ------------------------------------|>
        do {
            std::cout << "Ingrese su usuario: ";
            std::cin >> datosProfesor.nombre;

            if (validarUsuarioProfesor(datosProfesor.nombre)) break;
            else datosProfesor.cantidadIntentos--;
        } while ((true) && (datosProfesor.cantidadIntentos > 0));
        if (datosProfesor.cantidadIntentos < 0) exit(EXIT_FAILURE);

        // ------------- CONTRASEÑA ----------------------------------------|>
        do {
            std::cout << "Ingrese su clave: ";
            std::cin >> datosProfesor.clave;

            if (validarClaveProfesor(datosProfesor.nombre, datosProfesor.clave)) break;
            else datosProfesor.cantidadIntentos--;
        } while ((true) && (datosProfesor.cantidadIntentos > 0));
        if (datosProfesor.cantidadIntentos < 0) exit(EXIT_FAILURE);
        break;
    } while (datosProfesor.cantidadIntentos > 0);
}

// ------------------------------ DATOS ESTUDIANTES ----------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void datosEstudiantes() {
    std::cout << "[ESTUDIANTES]" << std::endl;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        std::cout << std::endl;
        // ---------------- NOMBRE -------------------------|>
        do {
            std::cout << "[Estudiante " << i + 1 << "] Ingrese su nombre: ";
            std::cin >> estudiantes[i].nombre;
        } while (estudiantes[i].nombre.empty());

        // ---------------- CODIGO -------------------------|>
        do {
            std::cout << "[Estudiante " << i + 1 << "] Ingrese su codigo: ";
            std::cin >> estudiantes[i].codigo;
        } while (estudiantes[i].codigo.empty());

        // ---------------- NOTAS FINALES ------------------|>
        for (int asignatura = 0; asignatura < estudiantes[i].notasFinales.size(); asignatura++) {
            do {
                std::cout << "[Estudiante " << i + 1 << "] [Asignatura " << asignaturasGeneral.at(asignatura) << "] Ingrese su nota: ";
                std::cin >> estudiantes[i].notasFinales.at(asignatura);
            } while ((estudiantes[i].notasFinales.at(asignatura) < 0.0) || (estudiantes[i].notasFinales.at(asignatura) > 100.0));              
        }
    }
}

// ------------------------------ ANALISIS DE DATOS ----------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

void limpiarArchivosCategorias() {
    for (int i = 0; i < nombreCategorias.size(); i++) {
        std::filesystem::remove(folderPath + nombreCategorias.at(i));
    }
}

std::string categorizarEstudiante(const double notaFinal, const std::string asignatura, const std::string codigoEstudiante) {
    // if (notaFinal <= 30) categoriasEstudiantes.deficiente++;
    // else if (notaFinal <= 60) categoriasEstudiantes.insuficiente++;
    // else if (notaFinal <= 80) categoriasEstudiantes.regular++;
    // else if (notaFinal <= 90) categoriasEstudiantes.sobresaliente++; 
    // else categoriasEstudiantes.excelente++;

    std::string returnStatement;

    std::vector <int> puntosDeCorte = {30, 60, 80, 90, 100};

    for (int i = 0; i < puntosDeCorte.size(); i++) {
        if (notaFinal <= puntosDeCorte.at(i)) {
            std::ofstream archivoCategorias (folderPath + nombreCategorias.at(i), std::ios::app);
            returnStatement = nombreCategorias.at(i);
            if (archivoCategorias.is_open()) {
                archivoCategorias << std::endl;
                archivoCategorias << "Codigo Estudiante: " << codigoEstudiante << std::endl;
                archivoCategorias << "Asignatura: " << asignatura << std::endl;
                archivoCategorias << "Nota Final: " << notaFinal << std::endl;
                archivoCategorias << "-> " << nombreCategorias.at(i) << std::endl;
            }
            break;
        }
    }
    return returnStatement;
}

//-------------------------------------------------------------------------|>

void categoriasMain() {
    limpiarArchivosCategorias();
    for (int indiceEstudiante = 0; indiceEstudiante < cantidadEstudiantes; indiceEstudiante++) {
        for (int indiceAsignatura = 0; indiceAsignatura < estudiantes[indiceEstudiante].notasFinales.size(); indiceAsignatura++) {
            estudiantes[indiceEstudiante].categoriaPorAsignatura.push_back(categorizarEstudiante(
                estudiantes[indiceEstudiante].notasFinales.at(indiceAsignatura), 
                asignaturasGeneral.at(indiceAsignatura), 
                estudiantes[indiceEstudiante].codigo));
        }
    }
}

//-------------------------------------------------------------------------|>

void porcentajeAprobacion(const float notaMinimaAprobar) {

    // ------ % APROBACION GENERAL ------------------|>
    
    float cantidadAprobados = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        for (int asignatura = 0; asignatura < estudiantes[i].notasFinales.size(); asignatura++) {
            if (estudiantes[i].notasFinales.at(asignatura) >= notaMinimaAprobar) cantidadAprobados++;
        }
    }
    float totalNotas = estudiantes[0].notasFinales.size() * cantidadEstudiantes;
    escribirLog("Porcentaje Aprobacion {General}: " + std::to_string(((cantidadAprobados / totalNotas) * 100)) + "%");
    
    // ------ % APROBACION x ASIGNATURA -------------|>

    for (int indiceAsignatura = 0; indiceAsignatura < asignaturasGeneral.size(); indiceAsignatura++) {
        float cantidadAprobados = 0;
        for (int indiceEstudiante = 0; indiceEstudiante < cantidadEstudiantes; indiceEstudiante++) {
            if (estudiantes[indiceEstudiante].notasFinales.at(indiceAsignatura) >= notaMinimaAprobar) cantidadAprobados++;
        }
        escribirLog("Porcentaje Aprobacion {" + asignaturasGeneral.at(indiceAsignatura) + "}: " + std::to_string((cantidadAprobados / cantidadEstudiantes) * 100) + "%");
    }
}

//-------------------------------------------------------------------------|>

void estudianteMenorNota() {

    // ----- MENOR NOTA EN GENERAL ------------------|>

    float menorNota = 0.0, indiceEstudiante, indiceAsignatura;
    std::string codigoEstudiante;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        for (int asignatura = 0; asignatura < estudiantes[i].notasFinales.size(); asignatura++) {
            if (menorNota < estudiantes[i].notasFinales.at(asignatura)) {
                menorNota = estudiantes[i].notasFinales.at(i);
                indiceEstudiante = i;
                indiceAsignatura = asignatura;
                codigoEstudiante = estudiantes[i].codigo;
            }
        }
    }

    escribirLog("Nota Minima General: " + std::to_string(menorNota) + 
        " | Codigo Estudiante: " + codigoEstudiante + 
        " | Asingatura: " + asignaturasGeneral.at(indiceAsignatura));
    

    // ----- MENOR NOTA x ASIGNATURA ----------------|>

    for (int indiceAsignatura = 0; indiceAsignatura < asignaturasGeneral.size(); indiceAsignatura++) {
        float menorNota = 0.0;
        std::string codigoEstudiante;
        for (int indiceEstudiante = 0; indiceEstudiante < cantidadEstudiantes; indiceEstudiante++) {
            if (menorNota < estudiantes[indiceEstudiante].notasFinales.at(indiceAsignatura)) {
                menorNota = estudiantes[indiceEstudiante].notasFinales.at(indiceAsignatura);
                codigoEstudiante = estudiantes[indiceEstudiante].codigo;
            }
        }
        escribirLog("Nota Minima {" + asignaturasGeneral.at(indiceAsignatura) + "}: " + std::to_string(menorNota) + " | Codigo Estudiante: " + codigoEstudiante);
    }
}

//-------------------------------------------------------------------------|>

void analisisMain() {
    categoriasMain();
    porcentajeAprobacion(50.0);
    estudianteMenorNota();
}

// ------------------------------ FUNCION MAIN ---------------------------------------------------------------------|>
//-------------------------------------------------------------------------|>

int main(void) {
    escribirLog();
    inicializarUsuarios(); 
    datosProfesorMain();
    datosEstudiantes(); 
    analisisMain();
    return EXIT_SUCCESS;
}