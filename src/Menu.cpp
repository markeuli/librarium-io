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

    cout << "Welcome to Librarium-IO:" << endl;
    cout << "a CLI library management system" << endl;
    cout << "Please login to continue" << endl;
    showLoginMenu();
}

void Menu::showLoginMenu() {
    while (true) {
        cout << "Login Menu" << endl;
        cout << "Please enter your credentials" << endl
            << "Using primitive authentication for now" << endl << endl;

        cout << "Username(admin, librarian, user): ";
        cin >> username;
        cout << "Password(123 for all): ";
        cin >> password;
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
            showLoginMenu();
        }
    }
}

void Menu::showAdminMenu() {
    while (true) {
        int choice;
        cout << "Admin Menu: Manage Users" << endl;
        cout << "1. Users" << endl;
        cout << "2. Books" << endl;
        cout << "3. Logout" << endl;
        cout << "4. Exit (All Data Will Be Lost)" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
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
                showAdminMenu();
                break;
        }
    }
}

void Menu::showUserMenu() {
    while (true) {
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
                cout << "Enter book id: " << endl;;
                cin >> bookId;
                if (manageOrder.returnBook(userId, bookId)){
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
                showUserMenu();
                break;
        } 
    }
}

void Menu::showLibrarianMenu() {
    while (true) {
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
                showLibrarianMenu();
                break;
        }
    }
}

/**********************************MANAGE USERS***********DONE****************************/
void Menu::showManageUsersMenu() {
    while (true) {
        int choice;
        cout << "Manage Users Menu" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Search User" << endl;
        cout << "3. View All Users" << endl;
        cout << "4. Edit User" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        int id;
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
                showAdminMenu();
                break;
            default:
                cout << "Invalid choice" << endl;
                showManageUsersMenu();
                break;
        }
    }

}

/**********************************MANAGE BOOKS*********DONE******************************/
void Menu::showManageBooksMenu(){
    while (true) {
        int choice;
        cout << "Manage Books Menu" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. View All Books" << endl;
        cout << "4. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        int id;
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
                if (userType == "admin")
                    showAdminMenu();
                else if (userType == "librarian")
                    showLibrarianMenu();
                break;
            default:
                cout << "Invalid choice" << endl;
                showManageBooksMenu();
                break;
        }
    }
}

