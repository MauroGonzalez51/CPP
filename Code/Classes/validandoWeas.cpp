#include <bits/stdc++.h>

using namespace std;

class Person {
    public:
        int someProperty;

        bool validateSome();
};

bool Person::validateSome() {
    bool isValid = false;

    array <int, 3> validEntries = {1, 2, 3};
    for (int i = 0; i < validEntries.size(); i++) {
        if (this -> someProperty == validEntries[i])
            isValid = true;
    }

    return !isValid;
}

int main() {
    Person person;

    do {
        cout << "-> ";
        cin >> person.someProperty;
    } while (person.validateSome());



    return EXIT_SUCCESS;
}