#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Member.h"


class ManageMember: public Member{
    private:
        int id;
        std::string name;
        std::string email;
        std::string password;
        std::string membershipStatus;
        std::list<Member> members;

    public:
        //Add a member
        void addMember(){
            Member memb;
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
                        
            //members.push_back(memb);
        }

        void removeMember(int memberID){
            
        }

        void editMember(int id){
            
        }
}