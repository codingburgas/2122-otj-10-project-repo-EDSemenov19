#include "UsersManagement.h"

void displayUsersManagement(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "1. Add user" << std::endl;
	std::cout << "2. Edit user" << std::endl;
	std::cout << "3. Delete user" << std::endl;
	std::cout << "4. View User" << std::endl;
	std::cout << "5. Sort Users" << std::endl;
	std::cout <<"6. Back" << std::endl;

	std::cout << "Option: ";
	unsigned short int option{};
	std::cin >> option;

	handleUsersManagement(conn, user, option);
}

void handleUsersManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short& option)
{
	switch (option)
	{
	case 1:
		pm::dal::UserStore::create(conn, user);
		break;
	case 2:
		//pm::dal::UserStore::update(conn, user);
		break;
	case 3:
		//pm::dal::UserStore::remove(conn, user);
		break;
	case 4:
		//pm::dal::UserStore::getAllElements(conn, user);
		break;
	case 5:
		//pm::dal::UserStore::sort(conn, user);
		break;
	case 6:
		MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		//std::cout << "Invalid option" << std::endl;
		break;
	}
}
