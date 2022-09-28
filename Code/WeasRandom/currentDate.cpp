#include <bits/stdc++.h>

using namespace std;

int main() {
    time_t now = time(0);
    char* dateTime = ctime(&now);

    cout << "Current Date: " << dateTime << endl;
    return 0;
}