#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "../pm.consoleApp/AdminsManagement.h"
#include "../pm.consoleApp/TeamsManagement.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::bll
{
	namespace TeamManager
	{
		void createTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void deleteTeam(
			nanodbc::connection& conn, pm::types::User& user);

	}
}