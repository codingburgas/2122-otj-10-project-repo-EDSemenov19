#include "pch.h"
#include "TaskManager.h"

void pm::bll::TaskManager::tasksForProjectNotFound(
	nanodbc::connection& connection, pm::types::User& user)
{
	pm::pl::TasksManagement::tasksForProjectNotFound(connection, user);
}

void pm::bll::TaskManager::displayTasksOfProject(
	nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);
	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);
	size_t projectId =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::types::Project project =
		pm::dal::ProjectStore::getProjectById(conn, user, projectId);

	std::vector<pm::types::Task> tasks =
		pm::dal::TaskStore::getTasksOfProject(conn, user, projectId);

	pm::pl::ProjectsManagement::displayProjectsAndTasks(
		conn, user, project, tasks);

	pm::pl::TasksManagement::tasksDisplayed(conn, user);
}

void pm::bll::TaskManager::taskUnassignedFromProject(
	nanodbc::connection& connection, pm::types::User& user)
{
	pm::pl::TasksManagement::taskUnassignedFromProject(
		connection, user);
}

void pm::bll::TaskManager::taskAssignedToProject(
	nanodbc::connection& connection, pm::types::User& user)
{
	pm::pl::TasksManagement::taskAssignedToProject(connection, user);
}

void pm::bll::TaskManager::taskDescriptionChanged(
	nanodbc::connection& connection, pm::types::User& user)
{
	pm::pl::TasksManagement::taskDescriptionChanged(
		connection, user);
}

void pm::bll::TaskManager::taskTitleChanged(nanodbc::connection& connection,
	pm::types::User& user)
{
	pm::pl::TasksManagement::taskTitleChanged(connection, user);
}

void pm::bll::TaskManager::displayAllTasks(nanodbc::connection& conn,
	pm::types::User& user)
{
	std::vector<pm::types::Task> tasks =
		pm::dal::TaskStore::getAllTasks(conn, user);
	pm::pl::TasksManagement::displayTasks(
		conn, user, tasks);

	pm::pl::TasksManagement::tasksDisplayed(conn, user);
}

void pm::bll::TaskManager::taskDeleted(nanodbc::connection& connection,
	pm::types::User& user)
{
	pm::pl::TasksManagement::taskDeleted(connection, user);
}

void pm::bll::TaskManager::deleteTask(nanodbc::connection& connection,
	pm::types::User& user)
{
	std::vector<pm::types::Task> tasks =
		pm::dal::TaskStore::getAllTasks(connection, user);
	size_t taskId =
		pm::pl::TasksManagement::getTaskId(connection, user, tasks);

	pm::dal::TaskStore::deleteTaskById(connection, user, taskId);
}

void pm::bll::TaskManager::createTask(
	nanodbc::connection& connection, pm::types::User& user)
{
	pm::types::Task task = pm::pl::TasksManagement::getTask(
		connection, user);

	pm::dal::TaskStore::createTask(connection, user, task);
}

void pm::bll::TaskManager::taskCreated(nanodbc::connection& conn,
	pm::types::User& user)
{
	pm::pl::TasksManagement::taskCreated(conn, user);
}

void pm::bll::TaskManager::editTask(nanodbc::connection& conn,
	pm::types::User& user)
{
	std::vector<pm::types::Task> tasks =
		pm::dal::TaskStore::getAllTasks(conn, user);
	size_t taskId =
		pm::pl::TasksManagement::getTaskId(conn, user, tasks);

	tasks = pm::dal::TaskStore::getTaskById(conn, user, taskId);

	pm::pl::TasksManagement::displayTasks(conn, user, tasks);

	size_t option =
		pm::pl::TasksManagement::displayEditMenu(conn, user);
	switch (option)
	{
	case 1:
	{std::string newTitle =
		pm::pl::TasksManagement::getNewTaskTitle(
			conn, user, tasks);
	pm::dal::TaskStore::updateTaskTitle(
		conn, user, taskId, newTitle); }
	break;
	case 2:
	{std::string newDescription =
		pm::pl::TasksManagement::getNewDescription(
			conn, user, tasks);
	pm::dal::TaskStore::updateTaskDescription(
		conn, user, taskId, newDescription); }
	break;
	case 3: pm::bll::TaskManager::assignTask(conn, user, tasks);
		break;
	case 4: pm::bll::TaskManager::unassignTask(conn, user, tasks);
		break;
	case 5:
		pm::pl::TasksManagement::displayTasksManagement(conn, user);
		break;
	}
}

void pm::bll::TaskManager::assignTask(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);
	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);
	size_t projectId =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::dal::TaskStore::assignTask(conn, user, tasks, projectId);
}

void pm::bll::TaskManager::unassignTask(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& tasks)
{
	std::vector<pm::types::Project> projects =
		pm::dal::ProjectStore::getAllProjects(conn, user);
	pm::pl::ProjectsManagement::displayProjects(
		conn, user, projects);
	size_t projectId =
		pm::pl::ProjectsManagement::getProjectId(conn, user);

	pm::dal::TaskStore::unassignTask(conn, user, tasks, projectId);
}
