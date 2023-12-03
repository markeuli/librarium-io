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
    void showManageOrdersMenu();

};