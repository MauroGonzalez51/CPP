#include <bits/stdc++.h>

unsigned int number;

std::vector <unsigned int> previousConsecutiveNumbers;

void displayCase(const int count) {
    std::cout << count << ") ";
    for (int i = 0; i < (previousConsecutiveNumbers.size() - 1); i++) 
        std::cout << previousConsecutiveNumbers.at(i) << " + ";
    std::cout << previousConsecutiveNumbers.back() << std::endl;
    std::cout << std::endl;
}

bool verifySumatory(const int number) {
    unsigned int sumatory = 0;
    for (auto &number : previousConsecutiveNumbers) sumatory += number;
    return ((sumatory == number) ? true : false);
}

void fillPreviosNumbers(const int amountToFill, int startPoint, const int &endPoint) {
    for (int i = 0; i < amountToFill; i++) {
        if (startPoint < endPoint) {
            previousConsecutiveNumbers.push_back(startPoint);
            startPoint++;
        }
    }
}

void consecutiveNumbers() {
    do {
        std::cout << "-> ";
        std::cin >> number;
    } while (number < 0);

    int amountOfCases = 0;
    std::cout << std::endl;

    auto startPoint = std::chrono::high_resolution_clock::now();

    for (int amountOfNumbers = 1; amountOfNumbers < number; amountOfNumbers++) {
        for (int startPoint = 1; startPoint < number; startPoint++) {
            fillPreviosNumbers(amountOfNumbers, startPoint, number);
            if (verifySumatory(number)) { amountOfCases++; displayCase(amountOfCases); }
            previousConsecutiveNumbers.clear();
        }
    }

    auto endPoint = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast <std::chrono::nanoseconds> (endPoint - startPoint);
    std::cout << "Time Taken: " << elapsedTime.count() << " (Nanoseconds)" << std::endl;
    std::cout << "Seconds: " << double(elapsedTime.count() / 1000000000) << std::endl;


    if (!(bool) amountOfCases) std::cout << std::endl << "No possible representation as a sumatory of consecutive Numbers" << std::endl;
}

int main(void) {
    consecutiveNumbers();
    return EXIT_SUCCESS;
}