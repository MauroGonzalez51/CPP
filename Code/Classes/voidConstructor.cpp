#include <bits/stdc++.h>

class Person {
    private:
        std::string name;
        int age;
    
    public:
        Person(void);

        std::string getName() { return this -> name; }
};

Person::Person(void) {
    std::cout << std::endl;

    std::cout << "Name: ";
    std::cin >> this -> name;

    std::cout << std::endl;

    std::cout << "Age: ";
    std::cin >> this -> age;
}

int main() {
    Person person[2];


    return EXIT_SUCCESS;
}