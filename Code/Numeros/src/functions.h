#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>

std::vector <int> getDivisorsOf(int number);
int getMCD(int dividend, int divisor);
bool isPrime(int number);

int handleCase(int option);
void mainMenu();

std::vector <int> primesLessThan(int threshold);

#endif