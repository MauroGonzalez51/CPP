#include <bits/stdc++.h>

void clearBuffers(void) {
    std::cin.ignore(std::numeric_limits <std::size_t>::max());
}

class Person {
    private:
        std::string name;

    public:
        Person(void) {
            clearBuffers();
            std::cout << "Name: ";
            std::cout << std::endl << "-> ";
            getline(std::cin, this -> name, '\n');
        }

        std::string getName() { return this -> name; }
};


int main(void) {
    Person* person = new Person();



    return EXIT_SUCCESS;
} 