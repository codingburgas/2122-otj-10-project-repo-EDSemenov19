#include "Application.h"
#include "MainMenu.h"
#include "User.h"
#include "login.h"

void pm::pl::Application::run(nanodbc::connection& conn)
{
	pm::pl::Login login;
	pm::types::User user = login.getUserLogged(conn);
	
	if(user.isAdmin)
	{
		pm::pl::MainMenu::displayAdminMenu(conn, user);
	}
	else
	{
		pm::pl::MainMenu::displayUserMenu(conn, user);
	}
	
	//mainMenu.displayMenu(conn, user);
}
