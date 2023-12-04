/* ManageLibrarian.cpp
 * Description: Designed to add, remove and edit librarians. More functionality could be added here, such as
 *              searching for a librarian by name or employee ID. Currently, the program only uses one librarian
 *             for testing purposes, which works because librarians can all do the same things regardless of 
 *             their specific identification numbers. 
 * 
 * Authors: Mark Ulicnik
 * Date Created: 12/1/2023 
*/

#include "Librarian.h"

void ManageLibrarian::addLibrarian(const Librarian& librarian) {
    librarians.push_back(librarian);
}

void ManageLibrarian::removeLibrarian(int employeeId) {
    //erase-remove pattern used with vectors to remove a specific element
    librarians.erase(remove_if(librarians.begin(), librarians.end(),
                                    [employeeId](const Librarian& l) { return l.getEmployeeId() == employeeId; }),
    librarians.end());
}

void ManageLibrarian::editLibrarian(int employeeId, const std::string& newName, const std::string& newEmail, const std::string& newPassword, const std::string& newShiftScheduled) {
    for (auto& librarian : librarians) {
        if (librarian.getEmployeeId() == employeeId) {
            librarian.setName(newName);
            librarian.setEmail(newEmail);
            librarian.setPassword(newPassword);
            librarian.setShiftScheduled(newShiftScheduled);
        }
    }
}