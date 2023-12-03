#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include "Member.h"


 
void ManageMember::addMember(){
    Member memb;
    int id;
    std::string name;
    std::string email;
    std::string password;
    std::string membershipStatus;

    cout << "Enter member ID:\n";
    cin >> id; 
    memb.setMemberID(id);
    cout << "Enter member name:\n";
    getline(cin, name);
    memb.setName(name);
    cout << "Enter member email:\n";
    cin >> email;
    memb.setEmail(email);
    cout << "Enter member password:\n";
    cin >> password;
    memb.setPassword(password);
    cout << "Enter member membeship status:\n";
    cin >> membershipStatus;
    memb.setMembershipStatus(membershipStatus);
                
    members.push_back(memb);
}

void ManageMember::removeMember(int memberID){
    for (auto& member : members) {
        if (member.getMemberID() == memberID) {
            members.erase(remove_if(members.begin(), members.end(),
                            [memberID](const Member& m) {
                                return m.getMemberID() == memberID; 
                            }),
                            members.end());
        }
    }
}

void ManageMember::editMember(int id){
    for (auto& member : members) {
        if (member.getMemberID() == id) {
            
        }
    }
}

void ManageMember::viewMember(int id){
    for (auto& member : members) {
        if (member.getMemberID() == id) {
            std::cout << "Member ID: " << member.getMemberID() << std::endl;
            std::cout << "Member Name: " << member.getName() << std::endl;
            std::cout << "Member Email: " << member.getEmail() << std::endl;
            std::cout << "Member Password: " << member.getPassword() << std::endl;
            std::cout << "Member Membership Status: " << member.getMembershipStatus() << std::endl << std::endl;
        }
    }
}

void ManageMember::viewAllMembers(){
    for (auto& member : members) {
        std::cout << "Member ID: " << member.getMemberID() << std::endl;
        std::cout << "Member Name: " << member.getName() << std::endl;
        std::cout << "Member Email: " << member.getEmail() << std::endl;
        std::cout << "Member Password: " << member.getPassword() << std::endl;
        std::cout << "Member Membership Status: " << member.getMembershipStatus() << std::endl << std::endl;
    }
}

//belongs in control class
void ManageMember::checkOutBook(int bookID, int memberID){
    //TODO: Figure out how we handle books
}

//belongs in control class
void ManageMember::returnBook(int bookID, int memberID){
    //TODO: Figure out how we handle books
}