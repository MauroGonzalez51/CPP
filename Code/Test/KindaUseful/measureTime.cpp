#include <bits/stdc++.h>

void randomFunction(const int iterations) {
    for (int i = 0; i < iterations; i++) {}
}

void choice_1() {
    // ! Measures time in seconds :>
    // * Returns an integrer value

    time_t startPointTime, endPointTime;
    time(&startPointTime);
    std::ios_base::sync_with_stdio(false);

    // TODO Code ....

    time(&endPointTime);
    double timeTaken = double(endPointTime - startPointTime);
    std::cout << "Time Taken: " << std::fixed << timeTaken  << std::setprecision(10) << " sec" << std::endl;
}

void choice_2() {
    // * Measures CPU Clock, not real time taken :>

    unsigned int startTime, endTime;

    startTime = clock();

    // TODO Code ....

    endTime = clock();

    double elapsedTime = (double(endTime - startTime) / CLOCKS_PER_SEC);
    std::cout << "Elapsed Time: " << elapsedTime << std::endl;
}

void choice_3() {
    // * Return a integrer value
    // ! Measures time depending on the std::chrono::duration :O

    auto startPoint = std::chrono::high_resolution_clock::now();

    // TODO Code ....

    auto endPoint = std::chrono::high_resolution_clock::now();

    // !                                                 | HERE |
    auto elapsedTime = std::chrono::duration_cast <std::chrono::nanoseconds> (endPoint - startPoint);

    std::cout << "Elapsed Time: " << elapsedTime.count() << std::endl;

    // * std::chrono::nanoseconds
    // * std::chrono::microseconds
    // * std::chrono::milliseconds
    // * std::chrono::seconds
    // * std::chrono::minutes
    // * std::chrono::hours
}

void choice_4() {
    // * Returns elapsed time since 1970 (January 1st)
    // ! Mesures time in seconds, well, both in seconds and microseconds, and then added one to another

    struct timeval startPoint, endPoint;
    mingw_gettimeofday(&startPoint, 0);

    // TODO Code ....

    mingw_gettimeofday(&endPoint, 0);
    long seconds = endPoint.tv_sec - startPoint.tv_sec;
    long microseconds = endPoint.tv_usec - startPoint.tv_usec;
    double elapsedTime = seconds + (microseconds * 1e-6);

    std::cout << "Elapsed Time: " << elapsedTime << std::endl;
}

int main(void) {

    return EXIT_SUCCESS;
}