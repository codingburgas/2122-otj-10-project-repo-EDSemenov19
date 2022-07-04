#include "ProjectsManagement.h"

void pm::pl::ProjectsManagement::displayProjectsManagement(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Projects management\n";
	std::cout << "1. Create Project\n";
	std::cout << "2. Delete Project\n";
	std::cout << "3. Manage Projects\n";
	std::cout << "4. Back\n";

	unsigned short int option{};
	std::cin >> option;
	handleProjectsManagement(conn, user, option);
}

void pm::pl::ProjectsManagement::handleProjectsManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int option)
{
	switch (option)
	{
	case 1:
		//createProject(conn, user);
		break;
	case 2:
		//deleteProject(conn, user);
		break;
	case 3:
		//manageProjects(conn, user);
		break;
	case 4:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		std::cout << "Invalid option\n";
		break;
	}
}
