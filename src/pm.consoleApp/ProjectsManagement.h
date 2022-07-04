#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include "../pm.bll/UserManager.h"
#include "MainMenu.h"
#include "AdminsManagement.h"
#include <iostream>
#include <string>
#include <vector>

namespace pm::pl
{
	struct ProjectsManagement
	{
		static void handleProjectsManagement(nanodbc::connection& conn,
			pm::types::User& user, unsigned short option);
		static void displayProjectsManagement(nanodbc::connection& conn,
			pm::types::User& user);
	};
}