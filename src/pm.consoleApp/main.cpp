#include <iostream>
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "pm.consoleApp.h"
#include <iomanip>
#include <ios>
#include "Application.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "login.h"

int main() try
{
	pm::pl::Application app;
	const std::string connstr = NANODBC_TEXT(R"(
	Driver={ODBC Driver 17 for SQL Server};
	Server=PCBURGAS;
	Database=PMDB;
	Trusted_Connection=yes;
	MARS_Connection=Yes)"); // an ODBC connection string to (MARS) your database
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