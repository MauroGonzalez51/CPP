#include <bits/stdc++.h>
#include <conio.h>
#include "classPlayer.h"
#include "mainFunctions.h"

int main() {
    Player* player = new Player(displayGameModes());
    
    gameLauncher(player);

    std::cout << "Press any key to continue..." << std::endl;
    getch();

    return EXIT_SUCCESS;
}