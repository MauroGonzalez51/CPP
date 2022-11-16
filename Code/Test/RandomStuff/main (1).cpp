#include <bits/stdc++.h>

using namespace std;

void writeLog(string msgToLog);

int main() {

    string msg;

    do {
        cout << "-> ";
        cin >> msg;

        writeLog(msg);

    } while (true);

    return 0;
}



void writeLog(string msgToLog) {
    time_t now = time(0);
    char* dateTime = ctime(&now);

    ofstream logFile(
        "logFile.txt", ios_base::out | ios_base::app );
    
    string date = dateTime;

    string msgIn = date + " -> " + msgToLog;
    logFile << msgIn; 
}