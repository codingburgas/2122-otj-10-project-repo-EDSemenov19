#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/MenuItem.h"
#include "../pm.bll/UserManager.h"
#include "../pm.consoleApp/MainMenu.h"
#include <iostream>
#include "../../lib/nanodbc/nanodbc.h"
#include "MainMenu.h"
#include "login.h"
#include "Application.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include <string>
#include <vector>
#include <iostream>

namespace pm::pl
{
	struct AdminsManagement
	{
		static void displayUserDetails(nanodbc::connection& conn, pm::types::User, pm::types::User selectedUser);
		static void displayAdminsManagement(nanodbc::connection& conn, pm::types::User& user);
		//void getUsersToView(nanodbc::connection& conn, pm::types::User& user);
		static void handleAdminsManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int& option);
		static void logout(nanodbc::connection& conn, pm::types::User& user);
		static void displayUsers(nanodbc::connection& conn, pm::types::User& userToDisplay, std::vector<pm::types::User>& users);
		static void userCreated(nanodbc::connection& conn, pm::types::User& user);
	};
}