#include <bits/stdc++.h>

const char* getCurrentTime() {
    time_t now = time(0);
    const char* dateTime = ctime(&now);

    return dateTime;
}

int main() {
    std::cout << getCurrentTime() << std::endl;

    return EXIT_SUCCESS;
}