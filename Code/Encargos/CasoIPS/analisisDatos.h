#include <bits/stdc++.h>

const std::string rutaArchivo = "CasoIPS/files/registroDatos.csv";

struct {
    std::set <std::string> codigoEmpresasRemitorasSET;

    std::vector <std::string> identificacionPacientes;
    std::vector <std::string> nombrePacientes;
    std::vector <std::string> codigoEmpresasRemitorasVECTOR;
    std::vector <float> tipoExamenes;
    std::vector <std::string> fechaExamenes;
    std::vector <float> edadesPacientes;
    std::vector <std::string> generoPacientes;
    std::vector <float> estaturaPacientes;
    std::vector <float> pesoPacientes;

    struct {
        std::vector <float> frecuenciaCardiaca;
        std::vector <float> presionSistolica;
        std::vector <float> presionDiastolica;
        std::vector <float> IMC;
        std::vector <std::string> factorRiesgo;
    } datosMedicos;
} allDatos;

void leerDatos() {
    std::ifstream datosPacientes (rutaArchivo);

    if (datosPacientes.is_open()) {
        std::string linea;
        char delimitador = ';';

        std::getline(datosPacientes, linea);
        while (std::getline(datosPacientes, linea)) {
            if (!linea.empty()) {
                std::stringstream streamLine (linea);
                std::array <std::string, 14> rawDatos;

                for (int i = 0; i < rawDatos.size(); i++)
                    std::getline(streamLine, rawDatos.at(i), delimitador);
                
                
                allDatos.identificacionPacientes.push_back(rawDatos.at(0));
                allDatos.nombrePacientes.push_back(rawDatos.at(1));
                allDatos.codigoEmpresasRemitorasVECTOR.push_back(rawDatos.at(2));
                allDatos.tipoExamenes.push_back(std::stof(rawDatos.at(3)));
                allDatos.fechaExamenes.push_back(rawDatos.at(4));
                allDatos.edadesPacientes.push_back(std::stof(rawDatos.at(5)));
                allDatos.generoPacientes.push_back(rawDatos.at(6));
                allDatos.estaturaPacientes.push_back(std::stof(rawDatos.at(7)));
                allDatos.pesoPacientes.push_back(std::stof(rawDatos.at(8)));
                allDatos.datosMedicos.frecuenciaCardiaca.push_back(std::stof(rawDatos.at(9)));
                allDatos.datosMedicos.presionSistolica.push_back(std::stof(rawDatos.at(10)));
                allDatos.datosMedicos.presionDiastolica.push_back(std::stof(rawDatos.at(11)));
                allDatos.datosMedicos.IMC.push_back(std::stof(rawDatos.at(12)));
                allDatos.datosMedicos.factorRiesgo.push_back(rawDatos.at(13));
            }
        }
    }
}

void setCodigosEmpresas() {
    for (auto &dato : allDatos.codigoEmpresasRemitorasVECTOR)
        allDatos.codigoEmpresasRemitorasSET.insert(dato);
}

struct {
    std::vector <int> cantidadPacientesEvaluados;
    std::vector <float> porcentajeHombresEvaluados;
    std::vector <float> porcentajeMujeresEvaluadas;
    std::vector <float> edadPromedioHombres;
    std::vector <float> edadPromedioMujeres;

    // ------ CANTIDAD ----------------------|>
    std::vector <int> pacientesRiesgoBAJO;
    std::vector <int> pacientesRiesgoMEDIO;
    std::vector <int> pacientesRiesgoALTO;
} datosPorEmpresa;

bool crearArchivoEmpresa(const std::string nombreEmpresa) {
    bool success = false;
    if (!std::filesystem::exists("CasoIPS/files/EMPRESA-" + nombreEmpresa + ".txt")) {
        std::ofstream archivoEmpresa ("CasoIPS/files/EMPRESA-" + nombreEmpresa + ".txt", std::ios::app);
        if (archivoEmpresa.good()) success = true;
        archivoEmpresa.close();
    }

    return success;
}


void analisisPorEmpresa() {
    for (auto &dato : allDatos.codigoEmpresasRemitorasSET) {

        int pacientesEvaluados = 0, pacientesRiesgoBajo = 0, pacientesRiesgoMedio = 0, pacientesRiesgoAlto = 0;
        float cantidadHombres = 0.0, cantidadMujeres = 0.0, edadHombres = 0.0, edadMujeres = 0.0;

        for (int i = 0; i < allDatos.identificacionPacientes.size(); i++) {
            if (allDatos.codigoEmpresasRemitorasVECTOR.at(i) == dato) {
                if (!crearArchivoEmpresa(dato)) {
                    pacientesEvaluados++;

                    if (allDatos.generoPacientes.at(i) == "M") {
                        cantidadHombres++;
                        edadHombres += allDatos.edadesPacientes.at(i);
                    }
                    
                    if (allDatos.generoPacientes.at(i) == "F") {
                        cantidadMujeres++;                
                        edadMujeres += allDatos.edadesPacientes.at(i);
                    }

                    if (allDatos.datosMedicos.factorRiesgo.at(i) == "RIESGO-BAJO") pacientesRiesgoBajo++;
                    if (allDatos.datosMedicos.factorRiesgo.at(i) == "RIESGO-MEDIO") pacientesRiesgoMedio++;
                    if (allDatos.datosMedicos.factorRiesgo.at(i) == "RIESGO-ALTO") pacientesRiesgoAlto++; 
                }
            }
        }

        datosPorEmpresa.cantidadPacientesEvaluados.push_back(pacientesEvaluados);

        if (pacientesEvaluados != 0) {
            datosPorEmpresa.porcentajeHombresEvaluados.push_back((cantidadHombres / pacientesEvaluados) * 100);
            datosPorEmpresa.porcentajeMujeresEvaluadas.push_back((cantidadMujeres / pacientesEvaluados) * 100);
        } else {
            datosPorEmpresa.porcentajeHombresEvaluados.push_back(0.0);
            datosPorEmpresa.porcentajeMujeresEvaluadas.push_back(0.0);
        }

        (cantidadHombres != 0) ?
            datosPorEmpresa.edadPromedioHombres.push_back((edadHombres / cantidadHombres)) :
                datosPorEmpresa.edadPromedioHombres.push_back(0.0);

        (cantidadMujeres != 0) ?
            datosPorEmpresa.edadPromedioMujeres.push_back((edadMujeres / cantidadMujeres)) :
                datosPorEmpresa.edadPromedioMujeres.push_back(0);

        datosPorEmpresa.pacientesRiesgoBAJO.push_back(pacientesRiesgoBajo);
        datosPorEmpresa.pacientesRiesgoMEDIO.push_back(pacientesRiesgoMedio);
        datosPorEmpresa.pacientesRiesgoALTO.push_back(pacientesRiesgoAlto);
    }
}

void escribirArchivo() {
    std::vector <std::string> localEmpresasVector;
    for (auto &dato : allDatos.codigoEmpresasRemitorasSET)
        localEmpresasVector.push_back(dato);

    for (int i = 0; i < localEmpresasVector.size(); i++) {
        std::ofstream archivoEmpresa ("CasoIPS/files/EMPRESA-" + localEmpresasVector.at(i) + ".txt", std::ios::app);

        if (archivoEmpresa.is_open()) {
            archivoEmpresa << std::endl << std::endl;
            archivoEmpresa << "Nombre EMPRESA: " << localEmpresasVector.at(i) << std::endl;
            archivoEmpresa << "Cantidad de Pacientes Evaluados: " << std::to_string(datosPorEmpresa.cantidadPacientesEvaluados.at(i)) << std::endl;
            archivoEmpresa << "Porcentaje de Hombres Evaluados: " << std::to_string(datosPorEmpresa.porcentajeHombresEvaluados.at(i)) << "%" << std::endl;
            archivoEmpresa << "Porcentaje de Mujeres Evaluadas: " << std::to_string(datosPorEmpresa.porcentajeMujeresEvaluadas.at(i)) << "%" << std::endl;
            archivoEmpresa << "Edad Promedio" << std::endl;
            archivoEmpresa << "Hombres: " << std::to_string(datosPorEmpresa.edadPromedioHombres.at(i)) << std::endl;
            archivoEmpresa << "Mujeres: " << std::to_string(datosPorEmpresa.edadPromedioMujeres.at(i)) << std::endl;
            archivoEmpresa << std::endl;

            archivoEmpresa << "Pacientes Riesgo BAJO: " << std::to_string(datosPorEmpresa.pacientesRiesgoBAJO.at(i)) << std::endl;
            archivoEmpresa << "Pacientes Riesgo MEDIO: " << std::to_string(datosPorEmpresa.pacientesRiesgoMEDIO.at(i)) << std::endl;
            archivoEmpresa << "Pacientes Riesgo ALTO: " << std::to_string(datosPorEmpresa.pacientesRiesgoALTO.at(i)) << std::endl; 
        }
    }
}

void analizarDatos() {
    leerDatos();
    setCodigosEmpresas();
    analisisPorEmpresa();
    escribirArchivo();
}