#include "AdminsManagement.h"

void pm::pl::AdminsManagement::displayAdminsManagement(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "1. Add user" << '\n';
	std::cout << "2. Edit user" << '\n';
	std::cout << "3. Delete user" << '\n';
	std::cout << "4. View User Details" << '\n';
	std::cout << "5. Sort Users" << '\n';
	std::cout <<"6. Back" << '\n' << std::flush;

	std::cout << "Option: ";
	unsigned short int option{};
	std::cin >> option;
	
	pm::pl::AdminsManagement::handleAdminsManagement(conn, user, option);
}

void pm::pl::AdminsManagement::handleAdminsManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int& option)
{
	switch (option)
	{
	case 1:
		pm::bll::UserManager::registerNewUser(conn, user);
		break;
	case 2:
		//pm::dal::UserStore::update(conn, user);
		break;
	case 3:
		pm::dal::UserStore::deleteUser(conn, user);
		break;
	case 4:
		pm::bll::UserManager::viewUserDetails(conn, user);
		break;
	case 5:
		//pm::dal::UserStore::sort(conn, user);
		break;
	case 6:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		//std::cout << "Invalid option" << std::endl;
		break;
	}
}

void pm::pl::AdminsManagement::displayUser(nanodbc::connection& conn, pm::types::User& userToDisplay, std::vector<pm::types::User>& users)
{
	for (const auto& element : users)
	{
		std::cout << element.id << ' ' << element.firstName << ' ' << element.lastName;
	}
}

void pm::pl::AdminsManagement::userCreated(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "User created successfully!" << std::endl;
	std::cout << "Go back? (y/n)" << std::endl;
	char option;
	std::cin >> option;

	if (option == 'y')
	{
		system("cls");
		pm::pl::AdminsManagement::displayAdminsManagement(conn, user);
	}
	else
	{
		system("cls");
		exit(0);
	}
}

void pm::pl::AdminsManagement::logout(nanodbc::connection& conn, pm::types::User& user)
{
	std::cin.get();
	system("cls");
	pm::pl::Application app;
	app.run(conn);
}