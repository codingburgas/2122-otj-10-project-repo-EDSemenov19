#include "TeamsManagement.h"

void pm::pl::TeamsManagement::displayAllteams(nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::pl::TeamsManagement::displayTeamsView(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Teams view!\n";
	std::cout << "1. Display all teams\n";
	std::cout << "2. Display teams of a user\n";
	std::cout << "3. Display teams of a project\n";
	std::cout << "4. Back\n";

	unsigned short int option{};
	std::cin >> option;

	pm::pl::TeamsManagement::handleTeamsView(conn, user, option);
}

void pm::pl::TeamsManagement::displayTeamsManagement(nanodbc::connection& conn, pm::types::User user)
{
	system("cls");
	std::cout << "Teams management\n";
	std::cout << "1. Create team\n";
	std::cout << "2. Delete team\n";
	std::cout << "3. Manage teams\n";
	std::cout << "4. Back\n";

	unsigned short int option{};
	std::cin >> option;

	pm::pl::TeamsManagement::handleTeamsDisplay(conn, user, option);
}

pm::types::Team pm::pl::TeamsManagement::getTeam()
{
	std::string title{};
	std::string description{};

	std::cout << "Please enter team title: ";
	getline(std::cin, title);
	std::cout << "\n Please enter team description: ";
	getline(std::cin, description);

	pm::types::Team team{ title, description };
	return team;
}

void pm::pl::TeamsManagement::displayTeamsOfUser(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Display teams of a user\n";
	std::cout << "Users: \n";



	std::cout << "Please enter the user's id: ";
}

void pm::pl::TeamsManagement::displayTeamsOfProject(nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::pl::TeamsManagement::handleTeamsDisplay(nanodbc::connection& conn, pm::types::User& user, unsigned short int option)
{
	switch (option)
	{
	case 1: pm::bll::TeamManager::createTeam(conn, user);
		break;
	case 2: pm::bll::TeamManager::deleteTeam(conn, user);
		break;
	case 3: pm::pl::TeamsManagement::displayTeamsView(conn, user);
		break;
	case 4: pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		exit(0);
		break;
	}
}

void pm::pl::TeamsManagement::handleTeamsView(nanodbc::connection& conn, pm::types::User& user,
	unsigned short int option)
{
	switch (option)
	{
	case 1: // Display all teams
		pm::pl::TeamsManagement::displayAllteams(conn, user);
		break;
	case 2: // Display teams of a user
		pm::pl::TeamsManagement::displayTeamsOfUser(conn, user);
		break;
	case 3: // Display teams of a project
		pm::pl::TeamsManagement::displayTeamsOfProject(conn, user);
		break;
	case 4: // Back
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
		break;
	}
}