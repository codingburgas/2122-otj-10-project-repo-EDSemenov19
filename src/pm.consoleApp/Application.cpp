#include "Application.h"
#include "MainMenu.h"
#include "User.h"

void Application::run(nanodbc::connection& conn)
{
	

	MainMenu mainMenu;
	mainMenu.displayMenu(conn);
}
