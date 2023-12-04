/* Date.h
 * Description: This header declares a Date class the essentially serves as a struct
 *              to hold the current date. It also has a method to update the current date using ctime.
 * 
 * 
 * Authors: Mark Ulicnik, Long Chau
 * Date Created: 12/1/2023 
*/

#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <string>
#include <chrono>

class Date {
private:
    std::tm dateInfo;
    int day;
    int month;
    int year;

public:
    Date();

    Date(int day, int month, int year);

    void updateCurrentDate();

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    std::string getDateString() const;
};

#endif