#include "monitor.h"

Monitor::Monitor(
    const std::string& ID, 
    const std::string& firstName, 
    const std::string& lastName, 
    const std::string& subjectName,
    const std::vector<std::string>& daysList
    ) : ID(ID), firstName(firstName), lastName(lastName), daysList(daysList) {}

std::string Monitor::getID() const {
    return this -> ID;
}

std::string Monitor::getFirstName() const {
    return this -> firstName;
}

std::string Monitor::getLastName() const {
    return this -> lastName;
}

std::string Monitor::getSubjectName() const {
    return this -> subjectName;
}

std::vector<std::string> Monitor::getDaysList() const {
    return this -> daysList;
}
