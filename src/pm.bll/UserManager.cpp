#include "pch.h"
#include "UserManager.h"
#include "../pm.tools/md5.h"

// Simple hashing via md5
std::string pm::bll::UserManager::hashString(const std::string& str)
{
	return std::string(md5(str));

	std::string newStr(str);

	//for (size_t i = 0; i < newStr.size(); i++)
	//{
	//	newStr[i] = newStr[i] ^ 15;
	//}

	//return newStr;
}

void pm::bll::UserManager::registerUser(std::string firstName, 
	std::string lastName, uint8_t age, std::string email, 
	std::string password)
{
	pm::types::User user;
	// TODO: Check password requirements

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	//user.passwordHash = hashString(password);
	
	m_userStore.create(user);
}

bool pm::bll::UserManager::checkForNoUsers(nanodbc::connection& conn) const
{
	return (pm::dal::UserStore::getAllElements( conn)) ? true : false;
}

pm::types::User pm::bll::UserManager::loginUser(const std::string& username, std::string& password)
{

	if (checkForNoUsers && username == "admin" && password == "adminpass")
	{
		return pm::types::User("admin", "admin", "admin@pm.com", 0, "adminpass", true);
	}

	pm::types::User user = m_userStore.getByEmail(username);

	std::string passHash = hashString(password);

	/*if (user.passwordHash != passHash)
	{
		throw std::logic_error("Invalid password!");
	}*/

	return user;
}

std::vector<pm::types::User> pm::bll::UserManager::getRegisteredUsers()
{
	auto users = m_userStore.get_all();
	return users;
}

void pm::bll::UserManager::seedDatabase()
{
	registerUser("fn1", "ln1", 16, "u1@lab.com", "1231");
	registerUser("fn2", "ln2", 17, "u2@lab.com", "1232");
	registerUser("fn3", "ln3", 15, "u3@lab.com", "1233");
	registerUser("fn4", "ln4", 18, "u4@lab.com", "1234");
}

void pm::bll::UserManager::removeUser(size_t id)
{
	m_userStore.remove(id);
}

void pm::bll::UserManager::updateUser(pm::types::User user) 
{
	// TODO: data integrity check;
	m_userStore.update(user);
}