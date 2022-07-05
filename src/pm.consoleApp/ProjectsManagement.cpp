#include "ProjectsManagement.h"

void pm::pl::ProjectsManagement::displayProjectsMenu(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Projects management\n";
	std::cout << "1. Create Project\n";
	std::cout << "2. Delete Project\n";
	std::cout << "3. Manage Projects\n";
	std::cout << "4. Back\n\nOption: ";

	unsigned short int option{};
	std::cin >> option;
	handleProjectsMenu(conn, user, option);
}

pm::types::Project pm::pl::ProjectsManagement::getProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cin.get();
	std::string title{};
	std::string description{};
	size_t idOfCreator = user.id;
	size_t idOfLastChanger = user.id;

	std::cout << "Create project!\n";
	std::cout << "Enter title: ";
	getline(std::cin, title);
	std::cout << "\nEnter description: ";
	getline(std::cin, description);

	pm::types::Project project(
		title, description, idOfCreator, idOfLastChanger);

	return project;
}

void pm::pl::ProjectsManagement::projectCreated(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Project created successfully!\n";
	std::cout << "Manage Project? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::pl::ProjectsManagement::displayProjectsManagement(
			conn, user);
	}
	else
	{
		pm::pl::ProjectsManagement::displayProjectsMenu(conn, user);
	}
}

void pm::pl::ProjectsManagement::displayProjectsManagement(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Projects management!\n";

	std::cout << "1. Display all Projects\n";
	std::cout << "2. Edit Project Title\n";
	std::cout << "3. Edit Project Description\n";
	std::cout << "4. Assign Teams\n";
	std::cout << "5. Unassign Teams\n";
	std::cout << "6. Back\n\nOption: ";

	unsigned short int option{};
	std::cin >> option;
	pm::pl::ProjectsManagement::handleProjectsManagement(
		conn, user, option);
}

void pm::pl::ProjectsManagement::handleProjectsManagement(
	nanodbc::connection& conn, pm::types::User& user,
	unsigned short option)
{
	switch (option)
	{
	case 1: pm::bll::ProjectManager::displayAllProjects(conn, user);
		break;
	case 2: pm::bll::ProjectManager::editProjectTitle(conn, user);
		break;
	case 3: pm::bll::ProjectManager::editProjectDescription(conn, user);
		break;
	case 4: pm::bll::ProjectManager::assignTeam(conn, user);
		break;
	case 5: pm::bll::ProjectManager::unassignTeam(conn, user);
		break;
	case 6: displayProjectsMenu(conn, user);
		break;
	default: std::cerr << "Invalid input!" << std::endl;
	}
}

void pm::pl::ProjectsManagement::handleProjectsMenu(
	nanodbc::connection& conn, pm::types::User& user,
	unsigned short int option)
{
	switch (option)
	{
	case 1:
		pm::bll::ProjectManager::createProject(conn, user);
		break;
	case 2:
		pm::bll::ProjectManager::deleteProject(conn, user);
		break;
	case 3:
		displayProjectsManagement(conn, user);
		break;
	case 4:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		std::cout << "Invalid option\n";
		break;
	}
}

void pm::pl::ProjectsManagement::displayProjects(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Project>& projects)
{
	system("cls");
	tabulate::Table table;
	table.add_row({ "ID", "Title", "Description",
		"Created On" , "Created By", "Last Changed On",
		"Last Changed By" });
	for (const auto& element : projects)
	{
		char createdOn[26];
		char lastChange[26];
		ctime_s(createdOn, sizeof createdOn,
			&element.createdOn);
		ctime_s(lastChange, sizeof lastChange,
			&element.lastChanged);

		table.add_row({
			std::to_string(element.id), element.title,
			element.description, createdOn,
			std::to_string(element.idOfCreator), lastChange,
			std::to_string(element.idOfLastChanger) });
	}
	for (size_t i = 0; i < 7; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}
	std::cout << table << std::endl;
}

size_t pm::pl::ProjectsManagement::getProjectId(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "\nEnter project ID: ";
	size_t id{};
	std::cin >> id;
	return id;
}

std::string pm::pl::ProjectsManagement::getProjectDescription(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cin.get();
	std::string description{};
	std::cout<<"\nEnter the new description: ";
	getline(std::cin, description);
	return description;
}

std::string pm::pl::ProjectsManagement::getProjectTitle(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cin.get();
	std::string description{};
	std::cout << "\nEnter the new title: ";
	getline(std::cin, description);
	return description;
}

void pm::pl::ProjectsManagement::projectDeleted(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Project deleted successfully!\n";
	std::cout << "View All Projects? (y/n)\n";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::ProjectManager::displayAllProjects(conn, user);
	}
	else
	{
		displayProjectsManagement(conn, user);
	}
}

void pm::pl::ProjectsManagement::projectTitleChanged(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Title updated successfully!\n";
	std::cout << "View All Projects? (y/n)\n";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::ProjectManager::displayAllProjects(conn, user);
	}
	else
	{
		displayProjectsManagement(conn, user);
	}
}

void pm::pl::ProjectsManagement::projectDescriptionChanged(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout<<"Description updated successfully!\n";
	std::cout<<"View All Projects? (y/n)\n";
	char answer{};
	std::cin>>answer;
	if (answer == 'y')
	{
		pm::bll::ProjectManager::displayAllProjects(conn, user);
	}
	else
	{
		displayProjectsManagement(conn, user);
	}
}

void pm::pl::ProjectsManagement::projectsDisplayed(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Go back? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		displayProjectsManagement(conn, user);
	}
	else
	{
		displayProjectsMenu(conn, user);
	}
}
