#include <bits/stdc++.h>

// * &n = La direccion de memoria de n

// * *n = La variable cuya direccion esta almacenada en n



int main(void) {
    int num = 20, *direccionNum;
    direccionNum = &num;


    // ---- FORMA 1 ---- |>

    std::cout << "Numero: " << num << std::endl;

    // ! Direccion en memoria de num -> &num
    std::cout << "Direccion de memoria: " << &num << std::endl;
    

    // ---- FORMA 2 ---- |>

    std::cout << "Numero: " << *direccionNum << std::endl;
    std::cout << "Direccion de memoria: " << direccionNum << std::endl;






    return EXIT_SUCCESS;
}