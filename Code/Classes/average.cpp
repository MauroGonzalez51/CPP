#include <bits/stdc++.h>

using namespace std;

class Students {
    public:
        float grade;
        string name;

};

float average(Students s1, Students s2) {
    return (s1.grade + s2.grade) / 2;
}

int main(void) {
    Students student1, student2;

    cout << "Name: ";
    cin >> student1.name;

    cout << "Grade: ";
    cin >> student1.grade;

    cout << "Name: ";
    cin >> student2.name;

    cout << "Grade: ";
    cin >> student2.grade;

    cout << average(student1, student2);
}