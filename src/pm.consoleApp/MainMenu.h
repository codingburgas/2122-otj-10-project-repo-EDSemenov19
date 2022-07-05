#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include <string>
#include <vector>

namespace pm::pl
{
	namespace MainMenu
	{
		void* handleOption1(void*);
		void displayMenu(
			nanodbc::connection& conn, pm::types::User& user);
		void displayUserMenu(
			nanodbc::connection& conn, pm::types::User& user);
		void displayAdminMenu(
			nanodbc::connection& conn, pm::types::User& user);
		void handle(
			nanodbc::connection& conn, pm::types::User& user,
			unsigned short int option);
	}
}