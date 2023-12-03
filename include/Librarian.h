#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include <string>
#include <vector>


class Librarian {
private:
    std::string name;
    int employeeId;
    std::string email;
    std::string password;
    std::string shiftScheduled;

public:
    Librarian(std::string name, int employeeId, std::string email, std::string password, std::string shiftScheduled);

    std::string getName() const;
    int getEmployeeId() const;
    std::string getEmail() const;
    std::string getPassword() const;
    std::string getShiftScheduled() const;

    void setName(const std::string& n);
    void setEmployeeId(int id);
    void setEmail(const std::string& e);
    void setPassword(const std::string& p);
    void setShiftScheduled(const std::string& s);
};

class ManageLibrarian {
private:
    std::vector<Librarian> librarians;

public:
    void addLibrarian(const Librarian& librarian);
    void removeLibrarian(int employeeId);
    void editLibrarian(int employeeId, const std::string& newName, const std::string& newEmail, const std::string& newPassword, const std::string& newShiftScheduled);
};

#endif // LIBRARIAN_H