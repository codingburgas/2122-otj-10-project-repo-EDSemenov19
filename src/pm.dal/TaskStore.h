#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Task.h"
#include "../pm.consoleapp/TasksManagement.h"

namespace pm::dal
{
	namespace TaskStore
	{
		void deleteTaskById(
			nanodbc::connection& conn, pm::types::User& user, size_t taskId);
		void createTask(nanodbc::connection& conn, pm::types::User& user,
			pm::types::Task& task);
		std::vector<pm::types::Task> getAllTasks(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::Task> getTaskById(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& taskId);
		void updateTaskTitle(nanodbc::connection& conn, pm::types::User& user,
			size_t& taskId, std::string& newTitle);
		void updateTaskDescription(nanodbc::connection& conn, pm::types::User& user,
			size_t& taskId, std::string& newDescription);

	}
}