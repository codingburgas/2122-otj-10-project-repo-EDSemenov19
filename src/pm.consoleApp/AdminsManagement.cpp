#include "AdminsManagement.h"



void pm::pl::AdminsManagement::displaySortedUsers(nanodbc::connection& conn,
	pm::types::User& user,
	std::vector<pm::types::User>& sortedUsers)
{
	std::cout << "Displaying sorted users!\n";
	tabulate::Table table;
	table.add_row({ "ID", "First Name", "Last Name",
		"Username", "Email", "Age", "Admin Status",
		"Last Change", "Created On" });

	for (const auto& element : sortedUsers)
	{
		char createdOn[26];
		char lastChange[26];
		ctime_s(createdOn, sizeof createdOn,
			&element.createdOn);
		ctime_s(lastChange, sizeof lastChange,
			&element.lastChange);

		table.add_row({ std::to_string(element.id),
			element.firstName,element.lastName, element.username,
			element.email, std::to_string(element.age),
			std::to_string(element.isAdmin), createdOn,
			lastChange });
	}

	for (size_t i = 0; i < 9; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}

	std::cout << table << std::endl;

	std::cout << "\nBack? (y/n)\n";
	char answer;
	std::cin >> answer;
	if (answer == 'y')
	{
		pm::pl::AdminsManagement::displayAdminPanel(conn, user);
	}
	else
	{
		std::cout << "Exiting...\n";
		exit(0);
	}
}

void pm::pl::AdminsManagement::displaySortMenu(nanodbc::connection& conn,
	pm::types::User user, unsigned short int& option)
{
	std::cout << "\nWhat do you want to sort by?\n \n1. Name \n2. Surname";
	std::cout << "\n3. Username \n4. Email \n5. Age \n6. Last Changed";
	std::cout << "\n7. Back \n\nOption: ";
	std::cin >> option;
	std::cout << std::endl;
}

void pm::pl::AdminsManagement::displayDeleteMenu(
	nanodbc::connection& connection, pm::types::User user,
	pm::types::User userToDelete, char& answer)
{
	system("cls");
	std::cout << "Are you sure you want to delete user " <<
		userToDelete.username << "? (y/n)" << std::endl;

	std::cin >> answer;
}

void pm::pl::AdminsManagement::displayEditMenu(
	nanodbc::connection& conn, pm::types::User user,
	pm::types::User selectedUser)
{
	system("cls");
	std::cout << "Edit user" << '\n';



	std::cout << "User details" << '\n' << '\n';

	tabulate::Table table;
	table.add_row({ "First name", "Last name",
		"Username", "Email", "Age" });
	table.add_row({ (selectedUser.firstName),
		(selectedUser.lastName), (selectedUser.username),
		(selectedUser.email), std::to_string(selectedUser.age) });

	for (size_t i = 0; i < 5; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}

	std::cout << table << '\n' << std::endl;

	std::cout << "1. Edit Name\n";
	std::cout << "2. Edit Surname\n";
	std::cout << "3. Edit username\n";
	std::cout << "4. Edit email\n";
	std::cout << "5. Edit password\n";
	std::cout << "6. Edit age\n";
	std::cout << "7. Edit Admin Status\n\n";

	std::cout << "Option: ";
	unsigned short int option{};
	std::cin >> option;

	editMenuHandler(conn, user, selectedUser, option);
}

void pm::pl::AdminsManagement::displayUserDetails(nanodbc::connection& conn,
	pm::types::User user, pm::types::User selectedUser)
{
	system("cls");

	char createdOn[26];
	char lastChange[26];
	ctime_s(createdOn, sizeof createdOn,
		&selectedUser.createdOn);
	ctime_s(lastChange, sizeof lastChange,
		&selectedUser.lastChange);

	std::cout << "User details" << '\n' << '\n';

	tabulate::Table table;

	table.add_row({ "Id", "Name", "Surname", "Username",
		"Email", "Age", "Is Admin", "Created On", "Last Changed", "Created By" });
	table.add_row({ std::to_string(selectedUser.id),
		selectedUser.firstName, selectedUser.lastName,
		selectedUser.username, selectedUser.email,
		std::to_string(selectedUser.age),
		std::to_string(selectedUser.isAdmin),
		createdOn, lastChange, std::to_string(selectedUser.creatorId) });

	for (size_t i = 0; i < 10; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}

	std::cout << table << std::endl;

	std::cout << "\nGo back? (y/n)" << '\n';
	char choice;
	std::cin >> choice;

	if (choice == 'y')
		displayAdminPanel(conn, user);
	else
		exit(0);
}

void pm::pl::AdminsManagement::displayAdminPanel(nanodbc::connection& conn,
	pm::types::User& user)
{
	system("cls");
	std::cout << "1. Add user" << '\n';
	std::cout << "2. Edit user" << '\n';
	std::cout << "3. Delete user" << '\n';
	std::cout << "4. View User Details" << '\n';
	std::cout << "5. Sort Users" << '\n';
	std::cout << "6. Back" << '\n' << std::flush;

	std::cout << "Option: ";
	unsigned short int option{};
	std::cin >> option;

	pm::pl::AdminsManagement::handleAdminsManagement(
		conn, user, option);
}

void pm::pl::AdminsManagement::handleAdminsManagement(
	nanodbc::connection& conn, pm::types::User& user,
	unsigned short int& option)
{
	switch (option)
	{
	case 1:
		pm::bll::UserManager::registerNewUser(conn, user);
		break;
	case 2:
		pm::bll::UserManager::editUser(conn, user);
		break;
	case 3:
		pm::bll::UserManager::deleteUser(conn, user);
		break;
	case 4:
		pm::bll::UserManager::viewUserDetails(conn, user);
		break;
	case 5:
		pm::bll::UserManager::sortUsers(conn, user);
		break;
	case 6:
		pm::pl::MainMenu::displayAdminMenu(conn, user);
		break;
	default:
		std::cout << "Invalid option" << std::endl;
		break;
	}
}

void pm::pl::AdminsManagement::editMenuHandler(
	nanodbc::connection& conn, pm::types::User& user,
	pm::types::User& selectedUser, const unsigned short& option)
{
	switch (option)
	{
	case 1:	//Edit Name
		pm::bll::UserManager::editName(
			conn, user, selectedUser);
		break;
	case 2: //Edit Surname
		pm::bll::UserManager::editSurname(
			conn, user, selectedUser);
		break;
	case 3: //Edit username
		pm::bll::UserManager::editUsername(
			conn, user, selectedUser);
		break;
	case 4: //Edit email
		pm::bll::UserManager::editEmail(
			conn, user, selectedUser);
		break;
	case 5: //Edit password
		pm::bll::UserManager::editPassword(
			conn, user, selectedUser);
		break;
	case 6: //Edit age
		pm::bll::UserManager::editAge(
			conn, user, selectedUser);
		break;
	case 7: //Edit Admin Status
		pm::bll::UserManager::editAdminStatus(
			conn, user, selectedUser);
		break;
	}
}

void pm::pl::AdminsManagement::getNewFirstName(pm::types::User& selectedUser)
{
	system("cls");
	std::cout << "Current First Name: " << selectedUser.firstName << '\n';
	std::cout << "New First Name: ";
	std::cin.get();
	getline(std::cin, selectedUser.firstName);
}

void pm::pl::AdminsManagement::getNewLastName(pm::types::User& selectedUser)
{
	system("cls");
	std::cout << "Current Last Name: " << selectedUser.lastName << '\n';
	std::cout << "New Last Name: ";
	std::cin.get();
	getline(std::cin, selectedUser.lastName);
}

void pm::pl::AdminsManagement::getNewUsername(pm::types::User& selectedUser)
{
	system("cls");
	std::cout << "Current username: " << selectedUser.username << '\n';
	std::cout << "New username: ";
	std::cin.get();
	getline(std::cin, selectedUser.username);
}

void pm::pl::AdminsManagement::getNewEmail(pm::types::User& selectedUser)
{
	system("cls");
	std::cout << "Current email: " << selectedUser.email << '\n';
	std::cout << "New email: ";
	std::cin.get();
	getline(std::cin, selectedUser.email);
}

std::string pm::pl::AdminsManagement::getNewPassword()
{
	system("cls");
	std::cout << "Enter your new password: ";
	std::cin.get();
	std::string newPassword{};
	getline(std::cin, newPassword);
	return newPassword;
}

void pm::pl::AdminsManagement::getNewAge(pm::types::User& selectedUser)
{
	//std::cin.get();
	//std::cin.clear();
	system("cls");
	std::cout << "Current age: " << selectedUser.age << '\n';
	std::cout << "New age: ";
	std::cin >> selectedUser.age;
	std::cout << "current age" << ": " << selectedUser.age << '\n';
}

void pm::pl::AdminsManagement::getNewAdminStatus(pm::types::User& selectedUser)
{
	system("cls");
	if (selectedUser.isAdmin)
		std::cout << "IsAdmin : Yes" << '\n';
	else
		std::cout << "IsAdmin : No" << '\n';
	std::cout << "New Admin Status (0 or 1): " << '\n';
	std::cin >> selectedUser.isAdmin;
}

void pm::pl::AdminsManagement::updatedSuccessfully(
	nanodbc::connection& conn, pm::types::User& user)
{
	system("cls");
	std::cout << "Update successful" << '\n';
	std::cout << "\nGo back? (y/n)" << '\n';
	char choice;
	std::cin >> choice;

	if (choice == 'y')
		displayAdminPanel(conn, user);
	else
		exit(0);
}

void pm::pl::AdminsManagement::displayUsers(
	nanodbc::connection& conn, pm::types::User& userToDisplay,
	std::vector<pm::types::User>& users)
{
	tabulate::Table table;
	table.add_row({ "ID", "First Name", "Last Name",
		"Username", "Email", "Age", "IsAdmin" });
	for (const auto& element : users)
	{
		table.add_row({ std::to_string(element.id),
			element.firstName, element.lastName, element.username,
			element.email, std::to_string(element.age),
			std::to_string(element.isAdmin) });
	}
	for (size_t i = 0; i < 7; ++i) {
		table[0][i].format()
			.font_color(tabulate::Color::magenta)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}
	std::cout << table << std::endl;
}

void pm::pl::AdminsManagement::userCreated(nanodbc::connection& conn,
	pm::types::User& user)
{
	std::cout << "\nUser created successfully!" << std::endl;
	std::cout << "Go back? (y/n)" << std::endl;
	char option;
	std::cin >> option;

	if (option == 'y')
	{
		system("cls");
		pm::pl::AdminsManagement::displayAdminPanel(conn, user);
	}
	else
	{
		system("cls");
		exit(0);
	}
}

void pm::pl::AdminsManagement::logout(nanodbc::connection& conn,
	pm::types::User& user)
{
	std::cin.get();
	system("cls");
	pm::pl::Application app;
	app.run(conn);
}