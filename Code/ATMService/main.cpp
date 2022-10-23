#include <bits/stdc++.h>
#include "ATMClass.h"
#include "userClass.h"

void clearBuffers() {
    std::cin.ignore(std::numeric_limits<std::size_t>::max());
}


int mainMenu() {
    std::cout << std::endl;

    for (int i = 0; i < 40; i++)
        std::cout << "-";
    std::cout << std::endl;

    int choice;
    clearBuffers();
    std::cout << "Main Menu" << std::endl;
    std::cout << "1. Create Account" << std::endl;
    std::cout << "2. Access the Account" << std::endl;
    std::cout << "3. Delete the Account" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << std::endl << "-> ";
    std::cin >> choice;

    return choice;
}

void dashboardAccount(User* user) {
    std::cout << std::endl << "Buenos dias" << std::endl;
}

void loopAtm() {
    do {
        switch (mainMenu()) {
            case 1: {
                User* user = new User(true);
                (user -> createAccount()) ?
                    std::cout << std::endl << "Succesfully signed up" << std::endl :
                        std::cout << std::endl <<"Failed to sign up" << std::endl;
                
                delete user;

                break;
            }

            case 2: {
                User* user = new User(false);
                (user -> tryLogin()) ? 
                    std::cout << std::endl << "Succesfully logged" << std::endl :
                        std::cout << std::endl << "Failed to log up" << std::endl;

                dashboardAccount(user);
                
                delete user;

                break;
            }

            default:
                exit(EXIT_SUCCESS);
        }

    } while (true);
}


int main(void) {
    loopAtm();

    return EXIT_SUCCESS;
}