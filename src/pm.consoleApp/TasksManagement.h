#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.bll/TaskManager.h"
#include "AdminsManagement.h"
#include "../pm.bll/UserManager.h"
#include "../pm.types/User.h"
#include <string>
#include <vector>
#include <iostream>

namespace pm::pl
{
	namespace TasksManagement
	{
		size_t getTaskId(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		void taskDescriptionChanged(
			nanodbc::connection& conn, pm::types::User& user);
		void displayTasks(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		void taskTitleChanged(
			nanodbc::connection& conn, pm::types::User user);
		void taskCreated(
			nanodbc::connection& conn, pm::types::User user);
		void tasksDisplayed(
			nanodbc::connection& conn, pm::types::User user);
		std::string getNewTaskTitle(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		std::string getNewDescription(
			nanodbc::connection& conn, pm::types::User& user,
			std::vector<pm::types::Task>& tasks);
		void displayTasksManagement(
			nanodbc::connection& conn, pm::types::User user);
		size_t displayEditMenu(
			nanodbc::connection& conn, pm::types::User user);
		void handleEditMenu(
			nanodbc::connection& conn, pm::types::User user,
			unsigned short int option);
		void handleTaskManagement(
			nanodbc::connection& conn, pm::types::User user,
			unsigned short int option);
		void taskDeleted(
			nanodbc::connection& conn, pm::types::User& user);
		pm::types::Task getTask(
			nanodbc::connection& conn, pm::types::User user);
	};
}