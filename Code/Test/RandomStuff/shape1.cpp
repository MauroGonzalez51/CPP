#include <bits/stdc++.h>

void printShape() {
    int numberOfRows;
    do {
        std::cout << "Rows: ";
        std::cin >> numberOfRows;
    } while (numberOfRows < 0);
    std::cout << std::endl;
    for (int i = 1; i <= numberOfRows; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main(void) {
    printShape();
    return EXIT_SUCCESS;
}