#include <iostream>
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "pm.consoleApp.h"
#include <iomanip>
#include <ios>
#include "Application.h"

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

void listRegisteredUsers()
{
    auto users = userManager.getRegisteredUsers();
    std::cout << "-----\n";
    for (auto user : users)
    {
        std::cout << user.id << " " << user.firstName 
            << " " << user.lastName << " " << user.email 
            << " " << std::hex << user.passwordHash << std::endl;
    }
}

int main()
{
    Application app;

    app.run();

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
