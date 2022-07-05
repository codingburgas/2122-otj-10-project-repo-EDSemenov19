#include "pch.h"
#include "TeamManager.h"

void pm::bll::TeamManager::teamsForUserNotFound(nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::TeamsManagement::teamsForUserNotFound(conn, user);
}

void pm::bll::TeamManager::userAssignedToTeam(nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::TeamsManagement::userAssignedToTeam(conn, user);
}

void pm::bll::TeamManager::teamDeletedSuccessfully(nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::TeamsManagement::teamDeletedSuccessfully(conn, user);
}

void pm::bll::TeamManager::createTeam(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::types::Team team = pm::pl::TeamsManagement::getTeam(conn, user);
	pm::dal::TeamStore::registerTeam(conn, user, team);
}



void pm::bll::TeamManager::deleteTeam(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Team> teams = 
		pm::dal::TeamStore::getTeams(conn, user);
	pm::pl::TeamsManagement::displayTeams(
		conn, user, teams);
	unsigned short int option =
		pm::pl::TeamsManagement::getTeamToDeleteId(conn, user);
	pm::dal::TeamStore::deleteTeam(conn, user, option);
}

void pm::bll::TeamManager::teamCreated(nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::TeamsManagement::displayTeamCreatedMenu(conn, user);
}

void pm::bll::TeamManager::displayAllteams(nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Team> teams =
		pm::dal::TeamStore::getTeams(conn, user);
	pm::pl::TeamsManagement::displayTeams(
		conn, user, teams);

	std::cin.get();
	pm::pl::TeamsManagement::teamsDisplayed(conn, user);
}

void pm::bll::TeamManager::displayTeamsOfUser(nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::User> users =
		pm::dal::UserStore::getAllUsers(conn, user);
	size_t userId =
		pm::pl::TeamsManagement::getUserId(conn, user, users);

	std::vector<pm::types::Team> teams = 
		pm::dal::TeamStore::getTeamsOfUser(conn, user, userId);

	pm::pl::TeamsManagement::displayTeams(
		conn, user, teams);

	pm::pl::TeamsManagement::teamsDisplayed(conn, user);
}

void pm::bll::TeamManager::displayTeamsOfProject(nanodbc::connection& conn, pm::types::User& user)
{
}

void pm::bll::TeamManager::assignUser(nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::User> users =
		pm::dal::UserStore::getAllUsers(conn, user);
	size_t userId = 
		pm::pl::TeamsManagement::getUserId(conn, user, users);

	std::vector<pm::types::Team> teams =
		pm::dal::TeamStore::getTeams(conn, user);
	size_t teamId =
		pm::pl::TeamsManagement::getTeamId(conn, user, teams);

	pm::dal::TeamStore::assignUser(conn, user, userId, teamId);
}

void pm::bll::TeamManager::unassignUser(nanodbc::connection& conn, pm::types::User& user)
{

}
