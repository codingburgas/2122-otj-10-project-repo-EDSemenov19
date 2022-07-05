#include "pch.h"
#include "ProjectManager.h"
#include "../pm.consoleApp/ProjectsManagement.h"
#include "../pm.dal/ProjectStore.h"

void pm::bll::ProjectManager::createProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::types::Project project = 
		pm::pl::ProjectsManagement::getProject(conn, user);
	pm::dal::ProjectStore::createProject(conn, user, project);
}

void pm::bll::ProjectManager::projectCreated(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::projectCreated(conn, user);
}

void pm::bll::ProjectManager::deleteProject(
	nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::bll::ProjectManager::displayAllProjects(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Project> projects = 
		pm::dal::ProjectStore::getAllProjects(conn, user);

	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	pm::pl::ProjectsManagement::projectsDisplayed(conn, user);
}

void pm::bll::ProjectManager::editProjectTitle(
	nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::bll::ProjectManager::editProjectDescription(
	nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::bll::ProjectManager::assignTeam(
	nanodbc::connection& conn, pm::types::User& user)
{

}

void pm::bll::ProjectManager::unassignTeam(
	nanodbc::connection& conn, pm::types::User& user)
{

}
