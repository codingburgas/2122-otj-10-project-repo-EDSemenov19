#include "pch.h"
#include "TeamStore.h"

void pm::dal::TeamStore::getTeamsById(nanodbc::connection& conn, pm::types::User user,
	size_t teamId, std::vector<pm::types::Team>& teams)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		SELECT * FROM [dbo].[Teams]
		WHERE id = ?)");
	stmt.bind(0, &teamId);
	nanodbc::result result = execute(stmt);
	while (result.next())
	{
		auto id = result.get<int>("id");
		auto title = result.get<std::string>("title");
		auto m_createdOn =
			result.get<nanodbc::timestamp>("createdOn");
		auto creatorId = result.get<int>("creatorId");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId = result.get<int>("lastChangerId");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);

		teams.emplace_back(
			id, title, createdOn, creatorId,
			lastChange, lastChangerId);
	}
}

void pm::dal::TeamStore::registerTeam(
	nanodbc::connection& conn, pm::types::User& user, pm::types::Team& team)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	INSERT INTO [dbo].[Teams] (title, createdOn, creatorId,
	 lastChange, lastChangerId) 
	VALUES (?, GETDATE(), ?, GETDATE(), ?))"));

	stmt.bind(0, team.title.c_str());
	stmt.bind(1, &team.creatorId);
	stmt.bind(2, &team.creatorId);

	nanodbc::execute(stmt);

	pm::bll::TeamManager::teamCreated(conn, user);
}

std::vector<pm::types::Team> pm::dal::TeamStore::getTeams(
	nanodbc::connection& conn, pm::types::User& user)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
    SELECT *
    FROM Teams
    )"));

	auto result = execute(statement);

	std::vector<pm::types::Team> teams;
	while (result.next())
	{
		auto id = result.get<int>("id");
		auto title = result.get<std::string>("title");
		auto m_createdOn =
			result.get<nanodbc::timestamp>("createdOn");
		auto creatorId = result.get<int>("creatorId");
		auto m_lastChange =
			result.get<nanodbc::timestamp>("lastChange");
		auto lastChangerId = result.get<int>("lastChangerId");

		auto createdOn =
			pm::dal::UserStore::getTime(m_createdOn);
		auto lastChange =
			pm::dal::UserStore::getTime(m_lastChange);


		teams.emplace_back(
			id, title, createdOn, creatorId,
			lastChange, lastChangerId);
	}

	return teams;
}

void pm::dal::TeamStore::deleteTeam(nanodbc::connection& conn,
	pm::types::User& user, unsigned short option)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	DELETE FROM Teams
		WHERE id = ?)"));
	stmt.bind(0, &option);
	execute(stmt);

	pm::bll::TeamManager::teamDeletedSuccessfully(conn, user);
}

void pm::dal::TeamStore::assignUser(
	nanodbc::connection& conn, pm::types::User& user,
	size_t& userId, size_t& teamId)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	INSERT INTO [dbo].[users_teams] (userId, teamId)
	VALUES (?, ?))"));
	stmt.bind(0, &userId);
	stmt.bind(1, &teamId);
	execute(stmt);

	pm::bll::TeamManager::userAssignedToTeam(conn, user);
}

std::vector<pm::types::Team> pm::dal::TeamStore::getTeamsOfUser(
	nanodbc::connection& conn, pm::types::User& user, size_t option)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	SELECT * FROM [users_teams]
	WHERE userId = ?)"));
	stmt.bind(0, &option);
	nanodbc::result result = execute(stmt);
	nanodbc::result result1 = result;
	result1.next();
	std::vector<pm::types::Team> teams{};
	if (result1.rows() == 0)
	{
		pm::bll::TeamManager::teamsForUserNotFound(conn, user);
	}

	else
	{
		std::vector<size_t> teamIds{};
		do {
			teamIds.push_back(result.get<size_t>("teamId"));
		} while (result.next());

		for (auto element : teamIds)
		{
			getTeamsById(conn, user, element, teams);
		}
	}
	return teams;
}
