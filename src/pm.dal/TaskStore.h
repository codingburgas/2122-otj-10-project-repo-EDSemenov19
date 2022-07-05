#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Task.h"
#include "../pm.consoleapp/TasksManagement.h"

namespace pm::dal
{
	namespace TaskStore
	{
		std::vector<pm::types::Task> getTasksOfProject(
			nanodbc::connection& conn, pm::types::User& user,
			size_t& projectIdl);
		void getTasksById(nanodbc::connection& conn, pm::types::User user,
			size_t taskId, std::vector<pm::types::Task>& tasks);
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
		void updateTaskDescription(nanodbc::connection& conn,
			pm::types::User& user,
			size_t& taskId, std::string& newDescription);
		void assignTask(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& task, size_t& projectId);

		void unassignTask(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& task, size_t& projectId);
	}
}