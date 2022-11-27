#include <bits/stdc++.h>

int main(void) {
    Timer clock();

    clock.tick();
    for (int i = 0; i < 1000000000; i++) {}

    clock.tock();
    
    std::cout << clock.duration().count() << std::endl;
    

    



    return EXIT_SUCCESS;
}