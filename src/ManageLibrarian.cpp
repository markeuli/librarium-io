#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include "Librarian.h"

void ManageLibrarian::addLibrarian(const Librarian& librarian) {
    librarians.push_back(librarian);
}

void ManageLibrarian::removeLibrarian(int employeeId) {
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


/*int main() {
    ManageLibrarian manager;
    manager.addLibrarian(Librarian("John Doe", 1, "john@example.com", "password123", "Morning"));
    manager.addLibrarian(Librarian("Jane Smith", 2, "jane@example.com", "password456", "Evening"));

    manager.editLibrarian(1, "John Doe Jr.", "johnjr@example.com", "newpassword123", "Afternoon");
    manager.removeLibrarian(2);

    
    return 0;
}*/
