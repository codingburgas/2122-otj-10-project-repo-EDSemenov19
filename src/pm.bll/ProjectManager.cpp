#include "pch.h"
#include "ProjectManager.h"
#include "../pm.consoleApp/ProjectsManagement.h"
#include "../pm.dal/ProjectStore.h"


void pm::bll::ProjectManager::teamUnassignedFromProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::teamUnassignedFromProject(conn, user);
}

void pm::bll::ProjectManager::teamAssignedToProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::teamAssignedToProject(conn, user);
}

void pm::bll::ProjectManager::projectDeleted(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::projectDeleted(conn, user);
}

void pm::bll::ProjectManager::projectTitleChanged(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::projectTitleChanged(conn, user);
}

void pm::bll::ProjectManager::projectDescriptionChanged(
	nanodbc::connection& conn, pm::types::User& user)
{
	pm::pl::ProjectsManagement::projectDescriptionChanged(conn, user);
}

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
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);

	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	size_t id =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::dal::ProjectStore::deleteProjectById(
		conn, user, id);
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
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);

	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	size_t id =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	std::string title =
		pm::pl::ProjectsManagement::getProjectTitle(conn, user);

	pm::dal::ProjectStore::updateProjectTitle(
		conn, user, id, title);
}

void pm::bll::ProjectManager::editProjectDescription(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);

	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	size_t id =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	std::string description =
		pm::pl::ProjectsManagement::getProjectDescription(conn, user);

	pm::dal::ProjectStore::updateProjectDescription(
		conn, user, id, description);

}

void pm::bll::ProjectManager::assignTeam(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Team> teams =
		pm::dal::TeamStore::getTeams(conn, user);
	size_t teamId =
		pm::pl::TeamsManagement::getTeamId(conn, user, teams);

	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);
	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	size_t projectId =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::dal::ProjectStore::assignTeam(
		conn, user, projectId, teamId);
}

void pm::bll::ProjectManager::unassignTeam(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Team> teams =
		pm::dal::TeamStore::getTeams(conn, user);
	size_t teamId =
		pm::pl::TeamsManagement::getTeamId(conn, user, teams);

	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);
	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);

	size_t projectId =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::dal::ProjectStore::unassignTeam(
		conn, user, projectId, teamId);
}
