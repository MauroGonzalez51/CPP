#include <bits/stdc++.h>

using namespace std;

class Student {
    public:
        array <int, 4> notes;

    void setValues() {
        for (int i = 0; i < notes.size(); i++) {
            cout << "Note " << i + 1 << ": ";
            cin >> notes[i];
        }
    }
};

int main(void) {
    Student obj;
    obj.setValues();

    cout << endl;
    cout << "NOTES" << endl;
    for (int i = 0; i < 4; i++) {
        cout << obj.notes[i] << endl;
    }

}