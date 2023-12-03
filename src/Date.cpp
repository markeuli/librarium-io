#include "Date.h"
#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

Date::Date() {
    updateCurrentDate();
}

void Date::updateCurrentDate() {
    time_t ttime = time(0);             // get time now
    tm *local_time = localtime(&ttime); // convert to local time
    dateInfo = *local_time;             //set dateInfo to local time
}

int Date::getYear() const {
    return dateInfo.tm_year + 1900;
}

int Date::getMonth() const {
    return dateInfo.tm_mon + 1; 
}

int Date::getDay() const {
    return dateInfo.tm_mday;
}

std::string Date::getDateString() const {
    char buffer[11]; 
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &dateInfo);
    return buffer;
}