#include <bits/stdc++.h>
#include "classPlayer.h"
#include "mainFunctions.h"

int main() {
    Player* player = new Player(displayGameModes());
    
    GuessNumber* guessNumber = new GuessNumber();

    guessNumber -> selectGameMode();


    return EXIT_SUCCESS;
}