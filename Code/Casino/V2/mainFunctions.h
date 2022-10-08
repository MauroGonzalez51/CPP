#include <iostream>
#include <array>
#include <set>
#include <string.h>

std::set <int> validGameModes;

bool validateMsg(char msg[3]) {
    // Basicamente lo que hace es validar si la opcion ingresada coincide con el "total" de opciones posibles
    std::array <std::string, 20> options = {"Si", "No", "si", "no", "SI", "NO", "S", "N", "s", "n", "y", "n", "Y", "N", "YES", "NO", "yes", "no", "Yes", "No"};
    // Flag = false significa que el programa va a salir
    bool Flag = false;
    for (int i = 0; i < options.size(); i++) {
        if (msg == options[i]) {
            Flag = true;
            if (i % 2 != 0){
                Flag = false;
            }
        }
    }
    return Flag;
}

bool validateGameMode(int option) {
    bool isValid = false;
    for (int i : validGameModes) {
        if (option == i)
            isValid = true;
    }

    return isValid;
}

int selectGameMode() {
    int option;

    do {
        std::cout << "-> ";
        std::cin >> option;
    } while (!validateGameMode(option));

    return option;
}

int displayGameModes() {
    system("cls");

    std::cout << std::endl;
    for (int i = 0; i < 50; i++)
        std::cout << "-";
    
    std::cout << std::endl;

    std::cout << "Game Modes" << std::endl;

    std::cout << "[1]. Guess a Number" << std::endl;
    validGameModes.insert(1);

    return selectGameMode();
}