#pragma once
#include "pch.h"
#include <iostream>
#include "../pm.types/User.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::dal
{
	// CRUD - CREATE, READ, UPDATE, DELETE

	namespace UserStore
	{
		time_t getTime(nanodbc::timestamp& ts1);

		void create(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& newUser);
		void showUser(
			nanodbc::connection& conn, pm::types::User& user);
		bool checkByUsername(
			nanodbc::connection& conn, std::string username);
		pm::types::User getUserById(
			nanodbc::connection& conn, const unsigned short option);
		pm::types::User getByUsername(std::string email,
			nanodbc::connection& conn);
		void deleteUser(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& userToDelete);
		void getUsersToView(
			nanodbc::connection& conn, pm::types::User& user);
		nanodbc::result getAllElements(nanodbc::connection& conn);
		std::vector<pm::types::User> getAllUsers(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> getAllSortedUsers(
			nanodbc::result& result);

		void updateFirstName(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updateLastName(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updateUsername(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updateEmail(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updatePassword(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updateAge(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void updateAdminStatus(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);

		std::vector<pm::types::User> sortByFirstName(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> sortByLastName(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> sortByUsername(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> sortByEmail(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> sortByAge(
			nanodbc::connection& conn, pm::types::User& user);
		std::vector<pm::types::User> sortByLastChange(
			nanodbc::connection&, pm::types::User& user);
	}
}
