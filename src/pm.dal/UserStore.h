#pragma once
#include "pch.h"
#include <iostream>
#include "../pm.types/User.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::dal
{
	// CRUD - CREATE, READ, UPDATE, DELETE

	struct UserStore
	{
		static void create(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& newUser);
		static void showUser(
			nanodbc::connection& conn, pm::types::User& user);
		bool checkByUsername(
			nanodbc::connection& conn, std::string username);
		static pm::types::User getUserById(
			nanodbc::connection& conn, const unsigned short option);
		pm::types::User getByUsername(std::string email,
			nanodbc::connection& conn);
		static void deleteUser(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& userToDelete);
		static void getUsersToView(
			nanodbc::connection& conn, pm::types::User& user);
		static nanodbc::result getAllElements(nanodbc::connection& conn);
		static std::vector<pm::types::User> getAllUsers(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> getAllSortedUsers(
			nanodbc::result& result);

		static void updateFirstName(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updateLastName(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updateUsername(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updateEmail(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updatePassword(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updateAge(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		static void updateAdminStatus(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);

		static std::vector<pm::types::User> sortByFirstName(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> sortByLastName(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> sortByUsername(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> sortByEmail(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> sortByAge(
			nanodbc::connection& conn, pm::types::User& user);
		static std::vector<pm::types::User> sortByLastChange(
			nanodbc::connection&, pm::types::User& user);
	};
}
