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
    booksBorrowed = {};
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

//Return list of checked out books
std::vector<Book> Member::viewBorrowedBooks() const{
    return booksBorrowed;
}

//belongs in control class
void Member::checkOutBook(int bookID){
    //TODO: Figure out how we handle books
}

//belongs in control class
void Member::returnBook(int bookID){
    //TODO: Figure out how we handle books
}
