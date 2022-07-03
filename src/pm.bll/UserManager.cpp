#include "pch.h"
#include "UserManager.h"
#include "UsersManagement.h"
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
}

void pm::bll::UserManager::userCreated(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout << "User created successfully!" << std::endl;
	std::cout << "Go back? (y/n)" << std::endl;
	char option;
	std::cin >> option;

	if (option == 'y')
	{
		system("cls");
		displayUsersManagement(conn, user);
	}
	else
	{
		system("cls");
		exit(0);
	}
}


void pm::bll::UserManager::registerUser(std::string firstName, 
	std::string lastName, uint8_t age, std::string email, 
	std::string password)
{
	pm::types::User user;
	// TODO: Check passwordHash requirements

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
	//user.passwordHash = hashString(passwordHash);
	
	//m_userStore.create(conn, user);
}

bool pm::bll::UserManager::checkForNoUsers(nanodbc::connection& conn) const
{
	return (pm::dal::UserStore::getAllElements( conn)) ? true : false;
}

pm::types::User pm::bll::UserManager::loginUser(const std::string& username, std::string& password, nanodbc::connection& conn)
{

	if (checkForNoUsers(conn) && username == "admin" && password == "adminpass")
	{
		return pm::types::User("admin", "admin", "admin@pm.com", 0, "adminpass", true);
	}

	pm::types::User user = m_userStore.getByUsername(username, conn);

	std::string passHash = hashString(password);

	if (user.passwordHash != passHash)
	{
		throw std::logic_error("Invalid passwordHash!");
	}

	return user;
}

std::vector<pm::types::User> pm::bll::UserManager::getRegisteredUsers()
{
	auto users = m_userStore.get_all();
	return users;
}

void pm::bll::UserManager::viewUser(nanodbc::connection& conn, pm::types::User& user)
{
	std::cout<<"Users: "<<std::endl;
	//pm::dal::UserStore::displayUsers(conn, user);
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