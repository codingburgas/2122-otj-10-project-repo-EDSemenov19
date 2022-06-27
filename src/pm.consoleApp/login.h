#pragma once
#include <string>
#include <iostream>
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"


class Login
{
	std::string email{};
	std::string password{};

	pm::bll::UserManager userManager_;
public:
	void printLogin();
	pm::types::User getUserLogged();
};