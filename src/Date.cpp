#include "Date.h"
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

Date::Date() {
    updateCurrentDate();
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::updateCurrentDate() {
    time_t ttime = time(0);             // get time now
    tm *local_time = localtime(&ttime); // convert to local time
    dateInfo = *local_time;             //set dateInfo to local time
    year = dateInfo.tm_year + 1900;
    month = dateInfo.tm_mon + 1;
    day = dateInfo.tm_mday;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::string Date::getDateString() const {
    char buffer[11]; 
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &dateInfo);
    return buffer;
}