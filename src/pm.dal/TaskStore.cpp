#include "pch.h"
#include "TaskStore.h"

std::vector<pm::types::Task> pm::dal::TaskStore::getTasksOfProject(
	nanodbc::connection& conn, pm::types::User& user,
	size_t& projectId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	SELECT * FROM [tasks_projects]
	WHERE projectId = ?)"));
	stmt.bind(0, &projectId);
	nanodbc::result result = execute(stmt);
	nanodbc::result result1 = result;
	result1.next();
	std::vector<pm::types::Task> tasks{};
	if (result1.rows() == 0)
	{
		pm::bll::TaskManager::tasksForProjectNotFound(conn, user);
	}

	else
	{
		std::vector<size_t> taskIds{};
		do {
			taskIds.push_back(
				result.get<size_t>("taskId"));
		} while (result.next());

		for (auto element : taskIds)
		{
			getTasksById(conn, user, element, tasks);
		}
	}
	return tasks;
}

void pm::dal::TaskStore::getTasksById(
	nanodbc::connection& conn, pm::types::User user, size_t taskId,
	std::vector<pm::types::Task>& tasks)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		SELECT * FROM [dbo].[Tasks]
		WHERE id = ?)");
	stmt.bind(0, &taskId);
	nanodbc::result result = execute(stmt);
	while (result.next())
	{
		auto id =
			result.get<int>("id");
		auto title =
			result.get<std::string>("title");
		auto description =
			result.get<std::string>("description");
		auto m_createdOn =
			result.get<nanodbc::timestamp>("createdOn");
		auto creatorId =
			result.get<int>("creatorId");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId =
			result.get<int>("lastChangerId");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);

		tasks.emplace_back(
			id,
			title,
			description,
			createdOn,
			creatorId,
			lastChange,
			lastChangerId);
	}
}

void pm::dal::TaskStore::deleteTaskById(nanodbc::connection& conn,
	pm::types::User& user, size_t taskId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	DELETE FROM Tasks
		WHERE id = ?)"));
	stmt.bind(0, &taskId);
	execute(stmt);

	pm::bll::TaskManager::taskDeleted(conn, user);
}

void pm::dal::TaskStore::createTask(nanodbc::connection& conn,
	pm::types::User& user, pm::types::Task& task)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
	INSERT INTO Tasks (title, description, createdOn,
	creatorId, lastChange ,lastChangerId) 
	VALUES (?, ?, GETDATE(), ?, GETDATE(), ?))");

	stmt.bind(0, task.title.c_str());
	stmt.bind(1, task.description.c_str());
	stmt.bind(2, &task.creatorId);
	stmt.bind(3, &task.lastChangerId);

	execute(stmt);

	pm::bll::TaskManager::taskCreated(conn, user);
}

std::vector<pm::types::Task> pm::dal::TaskStore::getAllTasks(
	nanodbc::connection& conn, pm::types::User& user)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
    SELECT *
    FROM Tasks
    )"));

	auto result = execute(statement);

	std::vector<pm::types::Task> tasks;
	while (result.next())
	{
		auto id = result.get<int>("id");
		auto title =
			result.get<std::string>("title");
		auto description =
			result.get<std::string>("description");
		auto m_createdOn =
			result.get<nanodbc::timestamp>("createdOn");
		auto creatorId =
			result.get<int>("creatorId");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId =
			result.get<int>("lastChangerId");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);


		tasks.emplace_back(
			id, title, description, createdOn,
			creatorId, lastChange, lastChangerId);
	}

	return tasks;
}

std::vector<pm::types::Task> pm::dal::TaskStore::getTaskById(
	nanodbc::connection& conn, pm::types::User& user,
	size_t& taskId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
    SELECT * FROM Tasks
	WHERE id = ?)"));

	stmt.bind(0, &taskId);
	auto result = execute(stmt);

	std::vector<pm::types::Task> tasks;
	while (result.next())
	{
		auto id = result.get<int>("id");
		auto title =
			result.get<std::string>("title");
		auto description =
			result.get<std::string>("description");
		auto m_createdOn =
			result.get<nanodbc::timestamp>("createdOn");
		auto creatorId =
			result.get<int>("creatorId");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId =
			result.get<int>("lastChangerId");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);


		tasks.emplace_back(
			id, title, description, createdOn,
			creatorId, lastChange, lastChangerId);
	}

	return tasks;
}

void pm::dal::TaskStore::updateTaskTitle(
	nanodbc::connection& conn, pm::types::User& user, size_t& taskId,
	std::string& newTitle)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Tasks]
		SET title = ?, lastChange = GETDATE(), lastChangerId = ?
		WHERE id = ?)"));
	stmt.bind(0, newTitle.c_str());
	stmt.bind(1, &user.id);
	stmt.bind(2, &taskId);

	execute(stmt);

	pm::bll::TaskManager::taskTitleChanged(conn, user);
}

void pm::dal::TaskStore::updateTaskDescription(
	nanodbc::connection& conn, pm::types::User& user, size_t& taskId,
	std::string& newDescription)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Tasks]
		SET description = ?, lastChange = GETDATE(), lastChangerId = ?
		WHERE id = ?)"));
	stmt.bind(0, newDescription.c_str());
	stmt.bind(1, &user.id);
	stmt.bind(2, &taskId);

	execute(stmt);

	pm::bll::TaskManager::taskDescriptionChanged(conn, user);
}

void pm::dal::TaskStore::assignTask(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& task,
	size_t& projectId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	INSERT INTO [dbo].[tasks_projects] (taskId, projectId)
	VALUES (?, ?))"));
	stmt.bind(0, &task[0].id);
	stmt.bind(1, &projectId);
	execute(stmt);

	pm::bll::TaskManager::taskAssignedToProject(conn, user);
}

void pm::dal::TaskStore::unassignTask(
	nanodbc::connection& conn, pm::types::User& user,
	std::vector<pm::types::Task>& task, size_t& projectId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		DELETE FROM [dbo].[tasks_projects]
		WHERE taskId = ? AND projectId = ?)");
	stmt.bind(0, &task[0].id);
	stmt.bind(1, &projectId);
	execute(stmt);

	pm::bll::TaskManager::taskUnassignedFromProject(conn, user);
}
