#include <iostream>
#include <string.h>

class Player {
    private:
        float balance;
        int coins;
        std::string name;

    public:
        Player(int gameMode) {
            std::cout << "Enter your name: ";
            std::cin >> this -> name;
            
            switch (gameMode) {
                case 1: {
                    std::cout << "Hey, " << this -> name << ", Enter your initial balance to play: ";
                    std::cin >> this -> balance;
                    break;
                }

                case 2: {
                    std::cout << "Hey, " << this -> name << ", Enter your initial coins to play: ";
                    std::cin >> this -> coins;
                    break;
                }

                default: 
                    exit(EXIT_FAILURE);
            }
        }
};
