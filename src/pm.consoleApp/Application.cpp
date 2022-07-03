#include "Application.h"
#include "MainMenu.h"
#include "User.h"
#include "login.h"

void Application::run(nanodbc::connection& conn)
{
	Login login;
	pm::types::User user = login.getUserLogged(conn);
	
	if(user.isAdmin)
	{
		MainMenu::displayAdminMenu(conn, user);
	}
	else
	{
		MainMenu::displayUserMenu(conn, user);
	}
	
	//mainMenu.displayMenu(conn, user);
}
