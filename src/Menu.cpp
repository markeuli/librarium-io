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
    cout << "Admin Menu" << endl;
}

void Menu::showUserMenu() {
    cout << "User Menu" << endl;
}

void Menu::showLibrarianMenu() {
    cout << "Librarian Menu" << endl;
}

