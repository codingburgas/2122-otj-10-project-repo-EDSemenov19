#include "MainMenu.h"
#include "User.h"
#include "AdminsManagement.h"
#include "TeamsManagement.h"
#include "ProjectsManagement.h"
#include "TasksManagement.h"
#include <conio.h>
#include <algorithm>
#include <iostream>

void* pm::pl::MainMenu::handleOption1(void*)
{
	return nullptr;
}

void pm::pl::MainMenu::displayMenu(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Main menu! " << std::endl;

	std::cin.get();
}

void pm::pl::MainMenu::displayAdminMenu(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Admin menu! " << std::endl;
	std::cout << "Welcome " << user.firstName << " " << user.lastName << '!' << std::endl;
	std::cout << "1. Users management!" << std::endl;
	std::cout << "2. Teams management!" << std::endl;
	std::cout << "3. Projects management!" << std::endl;
	std::cout << "4. Tasks management!" << std::endl;
	std::cout << "5. Logout!" << std::endl;
	std::cout << "6. Exit!" << std::endl;

	std::cout << "Option: ";
	unsigned short int option{};
	std::cin >> option;

	handle(conn, user, option);
}

void pm::pl::MainMenu::displayUserMenu(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "User menu! " << std::endl;
	std::cout << "Welcome " << user.firstName << " " << user.lastName << '!' << std::endl;
	std::cin.get();
}

void pm::pl::MainMenu::handle(nanodbc::connection& conn, pm::types::User& user, unsigned short int option)
{
	switch (option)
	{
	case 1:
		AdminsManagement::displayAdminPanel(conn, user);
		break;
	case 2:
		TeamsManagement::displayTeamsManagement(conn, user);
		break;
	case 3:
		ProjectsManagement::displayProjectsManagement(conn, user);
		break;
	case 4:
		TasksManagement::displayTasksManagement(conn, user);
		break;
	case 5:
		AdminsManagement::logout(conn, user);
		break;
	case 6:
		exit(0);
		break;
	default:
		std::cout << "Invalid option!" << std::endl;
		break;
	}

}


void pm::pl::initAndShowMainMenu(nanodbc::connection& conn)
{
	pm::pl::MainMenu mainMenu;

	//mainMenu.items.push_back({ '1', "Item1",   });
	mainMenu.items.push_back({ '2', "Item2", nullptr });
	mainMenu.items.push_back({ '3', "Item3", nullptr });

	//mainMenu.handle(conn);
}
