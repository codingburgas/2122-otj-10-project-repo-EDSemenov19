#include "pch.h"
#include "UserStore.h"
#include "UserManager.h"

void pm::dal::UserStore::create(nanodbc::connection& conn, pm::types::User& user, pm::types::User& newUser)
{
	int isAdmin = newUser.isAdmin;

	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
	INSERT INTO [dbo].[Users] (firstName, lastName, username, email, age, passwordHash, createdOn, lastChange, isAdmin) 
	VALUES 
	(?, ?, ?, ?, ?, ?, GETDATE(), GETDATE(), ?))"));

	stmt.bind(0, newUser.firstName.c_str());
	stmt.bind(1, newUser.lastName.c_str());
	stmt.bind(2, newUser.username.c_str());
	stmt.bind(3, newUser.email.c_str());
	stmt.bind(4, &newUser.age);
	stmt.bind(5, newUser.passwordHash.c_str());
	stmt.bind(6, &isAdmin);

	nanodbc::execute(stmt);
}

void pm::dal::UserStore::getUsersToView(nanodbc::connection& conn, pm::types::User& user)
{
	nanodbc::statement stmt(conn);
	//std::cout << user.id << " -> " << foundUser.firstName << ' ' << foundUser.lastName << std::endl;
}


time_t getTime(nanodbc::timestamp& ts1)
{
	tm time{};
	time.tm_year = ts1.year - 1900;
	time.tm_mon = ts1.month - 1;
	time.tm_mday = ts1.day;
	time.tm_hour = ts1.hour;
	time.tm_min = ts1.min;
	time.tm_sec = ts1.sec;

	const time_t tsRes = mktime(&time);

	return tsRes;
}


bool pm::dal::UserStore::checkByUsername(nanodbc::connection& conn, std::string username)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		SELECT * FROM [dbo].[Users]
		WHERE username = ?)");
	stmt.bind(0, username.c_str());
	nanodbc::result result = execute(stmt);
	result.next();

	if (result.rows() == 0)
	{
		return false;
	}

	return true;
}

pm::types::User pm::dal::UserStore::getUserById(nanodbc::connection& conn, const unsigned short int option)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		SELECT * FROM [dbo].[Users]
		WHERE id = ?)");
	stmt.bind(0, &option);
	nanodbc::result result = execute(stmt);
	result.next();

	pm::types::User user;
	{
		user.id = result.get<size_t>("id");
		user.firstName = result.get<std::string>("firstName");
		user.lastName = result.get<std::string>("lastName");
		user.username = result.get<std::string>("username");
		user.email = result.get<std::string>("email");
		user.age = result.get<size_t>("age");
		user.passwordHash = result.get<std::string>("passwordHash");

		auto createdOnTP = result.get<nanodbc::timestamp>("createdOn");
		auto lastChangeTP = result.get<nanodbc::timestamp>("lastChange");
		user.createdOn = getTime(createdOnTP);
		user.lastChange = getTime(lastChangeTP);

		user.isAdmin = result.get<int>("isAdmin");
	}

	return user;
}

pm::types::User pm::dal::UserStore::getByUsername(std::string username, nanodbc::connection& conn)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		SELECT * FROM [dbo].[Users]
		WHERE username = ?)");
	stmt.bind(0, username.c_str());
	nanodbc::result result = execute(stmt);
	result.next();

	if (result.rows() == 0)
	{
		throw std::range_error(std::string("Incorrect username or password!"));
	}

	pm::types::User user;
	{
		user.id = result.get<size_t>("id");
		user.firstName = result.get<std::string>("firstName");
		user.lastName = result.get<std::string>("lastName");
		user.username = result.get<std::string>("username");
		user.email = result.get<std::string>("email");
		user.age = result.get<size_t>("age");
		user.passwordHash = result.get<std::string>("passwordHash");

		auto createdOnTP = result.get<nanodbc::timestamp>("createdOn");
		auto lastChangeTP = result.get<nanodbc::timestamp>("lastChange");
		user.createdOn = getTime(createdOnTP);
		user.lastChange = getTime(lastChangeTP);

		user.isAdmin = result.get<int>("isAdmin");
	}

	return user;
}

void pm::dal::UserStore::deleteUser(nanodbc::connection& conn, pm::types::User& user, pm::types::User& userToDelete)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, R"(
		DELETE FROM [dbo].[Users]
		WHERE id = ?)");
	stmt.bind(0, &userToDelete.id);
	execute(stmt);
}

nanodbc::result pm::dal::UserStore::getAllElements(nanodbc::connection& conn)
{
	nanodbc::result result = execute(conn, NANODBC_TEXT(R"(
     SELECT*
     FROM Users)"));

	return result;
}

std::vector<pm::types::User> pm::dal::UserStore::getAllUsers(nanodbc::connection& conn, pm::types::User& user)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
    SELECT *
    FROM Users
    )"));

	auto result = execute(statement);

	std::vector<pm::types::User> users;
	while (result.next())
	{
		auto id = result.get<size_t>("id");
		auto firstName = result.get<std::string>("firstName");
		auto lastName = result.get<std::string>("lastName");
		auto username = result.get<std::string>("username");
		auto email = result.get<std::string>("email");
		auto age = result.get<size_t>("age");
		auto passwordHash = result.get<std::string>("passwordHash");

		auto createdOnTP = result.get<nanodbc::timestamp>("createdOn");
		auto lastChangeTP = result.get<nanodbc::timestamp>("lastChange");
		auto createdOn = getTime(createdOnTP);
		auto lastChange = getTime(lastChangeTP);

		auto isAdmin = result.get<int>("isAdmin");

		users.emplace_back(id, firstName, lastName, username, email, age, passwordHash, createdOn, lastChange, isAdmin);
	}

	return users;
}

void pm::dal::UserStore::updateFirstName(nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare (stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET firstName = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, selectedUser.firstName.c_str());
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updateLastName(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET lastName = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, selectedUser.lastName.c_str());
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updateUsername(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET username = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, selectedUser.username.c_str());
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updateEmail(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET email = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, selectedUser.email.c_str());
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updatePassword(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET passwordHash = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, selectedUser.passwordHash.c_str());
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updateAge(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET age = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, &selectedUser.age);
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::updateAdminStatus(nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	int isAdmin = selectedUser.isAdmin;
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT(R"(
		UPDATE [dbo].[Users]
		SET isAdmin = ?, lastChange = GETDATE()
		WHERE id = ?)"));
	stmt.bind(0, &isAdmin);
	stmt.bind(1, &selectedUser.id);

	execute(stmt);
}

void pm::dal::UserStore::update(const pm::types::User user) const
{

}
