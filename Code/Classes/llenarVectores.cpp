/**
 *  @autor mauroGonzalez
 *  @code T00067622
 *  @description fill two arrays depending if the number is odd or even
 * 
 *  #include <iostream>
 *  #include <vector>
 * 
 * 
 * 
 * */



#include <bits/stdc++.h>

using namespace std;

class Numbers {
    public:
        vector <int> numbersEven;
        vector <int> numbersOdd;
        int enteredData = 0;
};

struct {
    int evenSumatory = 0, oddSumatory = 0;
    float evenAverage = 0.0, oddAverage = 0.0;
    int evenHigh = 0, oddHigh = 0;

} variables;

void isPair(Numbers* numbers, int& input) {
    if (input != 0) {
        if (input % 2 == 0)
            numbers -> numbersEven.push_back(input);
        else 
            numbers -> numbersOdd.push_back(input);
    }
}

void analizeResults(Numbers* numbers);
void calculateAverages(Numbers* numbers);

int main() {

    Numbers* number = new Numbers();
    int input;

    do {
        cout << "-> ";
        cin >> input;

        if (input != 0)
            number -> enteredData++;
        if ((number -> enteredData >= 1) && (input == 0 )) {
            analizeResults(number);
            break;
        } else {
            isPair(number, input);
            continue;
        }
        
    } while (true);

    return EXIT_SUCCESS;
}

void analizeResults(Numbers* numbers) {
    cout << endl << endl;

    cout << "Numeros [PARES]" << endl;
    for (int i : numbers -> numbersEven) {
        cout << i << " ";
    }

    cout << endl << endl;

    cout << "Numeros [IMPARES]" << endl;
    for (int i : numbers -> numbersOdd) {
        cout << i << " ";
    }

    for (int i : numbers -> numbersEven)
        variables.evenSumatory += i;
    
    if (numbers -> numbersEven.size() != 0)
        variables.evenAverage = variables.evenSumatory / numbers -> numbersEven.size();


    for (int i : numbers -> numbersOdd) 
        variables.oddSumatory += i;

    if (numbers -> numbersOdd.size() != 0)
        variables.oddAverage = variables.oddSumatory /  numbers -> numbersOdd.size();

    cout << endl << endl;
    cout << "Promedios" << endl;
    cout << "Numeros [PARES]: " << variables.evenAverage << endl;
    cout << "Numeros [IMPARES]: " << variables.oddAverage << endl;

    for (int i : numbers -> numbersEven) {
        if (i > variables.evenHigh) {
            variables.evenHigh = i;
        }
    }

    for (int i : numbers -> numbersOdd) {
        if (i > variables.oddHigh) {
            variables.oddHigh = i;
        }
    }

    cout << endl;
    cout << "Numeros mas altos " << endl;
    cout << "Numeros [PARES]: " << variables.evenHigh << endl;
    cout << "Numeros [IMPARES: " << variables.oddHigh << endl;
}