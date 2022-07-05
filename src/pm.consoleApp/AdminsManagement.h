#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/MenuItem.h"
#include "../pm.bll/UserManager.h"
#include "../pm.consoleApp/MainMenu.h"
#include <iostream>
#include "../../lib/tabulate/tabulate.hpp"
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
	namespace AdminsManagement
	{
		void displaySortedUsers(
			nanodbc::connection& conn, pm::types::User& userToDisplay,
			std::vector<pm::types::User>& sortedUsers);
		void displaySortMenu(
			nanodbc::connection& conn, pm::types::User user,
			unsigned short& option);
		void displayDeleteMenu(
			nanodbc::connection& connection, pm::types::User user,
			pm::types::User userToDelete, char& answer);
		void displayEditMenu(
			nanodbc::connection& conn, pm::types::User,
			pm::types::User selectedUser);
		void displayUserDetails(
			nanodbc::connection& conn, pm::types::User,
			pm::types::User selectedUser);
		void displayAdminPanel(
			nanodbc::connection& conn, pm::types::User& user);
		void handleAdminsManagement(
			nanodbc::connection& conn, pm::types::User& user,
			unsigned short int& option);
		void logout(
			nanodbc::connection& conn, pm::types::User& user);
		void displayUsers(
			nanodbc::connection& conn, pm::types::User& userToDisplay,
			std::vector<pm::types::User>& users);
		void userCreated(
			nanodbc::connection& conn, pm::types::User& user);
		void editMenuHandler(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser, const unsigned short& option);

		void getNewFirstName(pm::types::User& selectedUser);
		void getNewLastName(pm::types::User& selectedUser);
		void getNewUsername(pm::types::User& selectedUser);
		void getNewEmail(pm::types::User& selectedUser);
		std::string getNewPassword();
		void getNewAge(pm::types::User& selectedUser);
		void getNewAdminStatus(pm::types::User& selectedUser);
		void updatedSuccessfully(
			nanodbc::connection& conn, pm::types::User& user);
	}
}