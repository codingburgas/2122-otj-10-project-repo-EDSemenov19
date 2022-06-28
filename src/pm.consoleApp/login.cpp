#include "login.h"
#include "User.h"

void Login::printLogin()
{
	std::cout << "Login menu" << std::endl;
	std::cout <<"Email: ";
	std::cout << std::endl;
	getline(std::cin, email);
	std::cout << std::endl;
	std::cout <<"Password: ";
	getline(std::cin, password);
}

pm::types::User Login::getUserLogged(nanodbc::connection conn)
{
	printLogin();

	pm::types::User user;

	try
	{
		user = userManager_.loginUser(email, password, conn);
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