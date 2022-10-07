#include <bits/stdc++.h>

class Fracciones {
    public:
        std::vector <int> divisoresComunes;
    
        int numerador, denominador;

        void setDivisores() {
            int mayorNumero = (this -> numerador > this -> denominador) ? 
                this -> numerador : this -> denominador;
            
            for (int i = 1; i < mayorNumero + 1; i++) {
                if ((this -> numerador % i == 0) && (this -> denominador % i == 0))
                    this -> divisoresComunes.push_back(i);
            }
        }

        void simplificarNumeros() {
            while (this -> divisoresComunes.size() > 0) {
                this -> numerador /= divisoresComunes.back();
                this -> denominador /= divisoresComunes.back();
            }
        }
};

int main() {
    Fracciones *fraccion = new Fracciones();

    std::cout << "-> ";
    std::cin >> fraccion -> numerador;

    std::cout << std::endl;

    std::cout << "-> ";
    std::cin >> fraccion -> denominador;

    fraccion -> setDivisores();
    fraccion -> simplificarNumeros();

    std::cout << std::endl;
    std::cout << "Resultados" << std::endl;
    std::cout << "Numerador: " << fraccion -> numerador << std::endl;

    if (fraccion -> denominador != 1)
        std::cout << "Denominador: " << fraccion -> denominador << std::endl;

    return EXIT_SUCCESS;
}