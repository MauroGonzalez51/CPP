#include <bits/stdc++.h>

void elevarCuadrado(int *numero) {
    *numero = pow(*numero, 2);
}


int main(void) {
    int numero = 10;
    elevarCuadrado(&numero);
    std::cout << numero << std::endl; 

    return EXIT_SUCCESS;
}