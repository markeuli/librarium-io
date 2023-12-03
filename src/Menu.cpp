#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    cout << "Welcome to Librarium-IO:" << endl;
    cout << "a CLI library management system" << endl;
    cout << "Please login to continue" << endl;
    showLoginMenu();
}

void Menu::showLoginMenu() {
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
        showUserMenu();
    } else {
        cout << "Invalid credentials" << endl;
        showLoginMenu();
    }
}

void Menu::showAdminMenu() {
    int choice;
    cout << "Admin Menu: Manage Users" << endl;
    cout << "1. Users" << endl;
    cout << "2. Books" << endl;
    cout << "3. Logout" << endl;
    cout << "4. Exit" << endl;
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
            break;
        default:
            cout << "Invalid choice" << endl;
            showAdminMenu();
            break;
    }
}

void Menu::showUserMenu() {
    cout << "User Menu: View Books and my Orders" << endl;

}

void Menu::showLibrarianMenu() {
    cout << "Librarian Menu" << endl;
}

/**********************************MANAGE USERS*******************************************/
void Menu::showManageUsersMenu() {
    int choice;
    cout << "Manage Users Menu" << endl;
    cout << "1. Add User" << endl;
    cout << "2. Search User" << endl;
    cout << "3. View All Users" << endl;
    cout << "4. Back" << endl;
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
            //showAdminMenu();
            break;
        default:
            cout << "Invalid choice" << endl;
            //showManageUsersMenu();
            break;
    }

}

/**********************************MANAGE BOOKS*******************************************/
void Menu::showManageBooksMenu(){
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
            //addBook();
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
/* This is going to be the edit member for the Admin, ask for member id, edit or remove, ask for new info, call ManageMember::editMember(id, option, newInfo)
for (auto& memb : members) {
        if (member.getMemberID() == id) {
            member = memb;
        }
int choice;
            std::cout << "What would you like to edit?\n";
            std::cout << "1. Name\n";
            std::cout << "2. Email\n";
            std::cout << "3. Password\n";
            std::cout << "4. Membership Status\n";
            std::cin >> choice;
            std::string name, email, password, membershipStatus;
            switch (choice) {
                case 1:
                    std::cout << "Enter new name:\n";
                    std::cin >> name;
                    member.setName(name);
                    break;
                case 2:
                    std::cout << "Enter new email:\n";
                    std::cin >> email;
                    member.setEmail(email);
                    break;
                case 3:
                    std::cout << "Enter new password:\n";
                    std::cin >> password;
                    member.setPassword(password);
                    break;
                case 4:
                    std::cout << "Enter new membership status:\n";
                    std::cin >> membershipStatus;
                    member.setMembershipStatus(membershipStatus);
                    break;
                default:
                    std::cout << "Invalid choice\n";
                    break;
            }
*/

