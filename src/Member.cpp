/* Member.cpp
 * Description: Member class is an entity class that holds information about a member, including their name, email, 
 *              password, and membership status. ManageMember class is made to manage these. A copy constructor is
 *             also implemented to initialize new members.
 * 
 * Authors: Lourdes Lola Renteria, Mark Ulicnik, Sadaf Khan
 * Date Created: 12/1/2023 
*/

#include <string>
#include <vector>
#include "Book.h"
#include "Order.h"
#include "Member.h"
#include <iostream>

Member::Member() {
    memberId = 0;
    name = "";
    email = "";
    password = "";
    membershipStatus = "";
}

//copy constructor
Member::Member(const Member& memb){
    memberId = memb.memberId;
    name = memb.name;
    email = memb.email;
    password = memb.password;
    membershipStatus = memb.membershipStatus;
}

void Member::setMemberID(int ID) {
    memberId = ID;
}

void Member::setName(std::string n) {
    name = n;
}

void Member::setEmail(std::string e) {
    email = e;
}

void Member::setPassword(std::string p) {
    password = p;
}

void Member::setMembershipStatus(std::string status) {
    membershipStatus = status;
}

int Member::getMemberID() const{
    return memberId;
}

std::string Member::getName() const{
    return name;
}

std::string Member::getEmail() const{
    return email;
}

std::string Member::getPassword() const{
    return password;
}

std::string Member::getMembershipStatus() const{
    return membershipStatus;
}




