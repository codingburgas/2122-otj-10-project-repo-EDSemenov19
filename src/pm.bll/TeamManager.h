#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "../pm.consoleApp/AdminsManagement.h"
#include "../pm.consoleApp/TeamsManagement.h"
#include "../pm.dal/TeamStore.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::bll
{
	namespace TeamManager
	{
		void userAssignedToTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void teamDeletedSuccessfully(
			nanodbc::connection& conn, pm::types::User& user);
		void createTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void deleteTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void teamCreated(
			nanodbc::connection& conn, pm::types::User& user);
		void displayAllteams(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTeamsOfUser(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTeamsOfProject(
			nanodbc::connection& conn, pm::types::User& user);
		void assignUser(
			nanodbc::connection& conn, pm::types::User& user);
		void unassignUser(
			nanodbc::connection& conn, pm::types::User& user);
	}
}