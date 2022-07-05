#include "TeamsManagement.h"

void pm::pl::TeamsManagement::displayAllteams(nanodbc::connection& conn,
	pm::types::User& user)
{

}

void pm::pl::TeamsManagement::displayTeamsView(nanodbc::connection& conn,
	pm::types::User& user)
{
	system("cls");
	std::cout << "Teams view!\n";
	std::cout << "1. Display all teams\n";
	std::cout << "2. Display teams of a user\n";
	std::cout << "3. Display teams of a project\n";
	std::cout << "4. Assign User\n";
	std::cout << "5. Unassign User\n";
	std::cout << "6. Back\n\nOption: ";

	unsigned short int option{};
	std::cin >> option;

	pm::pl::TeamsManagement::handleTeamsView(conn, user, option);
}

void pm::pl::TeamsManagement::displayTeamsManagement(
	nanodbc::connection& conn, pm::types::User user)
{
	system("cls");
	std::cout << "Teams management\n";
	std::cout << "1. Create team\n";
	std::cout << "2. Delete team\n";
	std::cout << "3. Manage teams\n";
	std::cout << "4. Back\n\nOption: ";

	unsigned short int option{};
	std::cin >> option;

	pm::pl::TeamsManagement::handleTeamsDisplay(conn, user, option);
}

unsigned short pm::pl::TeamsManagement::getTeamToDeleteId(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Enter team id to delete: ";
	unsigned short int option{};
	std::cin >> option;
	return option;
}

void pm::pl::TeamsManagement::userDeleted(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "User unassigned successfully!\n";
	std::cout << "\nGo back? (y/n)";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::pl::TeamsManagement::displayTeamsView(conn, user);
	}
	else
	{
		exit(0);
	}
}

void pm::pl::TeamsManagement::teamsForUserNotFound(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Teams for user not found!\n";
	std::cout << "\nTry again? (y/n)";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::TeamManager::displayTeamsOfUser(conn, user);
	}
	else
	{
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
	}
}

void pm::pl::TeamsManagement::teamsForProjectNotFound(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Teams for Project not found!\n";
	std::cout << "\nTry again? (y/n)";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::TeamManager::displayTeamsOfProject(conn, user);
	}
	else
	{
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
	}
}

void pm::pl::TeamsManagement::teamsDisplayed(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "\n\nGo Back? (y/n): ";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::pl::TeamsManagement::displayTeamsView(conn, user);
	}
	else
	{
		exit(0);
	}
}

void pm::pl::TeamsManagement::userAssignedToTeam(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "User assigned successfully!\n";
	std::cout << "View all teams? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::bll::TeamManager::displayAllteams(conn, user);
	}
	else
	{
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
	}
}

void pm::pl::TeamsManagement::teamDeletedSuccessfully(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Team deleted successfully!\n";
	std::cout << "Manage Teams? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::pl::TeamsManagement::displayTeamsView(conn, user);
	}
	else
	{
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
	}
}

void pm::pl::TeamsManagement::displayTeams(nanodbc::connection& connection, pm::types::User& user,
	std::vector<pm::types::Team>& teams)
{
	system("cls");
	tabulate::Table table;
	table.add_row({ "ID", "Team Name", "Created On",
		"Created By" , "Last Changed On", "Last Changed By" });
	for (const auto& element : teams)
	{
		char createdOn[26];
		char lastChange[26];
		ctime_s(createdOn, sizeof createdOn,
			&element.createdOn);
		ctime_s(lastChange, sizeof lastChange,
			&element.lastChange);

		table.add_row({
			std::to_string(element.id), element.title,
			createdOn, std::to_string(element.creatorId),
			lastChange, std::to_string(element.lastChangerId) });
	}
	for (size_t i = 0; i < 6; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}
	std::cout << table << std::endl;
}

void pm::pl::TeamsManagement::displayTeamCreatedMenu(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Team created successfully!\n";
	std::cout << "Manage Teams? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::pl::TeamsManagement::displayTeamsView(conn, user);
	}
	else
	{
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
	}
}

pm::types::Team pm::pl::TeamsManagement::getTeam(nanodbc::connection& conn,
	pm::types::User& user)
{
	std::cin.get();
	std::string title{};
	size_t creatorId{};
	creatorId = user.id;

	std::cout << "Please enter team title: ";
	getline(std::cin, title);

	pm::types::Team team{
		title, creatorId };
	return team;
}

void pm::pl::TeamsManagement::displayTeamsOfUser(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Display teams of a user\n";
	std::cout << "Users: \n";



	std::cout << "Please enter the user's id: ";
}

void pm::pl::TeamsManagement::displayTeamsOfProject(
	nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::pl::TeamsManagement::handleTeamsDisplay(
	nanodbc::connection& conn, pm::types::User& user,
	unsigned short int option)
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

void pm::pl::TeamsManagement::handleTeamsView(
	nanodbc::connection& conn, pm::types::User& user,
	unsigned short int option)
{
	switch (option)
	{
	case 1: // Display all teams
		pm::bll::TeamManager::displayAllteams(conn, user);
		break;
	case 2: // Display teams of a user
		pm::bll::TeamManager::displayTeamsOfUser(conn, user);
		break;
	case 3: // Display teams of a project
		pm::bll::TeamManager::displayTeamsOfProject(conn, user);
		break;
	case 4: // Assign Users
		pm::bll::TeamManager::assignUser(conn, user);
	case 5: // Unassign Users from team
		pm::bll::TeamManager::unassignUser(conn, user);
		break;
	case 6: // Back
		pm::pl::TeamsManagement::displayTeamsManagement(conn, user);
		break;
	}
}

int pm::pl::TeamsManagement::getUserId(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<types::User>& users)
{
	system("cls");
	pm::pl::AdminsManagement::displayUsers(
		conn, user, users);

	std::cout << "\n\nEnter user id: ";
	unsigned short int option{};
	std::cin >> option;
	return option;
}

int pm::pl::TeamsManagement::getTeamId(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<types::Team>& teams)
{
	system("cls");
	pm::pl::TeamsManagement::displayTeams(
		conn, user, teams);

	std::cout << "\n\nEnter team id: ";
	unsigned short int option{};
	std::cin >> option;
	return option;
}
