#include <bits/stdc++.h>

class Person {
    private:
        std::string name;
        int age;
        
    public:
        Person (std::string name, int age) {
            this -> name = name;
            this -> age = age;
        }
        
        std::string getName() { return this -> name; }
        int getAge() { return this -> age; }
};

class Worker : public Person {
    private:
        std::string workerCode;
    
    public:
        Worker (std::string name, int age, std::string workerCode) : Person (name, age) {
            this -> workerCode = workerCode;
        }
        
        // void showInfo() {
        //     std::cout << "Name: " << getName() << std::endl;
        //     std::cout << "Age: " << getAge() << std::endl;
        //     std::cout << "Code: " << this -> workerCode << std::endl;
        // }
};

int main(void) {


    return EXIT_SUCCESS;
}
