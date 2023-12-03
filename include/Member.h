#ifndef MEMBER_H
#define MEMBER_H

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
    
    public:
        Member();
        //copy constructor
        Member(const Member& memb);
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
};

class ManageMember{
    private:
        std::vector<Member> members;

    public:
        void addMember();
        void addMember(const Member& memb);
        void removeMember(int memberID);
        void editMember(int id);
        void viewMember(int id);
        void viewAllMembers();
};

#endif