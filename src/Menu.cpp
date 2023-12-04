/* Menu.cpp
 * Description: This is the implementation for the Menu class. It contains the definitions for the Menu class.
 *              The Menu class uses the ManageLibrarian, ManageMember, ManageBook, and ManageOrder classes to create
 *              objects of those classes.The menue class starts by displaying a login menu, then takes user to either 
 *              the admin, librarian, or user menu depending on the user type.
 * Authors: Mark Ulicnik
 * Date Created: 12/1/2023 
*/
#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    //create hardcoded user with memberId = 1
    Member user;
    user.setMemberID(1);
    user.setName("user");
    user.setEmail("user@here.com");
    user.setPassword("123");
    user.setMembershipStatus("active");
    manageMember.addMember(user);

    //create hardcoded book with bookId = 1
    Book book;
    book.setBookId(1);
    book.setTitle("C++ For Dummies");
    book.setAuthor("Bjarne Stroustrup");
    book.setISBN("978-0-7645-7065-2");
    book.setPublicationDate(2004);
    book.setTotalCopies(1);
    book.setCopiesAvailable(1);
    book.setLanguage("English");
    book.setCondition("Good");
    book.setBookStatus("Available");
    manageBook.addBook(book);


    cout << "Welcome to Librarium-IO:" << endl;
    cout << "a CLI library management system" << endl;
    cout << "Please login to continue" << endl;
    showLoginMenu();
}

void Menu::showLoginMenu() {
    while (true) {
        cout << endl;
        cout << "Login Menu" << endl;
        cout << "Please enter your credentials" << endl
            << "Using primitive authentication for now" << endl << endl;

        cout << "Username(admin, librarian, user): ";
        cin >> username;
        cout << "Password(123 for all): ";
        cin >> password;
        cout << endl;
        if (username == "admin" && password == "123") {
            userType = "admin";
            showAdminMenu();
        } else if (username == "librarian" && password == "123") {
            userType = "librarian";
            showLibrarianMenu();
        } else if (username == "user" && password == "123") {
            userType = "user";
            userId = 1; //hardcoded userID, would link to memberId, username, password in the future
            showUserMenu();
        } else {
            cout << "Invalid credentials" << endl;
        }
    }
}

void Menu::showAdminMenu() {
    while (true) {
        cout << endl;
        int choice;
        cout << "Admin Menu: Manage Users" << endl;
        cout << "1. Users" << endl;
        cout << "2. Books" << endl;
        cout << "3. Logout" << endl;
        cout << "4. Exit (All Data Will Be Lost)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                showManageUsersMenu();
                break;
            case 2:
                showManageBooksMenu();
                break;
            case 3:
                showLoginMenu();
                break;
            case 4:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}

void Menu::showUserMenu() {
    while (true) {
        cout << endl;
        cout << "User Menu: View Books and my Orders" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Order Book" << endl;
        cout << "3. View my Orders" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. View my Info" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit (All Data Will Be Lost)" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        int bookId;
        switch (choice) {
            case 1:
                manageBook.viewAllBooks();
                break;
            case 2:
                cout << "Enter book id: " << endl;
                cin >> bookId;
                if(manageBook.checkOutBook(bookId)){
                    // hardcoded due date on 1/1/2024
                    manageOrder.orderBook(userId, bookId, Date(1, 1, 2024));
                    cout << "Book successfully ordered" << endl;
                } else {
                    cout << "Book not available" << endl;
                };
                break;
            case 3:
                manageOrder.viewOrdersByUser(userId);
                break;
            case 4:
                cout << "Enter book id: " << endl;
                cin >> bookId;
                if (manageOrder.returnBook(userId, bookId)){ //if the order was able to be found and returned, returnBook based on id
                    manageBook.returnBook(bookId);
                    cout << "Book successfully returned" << endl;
                } else {
                    cout << "Book not returned" << endl;
                };
                break;
            case 5:
                manageMember.viewMember(userId);
                cout << "Contact Admin to edit your info" << endl;
                break;
            case 6:
                showLoginMenu();
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        } 
        cout << endl;
    }
}

void Menu::showLibrarianMenu() {
    while (true) {
        cout << endl;
        cout << "Librarian Menu: View Books and Orders" << endl;
        cout << "1. View Books" << endl;
        cout << "2. View Orders" << endl;
        cout << "3. Add Book" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Edit Book" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit (All Data Will Be Lost)" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                manageBook.viewAllBooks();
                break;
            case 2:
                manageOrder.viewAllOrders();
                break;
            case 3:
                manageBook.addBook();
                break;
            case 4:
                int bookId;
                cout << "Enter book id: " << endl;
                cin >> bookId;
                manageBook.removeBook(bookId);
                break;
            case 5:
                cout << "Enter book id: " << endl;
                cin >> bookId;
                manageBook.editBook(bookId);
                break;
            case 6:
                showLoginMenu();
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }
}

/**********************************MANAGE USERS***********DONE****************************/
void Menu::showManageUsersMenu() {
    while (true) {
        cout << endl;
        int choice;
        cout << "Manage Users Menu" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Search User" << endl;
        cout << "3. View All Users" << endl;
        cout << "4. Edit User" << endl;
        cout << "5. Remove User" << endl;
        cout << "6. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        int id;
        cout << endl;
        switch (choice) {
            case 1:
                manageMember.addMember();
                break;
            case 2:
                cout << "Enter user id: " << endl;
                cin >> id;
                manageMember.viewMember(id);
                break;
            case 3:
                manageMember.viewAllMembers();
                break;
            case 4:
                cout << "Enter user id: " << endl;
                cin >> id;
                manageMember.editMember(id);
                break;
            case 5:
                cout << "Enter user id: " << endl;
                cin >> id;
                manageMember.removeMember(id);
                break;
            case 6:
                showAdminMenu();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }

}

/**********************************MANAGE BOOKS*********DONE******************************/
void Menu::showManageBooksMenu(){
    while (true) {
        int choice;
        cout << endl;
        cout << "Manage Books Menu" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. View All Books" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        int id;
        cout << endl;
        switch (choice) {
            case 1:
                manageBook.addBook();
                break;
            case 2:
                cout << "Enter book id: " << endl;
                cin >> id;
                manageBook.viewBook(id);
                break;
            case 3:
                manageBook.viewAllBooks();
                break;

            case 4:
                cout << "Enter book id: " << endl;
                cin >> id;
                manageBook.removeBook(id);
                break;

            case 5:
                //return user to admin menu if admin, librarian menu if librarian
                if (userType == "admin")
                    showAdminMenu();
                else if (userType == "librarian")
                    showLibrarianMenu();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        cout << endl;
    }
}

