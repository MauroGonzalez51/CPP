#include <bits/stdc++.h>
#include <conio.h>

const float PI = 3.141592654;

class Circulo {
    public:
        float radio;
        int operacion;

        float calcArea() {
            return (PI * pow(this -> radio, 2));
        }

        float calcPerimetro() {
            return (2 * PI * this -> radio);
        }

        bool validateOperacion() {
            bool isValid = false;

            std::array <int, 2> validEntries = {1, 2};
            for (int i : validEntries) {
                if (this -> operacion == i) 
                    isValid = true;
            }

            return isValid;
        }
};

class Elipse {
    public:
        struct {
            float semiEjeUno, semiEjeDos;
        } semiEjes;

        int operacion;

        float calcArea() {
            return (PI * this -> semiEjes.semiEjeUno * this -> semiEjes.semiEjeDos);
        }

        float calcPerimetro() {
            return (PI * ((3 * (this -> semiEjes.semiEjeUno +  this -> semiEjes.semiEjeDos)) - (sqrt(((3 * this -> semiEjes.semiEjeUno) + this -> semiEjes.semiEjeDos) * (this -> semiEjes.semiEjeUno + (3 * this -> semiEjes.semiEjeDos))))));
        }

        bool validateOperacion() {
            bool isValid = false;

            std::array <int, 2> validEntries = {1, 2};
            for (int i : validEntries) {
                if (this -> operacion == i) 
                    isValid = true;
            }

            return isValid;
        }
};

class Cardioide {
    public:
        float radio;
        int operacion;

        float calcArea() {
            return (6 * PI * pow(this -> radio, 2));
        }

        float calcPerimetro() {
            return (16 * this -> radio);
        }

        bool validateOperacion() {
            bool isValid = false;

            std::array <int, 2> validEntries = {1, 2};
            for (int i : validEntries) {
                if (this -> operacion == i) 
                    isValid = true;
            }

            return isValid;
        }

};

void operacionesCirculo() {
    Circulo* circulo = new Circulo();

    std::cout << std::endl;
    std::cout << "[1]. Area" << std::endl;
    std::cout << "[2]. Perimetro" << std::endl; 

    do {
        std::cout << "-> ";
        std::cin >> circulo -> operacion;
    } while (!circulo -> validateOperacion());

    std::cout << std::endl;

    do {
        std::cout << "Ingrese el radio del circulo: ";
        std::cin >> circulo -> radio;
    } while (circulo -> radio < 1);

    switch (circulo -> operacion) {
        case 1: {
            std:: cout << "Area: " << circulo -> calcArea() << std::endl;
            break;
        }

        case 2: {
            std::cout << "Perimetro: " << circulo -> calcPerimetro() << std::endl;
            break;
        }
    }

    delete circulo;
}

void operacionesElipse() {
    Elipse* elipse = new Elipse();

    std::cout << std::endl;
    std::cout << "[1]. Area" << std::endl;
    std::cout << "[2]. Perimetro" << std::endl;

    do {
        std::cout << "-> ";
        std::cin >> elipse -> operacion;
    } while (!elipse -> validateOperacion());

    std::cout << std::endl;
    do {
        std::cout << "Ingrese el SemiEje 1 de la Elipse: ";
        std::cin >> elipse -> semiEjes.semiEjeUno;
    } while (elipse -> semiEjes.semiEjeUno < 1);

    do {
        std::cout << "Ingrese el SemiEje 2 de la Elipse: ";
        std::cin >> elipse -> semiEjes.semiEjeDos;
    } while (elipse -> semiEjes.semiEjeDos < 1);

    std::cout << std::endl;
    switch (elipse -> operacion) {
        case 1: {
            std::cout << "Area: " << elipse -> calcArea() << std::endl;
            break;
        }

        case 2: {
            std::cout << "Perimetro: " << elipse -> calcPerimetro() << std::endl;
            break;
        }
    }

    delete elipse;
}

void operacionesCardioide() {
    Cardioide* cardioide = new Cardioide();

    std::cout << std::endl;
    std::cout << "[1]. Area" << std::endl;
    std::cout << "[2]. Perimetro" << std::endl;
    
    do {
        std::cout << "-> ";
        std::cin >> cardioide -> operacion;
    } while (!cardioide -> validateOperacion());

    std::cout << std::endl;

    do {
        std::cout << "Ingrese el Radio del Cardioide: ";
        std::cin >> cardioide -> radio;
    } while (cardioide -> radio < 1);

    std::cout << std::endl;
    switch (cardioide -> operacion) {
        case 1: {
            std::cout << "Area: " << cardioide -> calcArea() << std::endl;
            break;
        }

        case 2: {
            std::cout << "Perimetro: " << cardioide -> calcPerimetro() << std::endl;
            break;
        }
    }

    delete cardioide;
}


void callFunction(int opcion) {
    switch (opcion) {
        case 1: {
            operacionesCirculo();
            break;
        }

        case 2: {
            operacionesElipse();
            break;
        }

        case 3: {
            operacionesCardioide();
            break;
        }
        
        default:
            std::cout << "[...]" << std:: endl;
    }
}

void mainMenu() {
    int opcion;
    std::cout << std::endl;
    std::cout << "Calcular Perimetro/Area de las siguientes figuras" << std::endl;
    std::cout << "[1]. Circulo" << std::endl;
    std::cout << "[2]. Elipse" << std::endl;
    std::cout << "[3]. Cardioide" << std::endl;
    std::cout << "[4]. Salir" << std::endl;

    do {
        std::cout << "-> ";
        std::cin >> opcion;

        if (opcion == 4) 
            exit(EXIT_SUCCESS);
        else {
            bool isValid = false;
            std::array <int, 3> validEntries = {1, 2, 3};

            for (int i : validEntries) {
                if (opcion == i)
                    isValid = true;
            }

            if (isValid)
                break;
        }
    } while (true);

    callFunction(opcion);
}

int main() {
    mainMenu();
    std::cout << std::endl << "Presione cualquier tecla para salir" << std::endl;
    getch();
    return EXIT_SUCCESS;
}