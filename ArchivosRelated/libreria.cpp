#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool getBooks();

int main() {
    return 0;
}

bool getBooks() {
    sting bookSearching;

    cout << "Enter the book that you want to search: ";
    getline(cin, bookSearching);

    ifstream read("c:\\library.txt");
    getline();
}