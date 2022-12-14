#include <bits/stdc++.h>

int main(void) {
    std::string saludo = "Buenos dias";


    std::string *ptr = (&saludo);

    std::cout << "Direccion: " << ptr << std::endl;
    std::cout << "Contenido: " << *ptr << std::endl;

    *ptr = "Buenas noches";

    std::cout << "Direccion: " << ptr << std::endl;
    std::cout << "Contenido {Puntero}: " << *ptr << std::endl;
    std::cout << "Contenido {Variable}: " << saludo << std::endl;






    return EXIT_SUCCESS;
}