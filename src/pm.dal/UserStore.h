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
		static void create(nanodbc::connection& conn, pm::types::User& user, pm::types::User& newUser);
		static void showUser(nanodbc::connection& conn, pm::types::User& user);
		bool checkByUsername(nanodbc::connection& conn, std::string username);
		static pm::types::User getUserById(nanodbc::connection& conn, const unsigned short option);
		pm::types::User getByUsername(std::string email, nanodbc::connection& conn);
		static void deleteUser(nanodbc::connection& conn, pm::types::User& user);
		void update(pm::types::User user) const;
		static void getUsersToView(nanodbc::connection& conn, pm::types::User& user);
		static nanodbc::result getAllElements(nanodbc::connection& conn);
		static std::vector<pm::types::User> getAllUsers(nanodbc::connection& conn, pm::types::User& user);
	};
}
