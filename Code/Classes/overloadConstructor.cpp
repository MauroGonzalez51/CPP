#include <bits/stdc++.h>

// class Date {
//     private:    
//         int day, month, year;
    
//     public: 
//         Date(int, int, int);
//         Date(long);
//         void showDate();
// };

// // date/month/year
// Date::Date(int day, int month, int year) {
//     this -> day = day;
//     this -> month = month;
//     this -> year = year;
// }

// // yearMonthDay
// Date::Date(long date) {
//     this -> year = int(date / 10000);
//     this -> month = int((date - (this -> year * 10000)) / 100);
//     this -> day = int(date - (this -> year * 10000) - (this -> month * 100));
// }

// void Date::showDate() {
//     std::cout << "Date: " << this -> day << "/" << this -> month << "/" << this -> year << std::endl;
// }

// int main(void) {
//     Date today(9, 1, 2017);
//     Date yesterday(20170108);

//     today.showDate();
//     yesterday.showDate();

//     return EXIT_SUCCESS;
// }

class Time {
    private:
        int seconds, minutes, hours;

    public:
        Time(int, int, int);
        Time(long long);

        void showTime() {
            std::cout << "Time: " << this -> hours << "- " << this -> minutes << "- " << this -> seconds << std::endl;
        }
};

Time::Time(int seconds, int minutes, int hours) {
    this -> seconds = seconds;
    this -> minutes = minutes;
    this -> hours = hours;
}

Time::Time(long long totalSeconds) {
    this -> hours = int(totalSeconds / 3600);
    this -> minutes = int((totalSeconds - (this -> hours * 3600)) / 60);
    this -> seconds = totalSeconds - (this -> hours * 3600) - (this -> minutes * 60);
}


int main(void) {
    Time* time = new Time(43734633255);

    time -> showTime();



    return EXIT_SUCCESS;
}