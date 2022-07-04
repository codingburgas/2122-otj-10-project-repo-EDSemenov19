#include "pch.h"
#include "TeamStore.h"

void pm::dal::TeamStore::registerTeam(nanodbc::connection& conn, pm::types::User& user, pm::types::Team& team)
{
	team.idOfCreator = user.id;

	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	INSERT INTO [dbo].[Teams] (title, description, createdOn, idOfCreator, lastChange, usersEmails) 
	VALUES 
	(?, ?, GETDATE(), ?, GETDATE(), ?))"));

	stmt.bind(0, team.title.c_str());
	stmt.bind(1, team.description.c_str());
	stmt.bind(2, &team.idOfCreator);
	//stmt.bind(3), 

	nanodbc::execute(stmt);
}