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

void pm::bll::UserManager::registerNewUser(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");

	std::string firstName{};
	std::string lastName{};
	std::string username{};
	std::string email{};
	short int age{};
	std::string password{};
	bool isAdmin{};
	size_t creatorId{};

	std::cin.get();
	std::cout << "Add User" << std::endl;
	std::cout << "\nEnter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "\nEnter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "\nEnter username: ";
	std::getline(std::cin, username);
	std::cout << "\nEnter Email: ";
	std::getline(std::cin, email);
	std::cout << "\nEnter Age: ";
	std::cin >> age;
	std::cin.get();
	std::cout << "\nEnter Password: ";
	std::getline(std::cin, password);
	std::cout << "\nIs admin (1 or 0): ";
	std::cin >> isAdmin;
	creatorId = user.id;

	password = pm::bll::UserManager::hashString(password);

	pm::types::User newUser{
		firstName,
		lastName,
		username,
		email,
		age,
		password,
		isAdmin,
		creatorId
	};

	pm::dal::UserStore::create(conn, user, newUser);

	pm::pl::AdminsManagement::userCreated(conn, user);
}

bool pm::bll::UserManager::checkForNoUsers(nanodbc::connection& conn)
{
	nanodbc::result result = pm::dal::UserStore::getAllElements(conn);
	return (result.rows() == 0) ? true : false;
}

pm::types::User pm::bll::UserManager::loginUser(
	const std::string& username, std::string& password,
	nanodbc::connection& conn)
{

	if (pm::bll::UserManager::checkForNoUsers(conn)
		&& username == "admin" && password == "adminpass")
	{
		return pm::types::User(0, "admin", "admin",
			"adminadmin", "admin@pm.com", 0,
			"adminpass", true);
	}

	if (!pm::dal::UserStore::checkByUsername(conn, username))
	{
		pm::pl::Login::userLoginFailed();
	}

	pm::types::User user = pm::dal::UserStore::getByUsername(
		username, conn);

	std::string passHash = hashString(password);

	if (user.passwordHash != passHash)
	{
		pm::pl::Login::userLoginFailed();
	}

	return user;
}

void pm::bll::UserManager::viewUserDetails(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::vector<pm::types::User> users = pm::dal::UserStore::getAllUsers(
		conn, user);
	pm::pl::AdminsManagement::displayUsers(
		conn, user, users);
	std::cout << "User id to view: ";
	unsigned int option{};
	std::cin >> option;

	pm::types::User selectedUser = pm::dal::UserStore::getUserById(
		conn, option);

	pm::pl::AdminsManagement::displayUserDetails(
		conn, user, selectedUser);
}

void pm::bll::UserManager::editUser(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::vector<pm::types::User> users = pm::dal::UserStore::getAllUsers(
		conn, user);
	pm::pl::AdminsManagement::displayUsers(
		conn, user, users);

	std::cout << "User id to edit: ";
	unsigned int option{};
	std::cin >> option;

	pm::types::User selectedUser = pm::dal::UserStore::getUserById(
		conn, option);

	pm::pl::AdminsManagement::displayEditMenu(
		conn, user, selectedUser);
}

void pm::bll::UserManager::editName(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewFirstName(selectedUser);
	pm::dal::UserStore::updateFirstName(
		conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editSurname(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewLastName(selectedUser);
	pm::dal::UserStore::updateLastName(
		conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editUsername(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewUsername(selectedUser);
	pm::dal::UserStore::updateUsername(
		conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editEmail(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewEmail(selectedUser);
	pm::dal::UserStore::updateEmail(conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editPassword(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	const std::string newPassword = hashString(
		pm::pl::AdminsManagement::getNewPassword());
	selectedUser.passwordHash = newPassword;
	pm::dal::UserStore::updatePassword(
		conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editAge(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewAge(selectedUser);
	pm::dal::UserStore::updateAge(conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::editAdminStatus(nanodbc::connection& conn,
	pm::types::User& user,
	pm::types::User& selectedUser)
{
	pm::pl::AdminsManagement::getNewAdminStatus(selectedUser);
	pm::dal::UserStore::updateAdminStatus(
		conn, user, selectedUser);
	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::sortUsers(
	nanodbc::connection& conn, pm::types::User& user)
{
	unsigned short int option{};
	system("cls");
	auto users =
		pm::dal::UserStore::getAllUsers(conn, user);
	pm::pl::AdminsManagement::displayUsers(
		conn, user, users);
	pm::pl::AdminsManagement::displaySortMenu(conn, user, option);

	users.clear();
	pm::bll::UserManager::sortOptionHandler(
		conn, user, option, users);

	system("cls");
	pm::pl::AdminsManagement::displaySortedUsers(
		conn, user, users);

	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}

void pm::bll::UserManager::sortOptionHandler(
	nanodbc::connection& conn, pm::types::User& user, unsigned short option,
	std::vector<pm::types::User>& sortedUsers)
{
	switch (option)
	{
	case 1:
		sortedUsers = pm::dal::UserStore::sortByFirstName(
			conn, user);
		break;
	case 2:
		sortedUsers = pm::dal::UserStore::sortByLastName(conn, user);
		break;
	case 3:
		sortedUsers = pm::dal::UserStore::sortByUsername(conn, user);
		break;
	case 4:
		sortedUsers = pm::dal::UserStore::sortByEmail(conn, user);
		break;
	case 5:
		sortedUsers = pm::dal::UserStore::sortByAge(conn, user);
		break;
	case 6:
		sortedUsers = pm::dal::UserStore::sortByLastChange(
			conn, user);
		break;
	case 7:
		pm::pl::AdminsManagement::displayAdminPanel(conn, user);
		break;
	}
}

void pm::bll::UserManager::deleteUser(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::vector<pm::types::User> users
		= pm::dal::UserStore::getAllUsers(conn, user);
	pm::pl::AdminsManagement::displayUsers(conn,
		user, users);

	std::cout << "User id to delete: ";
	unsigned int option{};
	std::cin >> option;

	pm::types::User selectedUser
		= pm::dal::UserStore::getUserById(conn, option);

	char answer{};
	pm::pl::AdminsManagement::displayDeleteMenu(
		conn, user, selectedUser,
		answer);

	if (answer == 'y')
	{
		pm::dal::UserStore::deleteUser(
			conn, user, selectedUser);
	}
	else
	{
		system("cls");
		pm::pl::AdminsManagement::displayAdminPanel(conn, user);
	}

	pm::pl::AdminsManagement::updatedSuccessfully(conn, user);
}