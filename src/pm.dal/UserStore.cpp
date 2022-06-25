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

pm::types::User pm::dal::UserStore::getByEmail(std::string email)
{
	auto it = std::find_if(users.begin(), users.end(), 
		[=](pm::types::User u) { return u.email == email;  });

	if (it == users.end())
	{
		throw std::range_error("User not found!");
	}

	return *it;
}

std::vector<pm::types::User> pm::dal::UserStore::get_all()
{
	return std::vector<types::User>(users);
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
