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
	namespace TeamsManagement
	{
		unsigned short int getTeamToDeleteId(nanodbc::connection& conn,
			pm::types::User& user);
		void teamsDisplayed(
			nanodbc::connection& conn, pm::types::User& user);
		void userAssignedToTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void teamDeletedSuccessfully(
		nanodbc::connection& conn, pm::types::User& user);
		void displayTeams(nanodbc::connection& connection,
			pm::types::User& user, std::vector<pm::types::Team>& teams);
		void displayTeamCreatedMenu(
			nanodbc::connection& conn, pm::types::User& user);
		pm::types::Team getTeam(nanodbc::connection& conn,
			pm::types::User& user);
		void displayTeamsOfUser(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTeamsOfProject(
			nanodbc::connection& conn, pm::types::User& user);
		void handleTeamsDisplay(
			nanodbc::connection& conn, pm::types::User& user,
			unsigned short int option);
		void displayAllteams(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTeamsView(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTeamsManagement(
			nanodbc::connection& conn, pm::types::User user);
		void handleTeamsView(
			nanodbc::connection& conn, pm::types::User& user,
			unsigned short option);
		int getUserId(nanodbc::connection& conn, pm::types::User& user, std::vector<types::User>& users);
		int getTeamId(nanodbc::connection& conn, pm::types::User& user, std::vector<types::Team>& teams);
	};
}