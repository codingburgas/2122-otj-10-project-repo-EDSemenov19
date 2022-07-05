#include "pch.h"
#include "ProjectStore.h"

void pm::dal::ProjectStore::createProject(nanodbc::connection& conn,
	pm::types::User& user, pm::types::Project& project)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
	INSERT INTO Projects (title, description, createdOn, IdOfCreator,
	lastChange, idOfLastChanger)
	VALUES (?, ?, GETDATE(), ?, GETDATE(), ?)
	)");

	stmt.bind(0, project.title.c_str());
	stmt.bind(1, project.description.c_str());
	stmt.bind(2, &project.idOfCreator);
	stmt.bind(3, &project.idOfLastChanger);

	execute(stmt);

	pm::bll::ProjectManager::projectCreated(conn, user);
}

std::vector<pm::types::Project> pm::dal::ProjectStore::getAllProjects(
	nanodbc::connection& conn, pm::types::User& user)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
	SELECT * FROM Projects
    )"));

	auto result = execute(statement);

	std::vector<pm::types::Project> projects;
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
			result.get<int>("IdOfCreator");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId =
			result.get<int>("idOfLastChanger");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);


		projects.emplace_back(
			id, title, description, createdOn,
			creatorId, lastChange, lastChangerId);
	}

	return projects;
}

void pm::dal::ProjectStore::updateProjectDescription(
	nanodbc::connection& conn, pm::types::User& user,
	size_t& id, std::string& description)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Projects]
		SET description = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, description.c_str());
	stmt.bind(1, &id);

	execute(stmt);

	pm::bll::ProjectManager::projectDescriptionChanged(conn, user);
}

void pm::dal::ProjectStore::updateProjectTitle(
	nanodbc::connection& conn, pm::types::User& user, size_t& id,
	std::string& title)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Projects]
		SET title = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, title.c_str());
	stmt.bind(1, &id);

	execute(stmt);

	pm::bll::ProjectManager::projectTitleChanged(conn, user);
}

void pm::dal::ProjectStore::deleteProjectById(
	nanodbc::connection& conn, pm::types::User& user, size_t& id)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		DELETE FROM [dbo].[Projects]
		WHERE id = ?)");
	stmt.bind(0, &id);
	execute(stmt);

	pm::bll::ProjectManager::projectDeleted(conn, user);
}
