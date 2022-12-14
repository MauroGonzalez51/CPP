#include <bits/stdc++.h>

typedef std::vector <int> vectorInt;

int main(void) {
    vectorInt numeros = {1, 2, 3, 4, 5};
    
    // * ITERAR UN VECTOR CON PUNTEROS -> PRIMER elemento to ULTIMO elemento
    for (auto it = numeros.begin(); it != numeros.end(); it++)
        std::cout << *it << std::endl;
    
    // ! .begin() devuelve un puntero hacia el primer elemento del vector
    // ! .end()   devuelve un puntero hacia el ultimo elemento del vector

    std::cout << std::endl;

    

    // * ITERAR UN VECTOR CON PUNTEROS -> ULTIMO elemento to PRIMER elemento
    for (auto it = numeros.rbegin(); it != numeros.rend(); it++) 
        std::cout << *it << std::endl;   

    // ! .rend() devuelve un puntero hacia el ultimo elemento del vector
    // ! .rend() devuelve un puntero hacia el primer elemento del vector

    // * Cuando hablamos de punteros solo se pueden hacer operaciones de suma (++)
    // * Por lo que es necesario utilizar .rbegin() - .rend() para poder iterar de esa forma




    // int numeros[] = {1, 2, 3, 4, 5};
    // int *direccion = numeros;

    // for (int i = 0; i < 5; i++)
    //     std::cout << "Posicion del vector [" << i << "]: " << *direccion++ << std::endl;





    return EXIT_SUCCESS;
}