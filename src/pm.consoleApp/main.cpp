#include <iostream>
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "pm.consoleApp.h"
#include <iomanip>
#include <ios>
#include "Application.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "login.h"

pm::bll::UserManager userManager;

void registerUser()
{
    std::string firstName, lastName, email, password;
    int age;

    std::cout << "First name: ";
    std::cin >> firstName;

    std::cout << "Last name: ";
    std::cin >> lastName;

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Email: ";
    std::cin >> email;

    std::cout << "Password: ";
    std::cin >> password;

    userManager.registerUser(firstName, lastName, age, email, password);
}

/*void listRegisteredUsers()
{
    auto users = userManager.getRegisteredUsers();
    std::cout << "-----\n";
    for (auto user : users)
    {
       std::cout << user.id << " " << user.firstName 
            << " " << user.lastName << " " << user.email 
            << " " << std::hex << user.passwordHash << std::endl;
    }
}*/

int main() try
{
   Application app;
   const std::string connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=PCBURGAS;Database=PMDB;Trusted_Connection=yes;"); // an ODBC connection string to your database
	nanodbc::connection conn(connstr);

   // std::cout << "Connection successful. Driver name: " << conn.driver_name() << std::endl;
   // std::cin.get();

   app.run(conn);


    //registerUser();

   /* userManager.seedDatabase();
    auto users = userManager.getRegisteredUsers();

    listRegisteredUsers();

    users[1].firstName = "Foo";

    userManager.updateUser(users[1]);
    
    //userManager.removeUser(2);

    listRegisteredUsers();
    */

}

catch (std::exception const& e)
{
	std::cerr << "Error: " << e.what() << std::endl;
}

catch (...)
{
	std::cerr << "Unknown error" << std::endl;
}