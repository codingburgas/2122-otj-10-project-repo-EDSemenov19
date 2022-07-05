#pragma once
#include "pch.h"
#include <iostream>
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "../pm.bll/TeamManager.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::dal
{
	namespace TeamStore
	{
		void unassignUser(
			nanodbc::connection& conn, pm::types::User&,
			size_t userId, size_t teamId);
		void getTeamsById(nanodbc::connection& conn,
			pm::types::User user, size_t teamId,
			std::vector<pm::types::Team>& teams);
		void registerTeam(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::Team& team);
		std::vector<pm::types::Team> getTeams(
			nanodbc::connection& conn, pm::types::User& user);
		void deleteTeam(nanodbc::connection& conn, pm::types::User& user,
			unsigned short int option);
		void assignUser(nanodbc::connection& conn, pm::types::User& user,
			size_t& userId, size_t& teamId);
		std::vector<pm::types::Team> getTeamsOfUser(
			nanodbc::connection& conn, pm::types::User& user, size_t option);
	}
}