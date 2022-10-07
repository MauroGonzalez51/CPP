#include <bits/stdc++.h>

using namespace std;

class personas {
    private: 
        string name;
        int age;

    public:
        personas(string name, int age) {
            this -> name = name;
            this -> age = age;
        }
};

int main(void) {
    personas* people = new personas("Mauro", 17);
}