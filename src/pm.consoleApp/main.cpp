#include <iostream>
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "pm.consoleApp.h"
#include <iomanip>
#include <ios>
#include "Application.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "login.h"

pm::bll::UserManager userManager;

/*void listRegisteredUsers()
{
	auto users = userManager.getRegisteredUsers();
	std::cout << "-----\n";
	for (auto user : users)
	{
	   std::cout << user.id << " " << user.firstName
			<< " " << user.lastName << " " << user.email
			<< " " << std::hex << user.passwordHash << std::endl;
	}
}*/

int main() try
{
	pm::pl::Application app;
	const std::string connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=PCBURGAS;Database=PMDB;Trusted_Connection=yes;"); // an ODBC connection string to your database
	nanodbc::connection conn(connstr);

	app.run(conn);
}

catch (std::exception const& e)
{
	std::cerr << "Error: " << e.what() << std::endl;
}

catch (...)
{
	std::cerr << "Unknown error" << std::endl;
}