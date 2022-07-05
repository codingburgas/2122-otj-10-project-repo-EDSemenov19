#include "TasksManagement.h"

size_t pm::pl::TasksManagement::getTaskId(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	system("cls");
	pm::pl::TasksManagement::displayTasks(
		conn, user, tasks);

	std::cout << "\n\nEnter task id: ";
	size_t option{};
	std::cin >> option;
	return option;
}

void pm::pl::TasksManagement::taskDescriptionChanged(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Description changed successfully!\n";
	std::cout << "View Tasks? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::bll::TaskManager::displayAllTasks(conn, user);
	}
	else
	{
		pm::pl::TasksManagement::displayTasksManagement(conn, user);
	}
}

void pm::pl::TasksManagement::tasksForProjectNotFound(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Tasks for Project not found!\n";
	std::cout << "\nTry again? (y/n)";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::TaskManager::displayTasksOfProject(conn, user);
	}
	else
	{
		pm::pl::TasksManagement::displayTasksManagement(conn, user);
	}
}

void pm::pl::TasksManagement::taskUnassignedFromProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Task Unassigned successfully!\n";
	std::cout << "View Tasks Of Project? (y/n)\n";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::TaskManager::displayTasksOfProject(conn, user);
	}
	else
	{
		displayTasksManagement(conn, user);
	}
}

void pm::pl::TasksManagement::taskAssignedToProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Task Assigned successfully!\n";
	std::cout << "View Tasks Of Project? (y/n)\n";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::bll::TaskManager::displayTasksOfProject(conn, user);
	}
	else
	{
		displayTasksManagement(conn, user);
	}
}

void pm::pl::TasksManagement::displayTasks(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	system("cls");
	tabulate::Table table;
	table.add_row({ "ID", "Title", "Description",
		"Created On" , "Created By", "Last Changed On",
		"Last Changed By" });
	for (const auto& element : tasks)
	{
		char createdOn[26];
		char lastChange[26];
		ctime_s(createdOn, sizeof createdOn,
			&element.createdOn);
		ctime_s(lastChange, sizeof lastChange,
			&element.lastChange);

		table.add_row({
			std::to_string(element.id), element.title,
			element.description, createdOn,
			std::to_string(element.creatorId),
			lastChange, std::to_string(element.lastChangerId) });
	}
	for (size_t i = 0; i < 7; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}
	std::cout << table << std::endl;
}

void pm::pl::TasksManagement::taskTitleChanged(
	nanodbc::connection& conn, pm::types::User user)
{
	std::cout << "Title changed successfully!\n";
	std::cout << "View Tasks? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::bll::TaskManager::displayAllTasks(conn, user);
	}
	else
	{
		pm::pl::TasksManagement::displayTasksManagement(conn, user);
	}
}

void pm::pl::TasksManagement::taskCreated(
	nanodbc::connection& conn, pm::types::User user)
{
	std::cout << "Task created!" << std::endl;
	std::cout << "Go back? (y/n)\n";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		displayTasksManagement(conn, user);
	}
	else
	{
		exit(0);
	}
}

void pm::pl::TasksManagement::tasksDisplayed(
	nanodbc::connection& conn, pm::types::User user)
{
	std::cout << "Go back? (y/n)\n";
	std::cout << "Answer: ";
	char answer{};
	std::cin >> answer;
	if (answer == 'y')
	{
		displayTasksManagement(conn, user);
	}
	else
	{
		exit(0);
	}
}

std::string pm::pl::TasksManagement::getNewTaskTitle(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	system("cls");
	pm::pl::TasksManagement::displayTasks(conn, user, tasks);
	std::cout << "\nEnter new title: ";
	std::string newTitle{};
	std::cin.get();
	getline(std::cin, newTitle);
	return newTitle;
}

std::string pm::pl::TasksManagement::getNewDescription(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	system("cls");
	pm::pl::TasksManagement::displayTasks(conn, user, tasks);
	std::cout << "\nEnter new description: ";
	std::string newDescription{};
	std::cin.get();
	getline(std::cin, newDescription);
	return newDescription;
}

void pm::pl::TasksManagement::displayTasksManagement(
	nanodbc::connection& conn, pm::types::User user)
{
	system("cls");
	std::cout << "Tasks management\n";
	std::cout << "1. Create Task\n";
	std::cout << "2. Delete Task\n";
	std::cout << "3. Display All Tasks\n";
	std::cout << "4. Display Tasks of A Project\n";
	std::cout << "5. Edit task\n";
	std::cout << "6. Back\n\nOption: ";

	unsigned short int option{};
	std::cin >> option;

	handleTaskManagement(conn, user, option);
}

size_t pm::pl::TasksManagement::displayEditMenu(nanodbc::connection& conn,
	pm::types::User user)
{
	std::cout << std::endl;
	std::cout << "1. Edit Title\n";
	std::cout << "2. Edit Description\n";
	std::cout << "3. Assign Task to Project\n";
	std::cout << "4. Unassign Task from Project\n";
	std::cout << "5. Back\n\nOption: ";

	size_t option{};
	std::cin >> option;
	return option;
}

void pm::pl::TasksManagement::handleTaskManagement(
	nanodbc::connection& conn, pm::types::User user,
	unsigned short option)
{
	switch (option)
	{
	case 1:
		pm::bll::TaskManager::createTask(conn, user);
		break;
	case 2:
		pm::bll::TaskManager::deleteTask(conn, user);
		break;
	case 3:
		pm::bll::TaskManager::displayAllTasks(conn, user);
		break;
	case 4: pm::bll::TaskManager::displayTasksOfProject(conn, user);
		break;
	case 5:
		pm::bll::TaskManager::editTask(conn, user);
		break;
	case 6:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	}
}

void pm::pl::TasksManagement::taskDeleted(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "Task deleted successfully!\n";
	std::cout << "View Tasks? (y/n)\n";
	char answer{};
	std::cin >> answer;

	if (answer == 'y')
	{
		pm::bll::TaskManager::displayAllTasks(conn, user);
	}
	else
	{
		pm::pl::TasksManagement::displayTasksManagement(conn, user);
	}
}

pm::types::Task pm::pl::TasksManagement::getTask(
	nanodbc::connection& conn, pm::types::User user)
{
	std::string title{};
	std::string description{};
	size_t creatorId = user.id;
	size_t lastChangerId = user.id;

	std::cin.get();
	std::cout << "Create task!\n\n";
	std::cout << "Enter task title: ";
	getline(std::cin, title);
	std::cout << "\nEnter task description: ";
	getline(std::cin, description);

	pm::types::Task task(
		title, description, creatorId, lastChangerId
	);

	return task;
}
