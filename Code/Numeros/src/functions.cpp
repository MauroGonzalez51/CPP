#include "functions.h"

// ! ----------------------------------------------------------------------------------------------------------------|>

/**
 * ! MAIN FUNCTIONS 
 * 
 * * std::vector <int> getDivisorsOf(@param int number)
 * 
 * returns a vector with all the divisors of the given number
 * 
 * 
 * * int getMCD(@param int dividend, @param int divisor)
 * 
 * Uses the Euclides's algorithm to calculate the MCD of two numbers
 * In case divisor is greater than dividend, the numbers will be swapped
 * 
 * The function also works with a copy of the numbers (by value) because
 * is no needed to utilize the reference
 * 
 * returns an integer in case of the MCD exists, if not, -1
 * 
 * * bool isPrime(@param int number)
 * 
 * Utilizes the previous funcion "getDivisorsOf()" in order to know
 * if a number is prime or not
 * 
 * If the vector returned has a size greater than two, that means that the
 * number is NOT a prime, if is lower or equal to two, is prime.
 * 
 * returns a boolean
 * 
 * 
 * 
 * 
 * 
*/

// * ------------------------------------------------------------------------------------|>

std::vector <int> getDivisorsOf(int number) {
    std::vector <int> divisors;

    for (int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            divisors.push_back(i);
            if (i != number / i) {
                divisors.push_back(number / i);
            }
        }
    }

    return divisors;
}

// * ------------------------------------------------------------------------------------|>

int getMCD(int dividend, int divisor) {
    int residue;

    if (divisor > dividend) 
        std::swap(dividend, divisor);
    
    do {
        int quotient = dividend / divisor;
        residue = dividend % divisor;

        dividend = divisor;
        divisor = residue;
    } while (residue != 0);

    return dividend;
}

// * ------------------------------------------------------------------------------------|>

bool isPrime(int number) {
    return (getDivisorsOf(number).size() > 2) ? false : true;
}

// ! ----------------------------------------------------------------------------------------------------------------|>

std::vector <int> primesLessThan(int threshold) {
    std::vector <int> primes;

    for (int i = 2; i <= threshold; i++) {
        if (isPrime(i)) primes.push_back(i);
    }

    return primes;
}

// * ------------------------------------------------------------------------------------|>

std::vector <int> twinPrimesLessThan(int threshold) {
    std::vector <int> twinPrimes;

    for (int i = 2; i <= threshold; i++) {
        if (isPrime(i) && isPrime(i + 2) && (i + 2 <= threshold)) {
            twinPrimes.push_back(i);
        }
    }

    return twinPrimes;
}

// * ------------------------------------------------------------------------------------|>

std::vector <int> getSolphieGermainPrimes(int threshold) {
    std::vector <int> solphieGermainPrimes;

    for (int i = 2; i <= threshold; i++) {
        if (isPrime(i) && isPrime((2 * i) + 1) && ((2 * i) + 1 <= threshold)) {
            solphieGermainPrimes.push_back(i);
        }
    }

    return solphieGermainPrimes;
}

// * ------------------------------------------------------------------------------------|>

void solveProblem() {
    /**
     * The sum of the ages is 29
     * All the ages are odd
     * All ages are prime numbers
     * 
     * 
    */

    int targetSum = 29;
    std::vector <int> primes = primesLessThan(targetSum);
    std::vector <int> oddPrimes;

    std::copy_if(primes.begin(), primes.end(), std::back_inserter(oddPrimes), [] (int num) {
        return num % 2 != 0;
    });

    std::cout << std::endl;
    for (auto &firstPrime : oddPrimes) {
        for (auto &secondPrime : oddPrimes) {
            for (auto &thirdPrime : oddPrimes) {
                if ((firstPrime + secondPrime + thirdPrime) == targetSum) {
                    std::cout << "[ " << firstPrime << " - " << secondPrime << " - " << thirdPrime << " ]" << std::endl;
                }
            }
        }
    }
}


// ! ----------------------------------------------------------------------------------------------------------------|>

/**
 * ! MAIN MENU related
 * 
 * functions responsible for calling the other functions and displaying the 
 * results into console
 * 
 * 
 * 
 * 
 * 
 * 
*/

// * ------------------------------------------------------------------------------------|>

int handleCase(int option) {
    int exit = 1;

    switch (option) {
        case 1: {
            std::vector <int> primes = primesLessThan(1000);

            std::cout << std::endl;
            for (auto &i : primes) {
                std::cout << i << " ";
            } 

            std::cout << std::endl;

            break;
        }

        case 2: {
            std::vector <int> twinPrimes = twinPrimesLessThan(1000);

            std::cout << std::endl;

            for (auto &value : twinPrimes) {
                std::cout << "[ " << value << " - " << value + 2 << " ]" << std::endl;
            }

            break;
        }

        case 3: {
            std::vector <int> solphieGermainPrimes = getSolphieGermainPrimes(100); 

            std::cout << std::endl;
            for (auto &value : solphieGermainPrimes) {
                std::cout << "[ " << value << " ]" << std::endl;
            }
            break;
        }

        case 4: {
            solveProblem();
            break;
        }

        case 5:  { exit = 0; break; }

        default: {
            std::cout << "Ingrese una opcion valida" << std::endl;
        }
    }

    return exit;
}

// * ------------------------------------------------------------------------------------|>

void mainMenu() {
    int option;

    do {
        std::cout << std::endl;
        std::cout << "1. Numeros primos menores que 1000" << std::endl;
        std::cout << "2. Numeros primos gemelos menores que 1000" << std::endl;
        std::cout << "3. Numeros primos de Sophie menores que 100" << std::endl;
        std::cout << "4. Solucionar problema" << std::endl;
        std::cout << "5. Salir" << std::endl;

        std::cout << "-> ";
        std::cin >> option;
    } while (handleCase(option));
}