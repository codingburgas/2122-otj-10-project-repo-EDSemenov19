#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Task.h"
#include "../pm.consoleapp/TasksManagement.h"
#include "../pm.dal/TaskStore.h"


namespace pm::bll
{
	namespace TaskManager
	{
		void taskDescriptionChanged(
			nanodbc::connection& connection, pm::types::User& user);
		void taskTitleChanged(
			nanodbc::connection& connection, pm::types::User& user);
		void displayAllTasks(
			nanodbc::connection& connection, pm::types::User& user);
		void taskDeleted(
			nanodbc::connection& connection, pm::types::User& user);
		void deleteTask(
			nanodbc::connection& connection, pm::types::User& user);
		void createTask(
			nanodbc::connection& connection, pm::types::User& user);
		void taskCreated(
			nanodbc::connection& connection, pm::types::User& user);
		void editTask(
			nanodbc::connection& connection, pm::types::User& user);
		void assignUser(
			nanodbc::connection& connection, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		void unassignUser(
			nanodbc::connection& connection, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
	}
}
