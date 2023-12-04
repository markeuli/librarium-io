/* Menu.h
 * Description: This is the header for the Menu class. It contains the declarations for the Menu class 
 *          and its methods. Menu class imports the Date, Member, Book, Librarian, and Order classes, 
 *          and uses them to create objects of those classes. The Menu class also uses the ManageLibrarian,
 *          ManageMember, ManageBook, and ManageOrder classes to create objects of those classes.
 * Authors: Mark Ulicnik, Sadaf Khan
 * Date Created: 12/2/2023 
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Member.h"
#include "Book.h"
#include "Librarian.h"
#include "Order.h"


using namespace std;

class Menu {

private:
    string userType =  "None";
    string username;
    string password;
    ManageLibrarian manageLibrarian;
    ManageMember manageMember;
    ManageOrder manageOrder;
    ManageBook manageBook;
    int userId;
    //ManageAdmin manageAdmin; TODO: Implement this class
    
public:
/*
    
*/  Menu();

    void showLoginMenu();
    void showAdminMenu();
    void showUserMenu();
    void showLibrarianMenu();
    void showManageUsersMenu();
    void showManageBooksMenu();

};