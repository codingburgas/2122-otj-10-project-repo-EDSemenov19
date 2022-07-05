#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Task.h"
#include "../pm.bll/ProjectManager.h"
#include "../pm.bll/UserManager.h"
#include "MainMenu.h"
#include "AdminsManagement.h"
#include <iostream>
#include <string>
#include <vector>

namespace pm::pl
{
	namespace ProjectsManagement
	{
		size_t getProjectId(
			nanodbc::connection& conn, pm::types::User& user);
		std::string getProjectDescription(
			nanodbc::connection& conn, pm::types::User& user);
		std::string getProjectTitle(
			nanodbc::connection& conn, pm::types::User& user);
		void displayProjectsAndTasks(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::Project& project,
			std::vector<pm::types::Task> tasks);
		void teamUnassignedFromProject(
			nanodbc::connection& conn, pm::types::User& user);
		void displayProjectsAndTeams(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::Project& project,
			std::vector<pm::types::Team>& teams);
		void teamAssignedToProject(
			nanodbc::connection& conn, pm::types::User& user);
		void projectDeleted(
			nanodbc::connection& conn, pm::types::User& user);
		void projectTitleChanged(
			nanodbc::connection& conn, pm::types::User& user);
		void projectDescriptionChanged(
			nanodbc::connection& conn, pm::types::User& user);
		void projectsDisplayed(
			nanodbc::connection& conn, pm::types::User& user);
		void handleProjectsMenu(
			nanodbc::connection& conn,
			pm::types::User& user, unsigned short option);
		void displayProjectsMenu(
			nanodbc::connection& conn, pm::types::User& user);
		pm::types::Project getProject(
			nanodbc::connection& conn, pm::types::User& user);
		void projectCreated(
			nanodbc::connection& conn, pm::types::User& user);
		void displayProjectsManagement(
			nanodbc::connection& conn, pm::types::User& user);
		void handleProjectsManagement(
			nanodbc::connection& conn,
			pm::types::User& user, unsigned short int option);
		void displayProjects(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Project>& projects);
	}
}