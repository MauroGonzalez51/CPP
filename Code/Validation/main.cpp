#include <bits/stdc++.h>

using namespace std;

class Person {
    public:
        int age, genre, educativeLevel, stratum;

        struct {
            int month, day, year;
            bool isLeapYear;
        } birthDate;

        bool validateAge() {
            return ((this -> age < 0) ? true : false);
        }

        bool validateGenre() {
            bool isValid = false;
            array <int, 3> validEntries = {1, 2, 3};

            for (int i : validEntries) {
                if (this -> genre == i)
                    isValid = true;
            }

            return isValid;
        }

        bool validateEducationLevel() {
            bool isValid = false;
            array <int, 4> validEntries = {1, 2, 3, 4};

            for (int i : validEntries) {
                if (this -> educativeLevel == i)
                    isValid = true;
            }
            
            return isValid;
        }

        bool validateStratum() {
            bool isValid = false;
            array <int, 6> validEntries = {1, 2, 3, 4, 5, 6};

            for (int i : validEntries) {
                if (this -> stratum == i)
                    isValid = true;
            }

            return isValid;
        }

        bool validateYear() {
            time_t currentTime;

            currentTime = time(NULL);
            int currentYear = 1970 + currentTime / 31537970;

            return ((this -> birthDate.year >= currentYear) ? false : true);
        }

        bool validateMonth() {
            bool isValid = false;
            array <int, 12> validEntries = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            for (int i : validEntries) {
                if (this -> birthDate.month == i)
                    isValid = true;
            }

            return isValid;
        }

        void isLeapYear() {
            this -> birthDate.isLeapYear = false;
            bool checkNextCase = false;

            if (checkNextCase) {
                ((this -> birthDate.year % 4) == 0) ?
                    checkNextCase = true : checkNextCase = false;
            }

            if (checkNextCase) {
                if ((this -> birthDate.year) % 100 != 0) {
                    this -> birthDate.isLeapYear = true;
                    checkNextCase = false;
                } else 
                    checkNextCase = true;
            }

            if (checkNextCase) {
                ((this -> birthDate.year % 100 == 0) && (this -> birthDate.year % 400 == 0)) ?
                    this -> birthDate.isLeapYear = true : this -> birthDate.isLeapYear = false;
            }
        }

        bool validateDay() {
            bool isValid = false, checkNextCase = true;

            if (checkNextCase) {
                array <int, 7> validEntriesMonth = {1, 3, 5, 7, 8, 10, 12};
                for (int i : validEntriesMonth) {
                    if (this -> birthDate.month == i) {
                        array <int, 31> validEntriesDay;
                        for (int i = 1; i <= 31; i++)
                            validEntriesDay[i - 1] = i;                        
                        
                        for (int i : validEntriesDay) {
                            if (this -> birthDate.day  == i) {
                                isValid = true;
                                checkNextCase = false;
                            }
                        }
                    }
                }
            }

            if (checkNextCase) {
                array <int, 4> validEntriesMonth = {4, 6, 9, 11};
                for (int i : validEntriesMonth) {
                    if (this -> birthDate.month == i) {
                        array <int, 30> validEntriesDay;
                        for (int i = 1; i <= 30; i++)
                            validEntriesDay[i - 1] = i;

                        for (int i : validEntriesDay) {
                            if (this -> birthDate.day == i) {
                                isValid = true;
                                checkNextCase = false;
                            }
                        }
                    }
                }
            }

            if (checkNextCase) {
                array <int, 1> validEntriesMonth = {2};
                for (int i : validEntriesMonth) {
                    if (this -> birthDate.month == i) {
                        array <int, 28> validEntriesDay;
                        for (int i = 0; i <= 28; i++)
                            validEntriesDay[i - 1] = i;
                        
                        for (int i : validEntriesDay) {
                            if ((this -> birthDate.day == i) && (this -> birthDate.isLeapYear == false)) {
                                isValid = true;
                                checkNextCase = false;
                            }
                        }
                    }
                }
            }

            if (checkNextCase) {
                array <int, 1> validEntriesMonth = {2};
                for (int i : validEntriesMonth) {
                    if (this -> birthDate.month == i) {
                        array <int, 29> validEntriesDay;
                        for (int i = 0; i <= 29; i++)
                            validEntriesDay[i - 1] = i;
                        
                        for (int i : validEntriesDay) {
                            if ((this -> birthDate.day == i) && (this -> birthDate.isLeapYear == true)) {
                                isValid = true;
                                checkNextCase = false;
                            }
                        }
                    }
                }
            }

            return isValid;
        }

};

void getAge(Person& person) {
    do {
        cout << "Age: ";
        cin >> person.age;
    } while (person.validateAge());
    cout << endl;
}

void getGender(Person& person) {
    do {
        cout << "Gender: ";
        cin >> person.genre;
    } while (!person.validateGenre());
    cout << endl;
}

void getEducativeLevel(Person& person) {
    do {
        cout << "Educative Level: ";
        cin >> person.educativeLevel;
    } while (!person.validateEducationLevel());
    cout << endl;
}

void getStratum(Person& person) {
    do {
        cout << "Stratum: ";
        cin >> person.stratum;
    } while (!person.validateStratum());
}

void getYear(Person& person) {
    do {
        cout << "Year: ";
        cin >> person.birthDate.year;
    } while (!person.validateYear());
    person.isLeapYear();
    cout << endl;
}

void getMonth(Person& person) {
    do {
        cout << "Month: ";
        cin >> person.birthDate.month;
    } while (!person.validateMonth());
    cout << endl;
}

void getDay(Person& person) {
    do {
        cout << "Day: ";
        cin >> person.birthDate.day;
    } while (!person.validateDay());
}

void getBirthDate(Person& person) {
    cout << "Birth Date" << endl;
    getYear(person);
    getMonth(person);
    getDay(person);
}


int main() {
    Person person;

    // getAge(person);

    // getGender(person);

    // getEducativeLevel(person);

    // getStratum(person); 

    getBirthDate(person);
    


    return EXIT_SUCCESS;
}