#include <bits/stdc++.h>

void passwordGenerator() {
    int length;
    do {
        std::cout << "-> ";
        std::cin >> length;
    } while (length < 1);

    std::string caracters = "abcdefghijklmopqrstuwxyzABCDEFGHIJKLMNOPKRSTUWXYZ0123456789!*/?¿#";

    std::string passwordGenerated = "";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int randomIndex = 0 + rand() % ((caracters.size() + 1) - 1);
        char randomCaracter = caracters[randomIndex];
        passwordGenerated += randomCaracter;
    }

    std::cout << passwordGenerated << std::endl;
}

int main(void) {
    passwordGenerator();
    return EXIT_SUCCESS;
}