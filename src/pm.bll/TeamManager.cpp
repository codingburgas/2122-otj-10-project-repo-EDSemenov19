#include "pch.h"
#include "TeamManager.h"

void pm::bll::TeamManager::createTeam(nanodbc::connection& conn, pm::types::User& user)
{
	pm::types::Team team = pm::pl::TeamsManagement::getTeam();
}

void pm::bll::TeamManager::deleteTeam(nanodbc::connection& conn, pm::types::User& user)
{

}
