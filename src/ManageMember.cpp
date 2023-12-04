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

    id = members.size() + 1; // increments, so that each member has a unique id
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
    
    cout << "Member added successfully! New member id: "<< id << "\n";
    members.push_back(memb);
}

//preconfigured member
void ManageMember::addMember(const Member& memb){
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
            cout << "Which field would you like to change?\n";
            cout << "1. Name\n";
            cout << "2. Email\n";
            cout << "3. Password\n";
            cout << "4. Membership Status\n";
            cout << "5. None\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            string newInfo;
            switch (choice)
            {
            case 1:
                cout << "Enter new name:\n";
                getline(cin, newInfo);
                member.setName(newInfo);
                return;
                break;
            
            case 2:
                cout << "Enter new email:\n";
                cin >> newInfo;
                member.setEmail(newInfo);
                return;
                break;
            
            case 3:
                cout << "Enter new password:\n";
                cin >> newInfo;
                member.setPassword(newInfo);
                return;
                break;
            
            case 4:
                cout << "Enter new membership status:\n";
                cin >> newInfo;
                member.setMembershipStatus(newInfo);
                return;
                break;
            
            case 5:
                return;
                break;
            }
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

