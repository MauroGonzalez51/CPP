#include <bits/stdc++.h>

std::ofstream registroDatos ("CasoIPS/files/registroDatos.csv", std::ios::app);

void tabularDatos(Paciente &paciente) {
    if (registroDatos.is_open()) {
        registroDatos << paciente.numeroIdentificacion << ";"
            << paciente.nombrePaciente << ";"
            << paciente.codigoEmpresa << ";"
            << std::to_string(paciente.tipoExamen) << ";"
            << paciente.fechaExamen << ";"
            << std::to_string(paciente.edad) << ";"
            << paciente.stringGenero << ";"
            << std::to_string(paciente.estatura) << ";"
            << std::to_string(paciente.peso) << ";"
            << std::to_string(paciente.datosMedicos.frecuenciaCardiaca) << ";"
            << std::to_string(paciente.datosMedicos.presionSistolica) << ";"
            << std::to_string(paciente.datosMedicos.precionDiastolica) << ";"
            << std::to_string(paciente.datosMedicos.IMC) << ";"
            << paciente.datosMedicos.factorDeRiesgo << std::endl;

    }
}