#include "login.h"
#include "../pm.types/User.h"

void Login::printLogin()
{
	std::cout << "Login menu" << std::endl;
	std::cout <<"Email: ";
	getline(std::cin, email);
	std::cout <<"Password: ";
	getline(std::cin, password);
}

pm::types::User Login::getUserLogged()
{
	printLogin();

	pm::types::User user;

	try
	{
		user = userManager_.loginUser(email, password);
	}

	catch (std::logic_error& e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}

	return user;
}