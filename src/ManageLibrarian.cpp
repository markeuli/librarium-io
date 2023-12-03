#include <iostream>
#include <vector>
#include <string>

// Librarian class
class Librarian {
private:
    std::string name;
    int employeeId;
    std::string email;
    std::string password;
    std::string shiftScheduled;

public:
    Librarian(std::string name, int employeeId, std::string email, std::string password, std::string shiftScheduled)
        : name(name), employeeId(employeeId), email(email), password(password), shiftScheduled(shiftScheduled) {}

    std::string getName() const { return name; }
    int getEmployeeId() const { return employeeId; }
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    std::string getShiftScheduled() const { return shiftScheduled; }

    void setName(const std::string& n) { name = n; }
    void setEmployeeId(int id) { employeeId = id; }
    void setEmail(const std::string& e) { email = e; }
    void setPassword(const std::string& p) { password = p; }
    void setShiftScheduled(const std::string& s) { shiftScheduled = s; }
};

// ManageLibrarian class
class ManageLibrarian {
private:
    std::vector<Librarian> librarians;

public:
    void addLibrarian(const Librarian& librarian) {
        librarians.push_back(librarian);
    }

    void removeLibrarian(int employeeId) {
        librarians.erase(std::remove_if(librarians.begin(), librarians.end(),
                                        [employeeId](const Librarian& l) { return l.getEmployeeId() == employeeId; }),
                         librarians.end());
    }

    void editLibrarian(int employeeId, const std::string& newName, const std::string& newEmail, const std::string& newPassword, const std::string& newShiftScheduled) {
        for (auto& librarian : librarians) {
            if (librarian.getEmployeeId() == employeeId) {
                librarian.setName(newName);
                librarian.setEmail(newEmail);
                librarian.setPassword(newPassword);
                librarian.setShiftScheduled(newShiftScheduled);
            }
        }
    }
};

int main() {
    ManageLibrarian manager;
    manager.addLibrarian(Librarian("John Doe", 1, "john@example.com", "password123", "Morning"));
    manager.addLibrarian(Librarian("Jane Smith", 2, "jane@example.com", "password456", "Evening"));

    manager.editLibrarian(1, "John Doe Jr.", "johnjr@example.com", "newpassword123", "Afternoon");
    manager.removeLibrarian(2);

    
    return 0;
}
