#include <bits/stdc++.h>

int main(void) {
    std::string line;
    do {
        std::cout << "-> ";
        std::getline(std::cin, line);
        fflush (stdin);
        std::cout << ": " << line << std::endl;
    } while (true);
}