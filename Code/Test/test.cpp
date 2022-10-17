#include <bits/stdc++.h>

int main() {
    std::vector <int> numeros(10);

    for (int i = 0; i < 10; i++) {
        std::cout << "-> ";
        std::cin >> numeros[i];
    }

    for (auto &numero : numeros)
        std::cout << numero << " ";


    return EXIT_SUCCESS;
}