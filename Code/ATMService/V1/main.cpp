// Create un logFile uwu
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

void loopAtm() {
    ATM* atm = new ATM();

    atm -> writeLog();

    do {
        switch (mainMenu()) {
            case 1: {
                User* user = new User(true);
                if (user -> createAccount()) {
                    std::cout << std::endl << "Succesfully signed up" << std::endl;
                    atm -> writeLog("New user created: " + user -> getUsername());
                    system("pause");
                } else {
                    std::cout << std::endl <<"Failed to sign up" << std::endl;
                    atm -> writeLog("Failed to create a new instance of user");
                    system("pause");
                }
                
                delete user;

                break;
            }

            case 2: {
                User* user = new User(false);
                if (user -> tryLogin()) {
                    std::cout << std::endl << "Succesfully logged" << std::endl;
                    atm -> writeLog("User accessed to account: " + user -> getUsername());
                    system("pause");
                    
                    user -> userDashboard(atm);
                } else {
                    std::cout << std::endl << "Failed to log up" << std::endl;
                    atm -> writeLog("User " + user -> getUsername() + " failed to accessed to account");
                    system("pause");
                }

                delete user;

                break;
            }

            case 3: {
                User* user = new User(false);

                if (user -> deleteAccount()) {
                    std::cout << std::endl << "Succesfully deleted account" << std::endl;
                    atm -> writeLog("Deleted account: " +  user -> getUsername());
                    system("pause");
                } else {
                    std::cout << std::endl << "[...]" << std::endl;
                    atm -> writeLog("Attempt to delete account: " +  user -> getUsername());
                    system("pause");
                }

                delete user;
                exit(EXIT_SUCCESS);
                break;
            }

            default:
                exit(EXIT_SUCCESS);
        }
        clearBuffers();
    } while (true);
}


int main(void) {
    loopAtm();

    return EXIT_SUCCESS;
}