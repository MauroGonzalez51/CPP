#include <bits/stdc++.h>

//! DICLAIMER
//! Binary seach is only aplicable when the array given is sorted
//! If not, then we have to sorted it first

std::vector <int> array;

int linearSeach() {
    int elementToSeach;
    std::cout << "Element to seach: ";
    std::cin >> elementToSeach;

    for (int i = 0; i < array.size(); i++) {
        if (array.at(i) == elementToSeach) {
            return i;
        }
    }
    return -1;
}

void fillArray() {
    int quantity;
    std::cout << "-> ";
    std::cin >> quantity;
    
    for (int i = 0; i < quantity; i++) {
        int aux;
        std::cin >> aux;

        array.push_back(aux);
    }
}


int main(void) {
    fillArray();
    std::cout << linearSeach() << std::endl;

    return EXIT_SUCCESS;
}