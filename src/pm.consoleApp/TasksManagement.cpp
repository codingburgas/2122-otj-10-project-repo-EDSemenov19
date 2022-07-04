#include "TasksManagement.h"

void pm::pl::TasksManagement::displayTasksManagement(nanodbc::connection& conn, pm::types::User user)
{
	system("cls");
	std::cout << "Tasks management\n";
	std::cout << "1. Create Task\n";
	std::cout << "2. Delete Task\n";
	std::cout << "3. Edit task\n";
	std::cout << "4. Back\n";

	unsigned short int option{};
	std::cin >> option;

	handleTaskManagement(conn, user, option);
}

void pm::pl::TasksManagement::handleTaskManagement(nanodbc::connection& conn, pm::types::User user,
	unsigned short option)
{
	switch (option)
	{
	case 1:
		//createTask(conn, user);
		break;
	case 2:
		//deleteTask(conn, user);
		break;
	case 3: 
		//editTask(conn, user);
		break;
	case 4:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	}
}
