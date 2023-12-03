#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "Book.h"

using namespace std;

class Member{
    
    private:
        int memberId;
        std::string name;
        std::string email;
        std::string password;
        std::string membershipStatus;
        std::vector<Book> booksBorrowed;
    
    public:
        Member();
        std::string getName() const;
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getMembershipStatus() const;
        void setName(std::string name);
        void setEmail(std::string email);
        void setPassword(std::string password);
        void setMembershipStatus(std::string membershipStatus);
        int getMemberID() const;
        void setMemberID(int id);
        void checkOutBook(int bookID);
        void returnBook(int bookID);
        std::vector<Book> viewBorrowedBooks() const;

};