#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
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