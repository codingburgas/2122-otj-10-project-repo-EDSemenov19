#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include "../pm.types/Task.h"
#include "../pm.consoleapp/TasksManagement.h"
#include "../pm.dal/TaskStore.h"
#include "../pm.bll/ProjectManager.h"


namespace pm::bll
{
	namespace TaskManager
	{
		void tasksForProjectNotFound(
			nanodbc::connection& connection, pm::types::User& user);
		void displayTasksOfProject(
			nanodbc::connection& connection, pm::types::User& user);
		void taskUnassignedFromProject(
			nanodbc::connection& connection, pm::types::User& user);
		void taskAssignedToProject(
			nanodbc::connection& connection, pm::types::User& user);
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
		void assignTask(
			nanodbc::connection& connection, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		void unassignTask(
			nanodbc::connection& connection, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
	}
}
