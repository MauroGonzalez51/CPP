#include <bits/stdc++.h>
#include "classPlayer.h"
#include "mainFunctions.h"

int main() {
    Player* player = new Player(displayGameModes());
    
    gameLauncher(player);

    return EXIT_SUCCESS;
}