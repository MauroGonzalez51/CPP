#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <vector>

class Monitor {
    private:
        std::string ID, firstName, lastName, subjectName;
        std::vector<std::string> daysList;

    public:
        Monitor(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& subjectName,const std::vector<std::string>& daysList);
    
        std::string getID() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getSubjectName() const;
        std::vector<std::string> getDaysList() const;
};

#endif
