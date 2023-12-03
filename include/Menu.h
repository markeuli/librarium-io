#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Menu {

private:
    string userType =  "None";
    string username;
    string password;
public:
/*
    
*/  Menu();

    void showLoginMenu();
    void showAdminMenu();
    void showUserMenu();
    void showLibrarianMenu();
};