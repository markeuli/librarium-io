#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "Book.h"

using namespace std;

class Member{
	private:
    	int memberID;
        std::string name;
        std::string email;
        std::string password;
        std::string membershipStatus;
        std::list<Book> checkedOutBooks;
        
	public:
        //Constructor
        Member(int id, std::string n, std::string e, std::string p, std::string status){}
        //Setter methods
        void setMemberID(int ID){
        	memberID = ID;
        }
        
        void setName(std::string n){
        	name = n;
        }
        
        void setEmail(std::string e){
        	email = e;
        }
        
        void setPassword(std::string p){
        	password = p;
        }
        
        void setMembershipStatus(std::string status){
        	membershipStatus = status;
        }
        
        //Getter methods
        int getMemberID(){
        	return memberID;
        }
        
        std::string getName(){
        	return name;
        }
        
        std::string getEmail(){
        	return email;
        }
        
        std::string getPassword(){
        	return password;
        }
        
        std::string getMembershipStatus(){
        	return membershipStatus;
        }
        
        /*
        //Members book list methods

        //Return list of checked out books
        void getCheckedOutBooks(){
            
        }
        //Add a book to checked out list
        void setCheckedOutBooks(std::list<Book> book){
            checkedOutBooks.push_back(book);
        }

        //remove a book from checked out list
        void checkOutBook(Book book){
            if(book.getCopiesAvailable.size() > 0){
                Order.generate();
                book.updateStatus();
                setCheckedoutBooks(book);
            }else{
                cout << "Book is unavailable to checkout.";
            }
        }

        void returnBook(Book book){
            checkedOutBooks.remove(book);
            book.updateStatus();
        }*/
};