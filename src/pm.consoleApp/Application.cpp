#include "Application.h"
#include "MainMenu.h"
#include "User.h"
#include "login.h"

void Application::run(nanodbc::connection& conn)
{
	Login login;
	pm::types::User user = login.getUserLogged(conn);

	std::cout << "Welcome " << user.firstName << "!" << std::endl;

	MainMenu mainMenu;
	mainMenu.displayMenu(conn);
}
