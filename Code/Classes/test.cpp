#include <bits/stdc++.h>

using namespace std;

class Personas {
    public:
        string nombre, code;
};

class Estudiantes : public Personas {
    private:
        string name, code;
        int age;
    public:
        Estudiantes(string name, string code, int age) {
            this -> name = name;
            this -> code = code;
            this -> age = age;
        }  

        string getName(); 
        string getCode();
        int getAge();
};

string Estudiantes::getName() {
    return this -> name;
}

string Estudiantes::getCode() {
    return this -> code;
}

int Estudiantes::getAge() {
    return this -> age;
}


class Profesores : public Personas {
    private:
        string name, code, cc;
        int age;

        Profesores(string name, string code, string cc, int age) {
            this -> name = name;
            this -> code = code;
            this -> cc = cc;
            this -> age = age;
        }

        string getName();
        string getCode();
        string getCC();
        int getAge();
};

string Profesores::getName() {
    return this -> name;
}

string Profesores::getCode() {
    return this -> code;
}

string Profesores::getCC() {
    return this -> cc;
}

int Profesores::getAge() {
    return this -> age;
}

int main(void) {
   Estudiantes obj1("Mauro", "82973052", 17);

   cout << obj1.getName() << endl;
   cout << obj1.getAge() << endl;

}