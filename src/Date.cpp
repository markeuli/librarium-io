#include "Date.h"

Date::Date() {
    updateCurrentDate();
}

void Date::updateCurrentDate() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    localtime_s(&dateInfo, &now);
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