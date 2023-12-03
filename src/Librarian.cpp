#include <string>
#include <iostream>

class Librarian {
private:
    std::string name;
    int employeeId;
    std::string email;
    std::string password;
    std::string shiftScheduled; // Assuming the date is stored as a string for simplicity

public:
    // Constructor
    Librarian(std::string name, int employeeId, std::string email, std::string password, std::string shiftScheduled)
        : name(name), employeeId(employeeId), email(email), password(password), shiftScheduled(shiftScheduled) {}

    // Getters
    std::string getName() const {
        return name;
    }

    int getEmployeeId() const {
        return employeeId;
    }

    std::string getEmail() const {
        return email;
    }

    std::string getPassword() const {
        return password;
    }

    std::string getShiftScheduled() const {
        return shiftScheduled;
    }

    // Setters
    void setName(const std::string& n) {
        name = n;
    }

    void setEmployeeId(int id) {
        employeeId = id;
    }

    void setEmail(const std::string& e) {
        email = e;
    }

    void setPassword(const std::string& p) {
        password = p;
    }

    void setShiftScheduled(const std::string& s) {
        shiftScheduled = s;
    }
};

int main() {
    // Example usage
    Librarian librarian("John Doe", 123, "johndoe@example.com", "password123", "2023-11-28");

    std::cout << "Librarian Name: " << librarian.getName() << std::endl;
    std::cout << "Employee ID: " << librarian.getEmployeeId() << std::endl;

    // Update Librarian's email
    librarian.setEmail("newemail@example.com");
    std::cout << "Updated Email: " << librarian.getEmail() << std::endl;

    return 0;
}
