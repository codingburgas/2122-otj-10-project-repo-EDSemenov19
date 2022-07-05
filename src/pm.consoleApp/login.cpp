#include "login.h"
#include "User.h"

void pm::pl::Login::printLogin()
{
	std::cout << "Login menu" << std::endl;
	std::cout <<"Username: ";
	getline(std::cin, email);
	std::cout <<"Password: ";
	getline(std::cin, password);
}

void pm::pl::Login::userLoginFailed()
{
	std::cout << "Wrong username or password!" << std::endl;
	std::cin.get();
	exit(0);
}

pm::types::User pm::pl::Login::getUserLogged(nanodbc::connection& conn)
{
	printLogin();

	pm::types::User user;

	try
	{
		user = pm::bll::UserManager::loginUser(email, password, conn);
	}

	catch (std::logic_error& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}

	catch (std::range_error& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}

	return user;
}
