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
		pm::types::User getById(size_t id);
		pm::types::User getByUsername(std::string email, nanodbc::connection& conn);
		static std::vector<pm::types::User> get_all();
		void remove(size_t id) const;
		void update(pm::types::User user) const;
		static void displayUsers(nanodbc::connection& conn, pm::types::User& user);
		static nanodbc::result getAllElements(nanodbc::connection& conn);
	};
}
