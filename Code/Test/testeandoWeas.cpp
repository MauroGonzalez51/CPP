#include <bits/stdc++.h>
#include <clocale>

using namespace std;

class Students {
    public:
        string name;
        int genre, educationLevel, stratum, maritalStatus, salary;

        struct {
            int day, month, year;
            bool isLeapYear;
        } birthDate;

        bool validateName();
        bool validateGenre();
        bool validateEducationLevel();
        bool validateStratum();
        bool validateYear();
        bool validateMonth();
        bool validateDay();
        bool validateMaritalStatus();
        bool validateSalary();
};

bool Students::validateName() {
    bool isValid = true;
    if (this -> name.length() == 0) 
        isValid = false;
    
    char auxName[this -> name.length() + 1];
    strcpy(auxName, this -> name.c_str());

    int spaceCounter = 0;

    for (int i = 0; i < this -> name.length(); i++) {
        if (auxName[i] == ' ') {
            spaceCounter++;
        } 
    }

    if (spaceCounter == this -> name.length()) 
        isValid = false;

    for (int i = 0; i < this -> name.length(); i++) {
        if (isdigit(i)) {
            isValid = false;
        }
    }

    if (this -> name.length() > 50) 
        isValid = false;

    return !isValid;
}

bool Students::validateGenre() {
    bool isValid = true;

    array <int, 3> validEntries = {1, 2, 3};
    for (int i : validEntries) {
        (this -> genre == i) ? 
            isValid = true : isValid = false;
    }

    return !isValid;
}

bool Students::validateEducationLevel() {
    bool isValid = true;

    array <int, 4> validEntries = {1, 2, 3, 4};
    for (auto i : validEntries) {
        (this -> educationLevel == i) ?
            isValid = true : isValid = false;
    }

    return !isValid;
}

bool Students::validateStratum() {
    bool isValid = true;

    array <int, 6> validEntries = {1, 2, 3, 4, 5, 6};
    for (auto i : validEntries) {
        (this -> stratum == i) ?
            isValid = true : isValid = false;
    }

    return !isValid;
}

bool Students::validateYear() {
    bool isValid = true, checkNextCase = true;

    if (checkNextCase) {
        time_t currentTime;

        currentTime = time(NULL);
        int currentYear = 1970 + currentTime / 31537970;
        
        if (this -> birthDate.year > currentYear) {
            isValid = false;
            checkNextCase = false;
        }
    }

    if (checkNextCase) {
        if (this -> birthDate.year < 1) {
            isValid = false;
            checkNextCase = false;
        }
    }

    if (checkNextCase) {
        (this -> birthDate.year % 4 == 0) ? 
            this -> birthDate.isLeapYear = true : 
                this -> birthDate.isLeapYear = false;
    }

    return !isValid;
}

bool Students::validateMonth() {
    bool isValid = true;

    ((this -> birthDate.month >= 1) && (this -> birthDate.month <= 12)) ? isValid = true : isValid = false;

    return !isValid;
}

bool Students::validateDay() {
    bool isValid = true, checkNextCase = true;

    if (checkNextCase) {
        array <int, 7> validEntriesMonth = {1, 3, 5, 7, 8, 10, 12};
        for (auto i : validEntriesMonth) {
            if (this -> birthDate.month == i) {
                if ((this -> birthDate.day >= 1) && (this -> birthDate.day <= 31)) {
                    isValid = true;
                    checkNextCase = false;
                } else {
                    isValid = false;
                    checkNextCase = false;
                }
            }
        }
    }

    if (checkNextCase) {
        array <int, 4> validEntriesMonth = {4, 6, 9, 11};
        for (auto i : validEntriesMonth) {
            if (this -> birthDate.month == i) {
                if ((this -> birthDate.day >= 1) && (this -> birthDate.day <= 30)) {
                    isValid = true;
                    checkNextCase = false;
                } else {
                    isValid = false;
                    checkNextCase = false;
                }
            }
        }
    }

    if (checkNextCase) {
        if ((this -> birthDate.month == 2) && (this -> birthDate.isLeapYear == false)) {
            if ((this -> birthDate.day >= 1) && (this -> birthDate.day <= 28)) {
                isValid = true;
                checkNextCase = false;
            } else {
                isValid = false;
                checkNextCase = false;
            }
        }
    }

    if (checkNextCase) {
        if ((this -> birthDate.month == 2) && (this -> birthDate.isLeapYear)) {
            if ((this -> birthDate.day >= 1) && (this -> birthDate.day <= 29)) {
                isValid = true;
                checkNextCase = false;
            } else {
                isValid = false;
                checkNextCase = false;
            }
        }
    }

    return !isValid;
}

bool Students::validateMaritalStatus() {
    bool isValid = true;

    ((this -> maritalStatus >= 1) && (this -> maritalStatus <=5)) ? 
        isValid = true : isValid = false;

    return !isValid;
}

bool Students::validateSalary() {
    bool isValid = true;

    (this -> salary >= 1000000) ? isValid = true : isValid = false;

    return !isValid;
}

void setupName(Students& student);
void setupGenre(Students& student);
void setupEducationLevel(Students& student);
void setupStratum(Students& student);
void setupBirthDate(Students& student);
void setupMaritalStatus(Students& student);
void setupSalary(Students& student);

int main() {
    Students student;

    try {
        setupName(student);
        setupGenre(student);
        setupEducationLevel(student);
        setupBirthDate(student);
        setupMaritalStatus(student);
        setupSalary(student);

        cout << "Datos validados correctamente" << endl;
    } catch (...) {
        cout << endl;
        cout << "Error al momento de validar los datos ..." << endl;
    }

    return EXIT_SUCCESS;
}

void setupName(Students& student) {
    do {
        cout << "Ingrese su nombre: ";
        cin >> student.name;
    } while (student.validateName());
    cout << endl;
}

void setupGenre(Students& student) {
    cout << "Ingrese su Genero " << endl;

    array <string, 3> displayOptions = {"Masculino", "Femenino", "Otro ..."};
    for (int i = 0; i < displayOptions.size(); i++) 
        cout << "[" << i + 1 << "]: " << displayOptions[i] << endl;

    do {
        cout << "-> ";
        cin >> student.genre;
    } while (student.validateGenre());
    cout << endl;
}

void setupEducationLevel(Students& student) {
    cout << "Ingrese su nivel educativo" << endl; 

    array <string, 4> displayOptions = {"Sin Educacion", "Basica", "Universitaria", "Posgrado"};
    for (int i = 0; i < displayOptions.size(); i++) 
        cout << "[" << i + 1 << "]: " << displayOptions[i] << endl;

    do {
        cout << "-> ";
        cin >> student.educationLevel;
    } while (student.validateEducationLevel());
    cout << endl;
}

void setupStratum(Students& student) {
    cout << "Ingrese su estrato" << endl;

    array <string, 6> displayOptions = {"Bajo bajo", "Bajo", "Medio bajo", "Medio", "Medio alto", "Alto"};
    for (int i = 0; i < displayOptions.size(); i++) 
        cout << "[" << i + 1 << "]: " << displayOptions[i] << endl;
    
    do {
        cout << "-> ";
        cin >> student.stratum;
    } while (student.validateStratum());
    cout << endl;
}

void setupBirthDate(Students& student) {
    setlocale(LC_ALL, "es_ES.UTF-8");
    cout << "Ingrese su fecha de nacimiento" << endl;
    do {
        cout << "A\164o: ";
        cin >> student.birthDate.year;
    } while (student.validateYear());

    cout << endl;
    do {
        cout << "Mes: ";
        cin >> student.birthDate.month;
    } while (student.validateMonth());

    cout << endl;
    do {
        cout << "Dia: ";
        cin >> student.birthDate.day;
    } while (student.validateDay());
    cout << endl;
}

void setupMaritalStatus(Students& student) {
    cout << "Ingrese su estado civil" << endl;

    array <string, 5> displayOptions = {"Soltero", "Casado", "Separado", "Viudo", "Otro"};
    for (int i = 0; i < displayOptions.size(); i++) 
        cout << "[" << i + 1 << "]: " << displayOptions[i] << endl;

    do {
        cout << "-> ";
        cin >> student.maritalStatus;
    } while (student.validateMaritalStatus());
    cout << endl;
}

void setupSalary(Students& student) {
    cout << "Ingrese su salario" << endl;

    do {
        cout << "-> ";
        cin >> student.salary;
    } while (student.validateSalary());
    cout << endl;
}