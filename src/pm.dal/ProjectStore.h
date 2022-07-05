#pragma once
#include "pch.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Project.h"
#include "../pm.bll/ProjectManager.h"
#include "UserStore.h"

namespace pm::dal
{
	namespace ProjectStore
	{
		void createProject(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::Project& project);

		std::vector<pm::types::Project> getAllProjects(
			nanodbc::connection& conn, pm::types::User& user);

		void updateProjectDescription(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& id, std::string& description);
		void updateProjectTitle(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& id, std::string& title);
		void deleteProjectById(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& id);
		void assignTeam(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& teamId, size_t& projectId);
		pm::types::Project getProjectById(
			nanodbc::connection& conn,
			pm::types::User& user, size_t projectId);
		void unassignTeam(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& projectId, size_t& teamId);
	}
}
