#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include "Member.h"


class ManageMember: public Member{
    private:
        int id;
        std::string name;
        std::string email;
        std::string password;
        std::string membershipStatus;
        std::vector<Member> members;

    public:
        //Add a member
        void addMember(){
            cout << "Enter member ID:\n";
            cin >> id; 
            cout << "Enter member name:\n";
            getline(cin, name);
            cout << "Enter member email:\n";
            cin >> email;
            cout << "Enter member password:\n";
            cin >> password;
            cout << "Enter member membeship status:\n";
            cin >> membershipStatus;

            //New member is added to end of members vector
            members.push_back(Member(id, name, email, password, membershipStatus));
            
        }

        void removeMember(int memberID){
            //iterator to go through vector
            std::vector<Member>::iterator it;
            //sets iterator to position of searched element if found, else returns position past last elemt of vector
            it = std::find(members.begin(), members.end(),memberID);
            if(it == members.end()){
                cout << "No member with" <<memberID<< "found.\n";
            }
            
            //Erase-Remove Idiom: remove moves elements not matching memberID to front of vector range & erase deletes the end element because it matches the memberID
            members.erase(std::remove(members.begin(), members.end(), memberID), members.end());

            cout <<"Member "<<memberID<<"was removed.\n";
        }

        //still working on this method
        void editMember(int id){
            //iterator to go through vector
            std::vector<Member>::iterator it;
            //sets iterator to position of searched element if found, else returns position past last elemt of vector
            it = std::find(members.begin(), members.end(),id);

            //add Switch so user can select what to edit
            //add setter after every input
            cout << "Enter member name:\n";
            getline(cin, name);
            cout << "Enter member email:\n";
            cin >> email;
            cout << "Enter member password:\n";
            cin >> password;
            cout << "Enter member membeship status:\n";
            cin >> membershipStatus;
        }
};