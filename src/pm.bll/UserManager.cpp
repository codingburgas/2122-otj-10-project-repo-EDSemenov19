#include "pch.h"
#include "UserManager.h"
#include "AdminsManagement.h"
#include "MainMenu.h"
#include "../pm.tools/md5.h"

// Simple hashing via md5
std::string pm::bll::UserManager::hashString(const std::string& str)
{
	return std::string(md5(str));
}

void pm::bll::UserManager::registerNewUser(nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");

	std::string firstName{};
	std::string lastName{};
	std::string username{};
	std::string email{};
	short int age{};
	std::string password{};
	bool isAdmin{};

	std::cin.get();
	std::cout<<"Add User"<<std::endl;
	std::cout<<"\nEnter First Name: ";
	std::getline(std::cin, firstName);
	std::cout<<"\nEnter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "\nEnter username: ";
	std::getline(std::cin, username);
	std::cout << "\nEnter Email: ";
	std::getline(std::cin, email);
	std::cout<<"\nEnter Age: ";
	std::cin >> age;
	std::cin.get();
	std::cout<<"\nEnter Password: ";
	std::getline(std::cin, password);
	std::cout<<"\nIs admin (1 or 0): ";
	std::cin >> isAdmin;

	pm::types::User newUser{};
	newUser.firstName = firstName;
	newUser.lastName = lastName;
	newUser.username = username;
	newUser.email = email;
	newUser.age = age;
	newUser.passwordHash = hashString(password);
	newUser.isAdmin = isAdmin;

	pm::dal::UserStore::create(conn, user, newUser);

	pm::pl::AdminsManagement::userCreated(conn, user);
}

bool pm::bll::UserManager::checkForNoUsers(nanodbc::connection& conn) const
{
	nanodbc::result result = pm::dal::UserStore::getAllElements(conn);
	return (result.rows() == 0) ? false : true;
}

pm::types::User pm::bll::UserManager::loginUser(const std::string& username, std::string& password, nanodbc::connection& conn)
{

	if (checkForNoUsers(conn) && username == "admin" && password == "adminpass")
	{
		return pm::types::User("admin", "admin", "admin@pm.com", 0, "adminpass", true);
	}

	if (!m_userStore.checkByUsername(conn, username))
	{
		pm::pl::Login::userLoginFailed();
	}

	pm::types::User user = m_userStore.getByUsername(username, conn);

	std::string passHash = hashString(password);

	if (user.passwordHash != passHash)
	{
		pm::pl::Login::userLoginFailed();
	}

	return user;
}

std::vector<pm::types::User> pm::bll::UserManager::getRegisteredUsers()
{
	auto users = m_userStore.get_all();
	return users;
}

void pm::bll::UserManager::viewUserDetails(nanodbc::connection& conn, pm::types::User& user)
{
	std::vector<pm::types::User> users;
	std::cout << "Vector created!" << std::endl;
	std::cin.get();
	pm::dal::UserStore::displayAllUsers(conn, user, users);
	pm::pl::AdminsManagement::displayUser(conn, user, users);
}

void pm::bll::UserManager::removeUser(size_t id)
{
	//m_userStore.deleteUser();
}

void pm::bll::UserManager::updateUser(pm::types::User user) 
{
	// TODO: data integrity check;
	m_userStore.update(user);
}