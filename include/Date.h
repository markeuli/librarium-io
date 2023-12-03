#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>
#include <chrono>

class Date {
private:
    std::tm dateInfo;

public:
    Date();

    void updateCurrentDate();

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    std::string getDateString() const;
};

#endif