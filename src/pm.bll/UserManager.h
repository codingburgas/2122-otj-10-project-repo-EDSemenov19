#pragma once
#include "pch.h"
#include "../pm.dal/UserStore.h"

namespace pm::bll {
	struct UserManager
	{
		pm::dal::UserStore m_userStore;
		static std::string hashString(const std::string& str);
		static void registerNewUser(nanodbc::connection& conn, pm::types::User& user);
		bool checkForNoUsers(nanodbc::connection& conn) const;
		pm::types::User loginUser(const std::string& username, std::string& password, nanodbc::connection& conn);
		std::vector<pm::types::User> getRegisteredUsers();
		static void viewUserDetails(nanodbc::connection& conn, pm::types::User& user);
		static void editUser(nanodbc::connection& conn, pm::types::User& user);

		static void editName(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editSurname(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editUsername(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editEmail(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editPassword(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editAge(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);
		static void editAdminStatus(nanodbc::connection& conn, pm::types::User& user, pm::types::User& selectedUser);

		void seedDatabase();

		void removeUser(size_t id);

		void updateUser(pm::types::User);
	};
}