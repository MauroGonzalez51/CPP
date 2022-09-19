#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        int age;
        string name;

    Person(int x1, string y1) {
        this -> age = x1;
        this -> name = y1;
    }

    // int age() { return this -> personAge; }
    // string name() { return this -> personName; }
};

class Student {
    public:
        int age, grade;
        string name;
    
        Student(int x1, int x2, string y1) {
            this -> age = x1;
            this -> grade = x2;
            this -> name = y1;
        }

};

class Test {
    private:
        string name;
        int age;
    
    public:
        void setValues() {
            cout << "Name: ";
            getline(cin, name);

            cout << "Age: ";
            cin >> age;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
        
};

int main() {
    // Person person1(17, "Mauro");

    // cout << person1.age() << endl;
    // cout << person1.name() << endl;

    // cout << endl <<  "[...]" << endl << endl;

    // Student student1(17, 10, "Samuel");
    // cout << student1.age << endl;

    // Test obj1;

    // obj1.setValues();
    // obj1.display();
    
    Person person1(17, "Mauro");
    cout << person1.personName << endl;

    return 0;
}