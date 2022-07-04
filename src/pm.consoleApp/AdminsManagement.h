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
		static void displaySortedUsers(nanodbc::connection& conn, pm::types::User& userToDisplay, std::vector<pm::types::User>& sortedUsers);
		static void displaySortMenu(nanodbc::connection& conn, pm::types::User user, unsigned short& option);
		static void displayDeleteMenu(nanodbc::connection& connection, pm::types::User user, pm::types::User userToDelete, char& answer);
		static void displayEditMenu(nanodbc::connection& conn, pm::types::User, pm::types::User selectedUser);
		static void displayUserDetails(nanodbc::connection& conn, pm::types::User, pm::types::User selectedUser);
		static void displayAdminPanel(nanodbc::connection& conn, pm::types::User& user);
		//void getUsersToView(nanodbc::connection& conn, pm::types::User& user);
		static void handleAdminsManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int& option);
		static void logout(nanodbc::connection& conn, pm::types::User& user);
		static void displayUsers(nanodbc::connection& conn, pm::types::User& userToDisplay, std::vector<pm::types::User>& users);
		static void userCreated(nanodbc::connection& conn, pm::types::User& user);
		static void editMenuHandler(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser, const unsigned short& option);

		static void getNewFirstName(pm::types::User& selectedUser);
		static void getNewLastName(pm::types::User& selectedUser);
		static void getNewUsername(pm::types::User& selectedUser);
		static void getNewEmail(pm::types::User& selectedUser);
		static std::string getNewPassword();
		static void getNewAge(pm::types::User& selectedUser);
		static void getNewAdminStatus(pm::types::User& selectedUser);
		static void updatedSuccessfully(nanodbc::connection& conn, pm::types::User& user);
	};
}