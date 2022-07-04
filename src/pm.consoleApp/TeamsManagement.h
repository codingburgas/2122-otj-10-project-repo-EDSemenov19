#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/MenuItem.h"
#include <iostream>
#include "AdminsManagement.h"
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "../pm.bll/TeamManager.h"
#include "../pm.bll/UserManager.h"

namespace pm::pl
{
	struct TeamsManagement
	{
		static pm::types::Team getTeam();
		static void displayTeamsOfUser(nanodbc::connection& conn, pm::types::User& user);
		static void displayTeamsOfProject(nanodbc::connection& conn, pm::types::User& user);
		static void handleTeamsDisplay(nanodbc::connection& conn, pm::types::User& user, unsigned short int option);
		static void displayAllteams(nanodbc::connection& conn, pm::types::User& user);
		static void displayTeamsView(nanodbc::connection& conn, pm::types::User& user);
		static void displayTeamsManagement(nanodbc::connection& conn, pm::types::User user);
		static void handleTeamsView(nanodbc::connection& conn, pm::types::User& user, unsigned short option);
	};
}