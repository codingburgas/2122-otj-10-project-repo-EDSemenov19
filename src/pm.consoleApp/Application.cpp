#include "Application.h"
#include "MainMenu.h"
#include "User.h"
#include "login.h"

void Application::run(nanodbc::connection& conn)
{
	Login login;
	MainMenu mainMenu;
	pm::types::User user = login.getUserLogged(conn);
	
	if(user.isAdmin)
	{
		mainMenu.displayAdminMenu(conn, user);
	}
	else
	{
		mainMenu.displayUserMenu(conn, user);
	}
	
	//mainMenu.displayMenu(conn, user);
}
