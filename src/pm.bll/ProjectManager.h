#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include "../pm.types/Project.h"
#include "../../lib/nanodbc/nanodbc.h"


namespace pm::bll
{
	namespace ProjectManager
	{
		void projectDeleted(
			nanodbc::connection& conn, pm::types::User& user);
		void projectTitleChanged(
			nanodbc::connection& conn, pm::types::User& user);
		void projectDescriptionChanged(
			nanodbc::connection& conn, pm::types::User& user);
		void createProject(
			nanodbc::connection& conn, pm::types::User& user);
		void projectCreated(
			nanodbc::connection& conn, pm::types::User& user);
		void deleteProject(
			nanodbc::connection& conn, pm::types::User& user);
		void displayAllProjects(
			nanodbc::connection& conn, pm::types::User& user);
		void editProjectTitle(
			nanodbc::connection& conn, pm::types::User& user);
		void editProjectDescription(
			nanodbc::connection& conn, pm::types::User& user);
		void assignTeam(
			nanodbc::connection& conn, pm::types::User& user);
		void unassignTeam(
			nanodbc::connection& conn, pm::types::User& user);
	}
}