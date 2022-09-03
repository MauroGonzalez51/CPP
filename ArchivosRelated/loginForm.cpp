#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

bool isLoggedIn();

int main() {
    int choice;
    cout << endl;
    cout << "1: Register" << endl;
    cout << "2: Login" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: {
            string username, password;

            cout << "Select a username: ";
            getline(cin, username);

            cout << "Select a password: ";
            getline(cin, password);

            // ofstream is creating a file
            ofstream file;
            file.open("data\\" + username + ".txt");
            file << username << endl;
            file << password << endl;
            file.close();

            main();
        }
        case 2: {
            bool status = isLoggedIn();

            if (!status) {
                cout << "False Login!" << endl;
                system("PAUSE");
                return 0;
            } else {
                cout << "Succesfully Logged in!" << endl;
                system("PAUSE");
                return 1;
            }
        }
    }



}

bool isLoggedIn() {
    string username, password, un, pw;
    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    // ifstream is reading a file
    ifstream read("c:\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    return ((un == username) && (pw == password)) ? true : false;
}