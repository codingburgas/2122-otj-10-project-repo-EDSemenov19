#include "pch.h"
#include "UserStore.h"

std::vector<pm::types::User> users;

size_t generateNewId()
{
	size_t maxId = 0;

	for (auto user : users)
	{
		if (user.id > maxId)
		{
			maxId = user.id;
		}
	}

	return maxId + 1;
}

void pm::dal::UserStore::create(pm::types::User& user)
{
	auto it = std::find_if(users.begin(), users.end(),
		[&](pm::types::User u) { return u.email == user.email; });

	if (it != users.end())
	{
		throw std::range_error("The user " + std::string(user.email) + " already exists!");
	}

	user.id = generateNewId();

	users.push_back(user);
}

pm::types::User pm::dal::UserStore::getById(size_t id)
{
	auto it = std::find_if(users.begin(), users.end(),
		[&](pm::types::User u) { return u.id == id; });

	if (it != users.end())
	{
		throw std::range_error(std::string("User with id ") + std::to_string(id) + std::string(" was not found!"));
	}

	return *it;

	/*for (auto user : users)
	{
		if (user.id == id)
		{
			return user;
		}
	}*/

	
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


pm::types::User pm::dal::UserStore::getByUsername(std::string username, nanodbc::connection& conn)
{
	nanodbc::statement stmt(conn);
	nanodbc::prepare(stmt, NANODBC_TEXT("SELECT * FROM users WHERE username = ?"));
	stmt.bind(0, username.c_str());
	nanodbc::result result = execute(stmt);
	const short columns = result.columns();

	if (!result)
	{
		throw std::range_error("User not found!");
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

std::vector<pm::types::User> pm::dal::UserStore::get_all()
{
	return std::vector<types::User>(users);
}

nanodbc::result pm::dal::UserStore::getAllElements(nanodbc::connection& conn)
{
	nanodbc::result result = execute(conn, NANODBC_TEXT(R"(
     SELECT*
     FROM Users)"));

	return result;
}

void pm::dal::UserStore::remove(const size_t id) const
{
	for (auto it = users.begin(); it != users.end(); ++it)
	{
		if ((*it).id == id)
		{
			users.erase(it);
			return;
		}
	}

	throw std::range_error(std::string("User with id ") + std::to_string(id) + std::string(" was not found!"));
}

void pm::dal::UserStore::update(const pm::types::User user) const
{
	std::vector<pm::types::User>::iterator it;
	it = std::find_if(users.begin(), users.end(), 
		[&](pm::types::User u) { return u.id == user.id; });
	
	if (it == users.end()) 
	{
		throw std::range_error("User with id " 
			+ std::to_string(user.id) 
			+ " was not found!");
	}

	auto& u = *it;
	u.firstName = user.firstName;
	u.lastName = user.lastName;
	u.email = user.email;
	u.age = user.age;
}
