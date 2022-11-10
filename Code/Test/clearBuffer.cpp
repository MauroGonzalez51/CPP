#include <bits/stdc++.h>

int main(void) {
    std::string line;
    do {
        std::cout << "-> ";
        std::getline(std::cin, line);
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << ": " << line << std::endl;
    } while (true);
}