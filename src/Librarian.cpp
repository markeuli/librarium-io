/* Librarian.cpp
 * Description: This is the implementation for the librarian class. Holds data pertaining to a specific librarian.
 *
 * 
 * 
 * Authors: Sadaf Khan
 * Date Created: 12/1/2023 
*/

#include "Librarian.h"

Librarian::Librarian(std::string name, int employeeId, std::string email, std::string password, std::string shiftScheduled)
    : name(name), employeeId(employeeId), email(email), password(password), shiftScheduled(shiftScheduled) {}

std::string Librarian::getName() const {
    return name;
}

int Librarian::getEmployeeId() const {
    return employeeId;
}

std::string Librarian::getEmail() const {
    return email;
}

std::string Librarian::getPassword() const {
    return password;
}

std::string Librarian::getShiftScheduled() const {
    return shiftScheduled;
}

void Librarian::setName(const std::string& n) {
    name = n;
}

void Librarian::setEmployeeId(int id) {
    employeeId = id;
}

void Librarian::setEmail(const std::string& e) {
    email = e;
}

void Librarian::setPassword(const std::string& p) {
    password = p;
}

void Librarian::setShiftScheduled(const std::string& s) {
    shiftScheduled = s;
}