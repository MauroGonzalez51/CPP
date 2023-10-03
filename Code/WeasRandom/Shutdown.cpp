#include <iostream>
#include <chrono>
#include <thread>

void setTimeout(int seconds) {
    for (int i = seconds; i >= 0; i--) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


int main() {
    int seconds = 10;

    std::cout << "El equipo se apagara en " << seconds << " segundos" << std::endl;

    std::thread timerThread(setTimeout, seconds);

    timerThread.join();

    return EXIT_SUCCESS;
}
