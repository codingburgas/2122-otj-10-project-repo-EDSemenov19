#pragma once
#include "pch.h"
#include "../pm.dal/UserStore.h"

namespace pm::bll {
	namespace UserManager
	{
		std::string hashString(const std::string& str);
		void registerNewUser(
			nanodbc::connection& conn, pm::types::User& user);
		bool checkForNoUsers(
			nanodbc::connection& conn);
		pm::types::User loginUser(
			const std::string& username, std::string& password,
			nanodbc::connection& conn);
		void viewUserDetails(
			nanodbc::connection& conn, pm::types::User& user);
		void editUser(nanodbc::connection& conn,
			pm::types::User& user);

		void editName(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editSurname(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editUsername(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editEmail
		(nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editPassword(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editAge(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);
		void editAdminStatus(
			nanodbc::connection& conn, pm::types::User& user,
			pm::types::User& selectedUser);

		void sortOptionHandler(nanodbc::connection& conn,
			pm::types::User& user, unsigned short option,
			std::vector<pm::types::User>& sortedUsers);
		void sortUsers(nanodbc::connection& conn,
			pm::types::User& user);
		void deleteUser(nanodbc::connection& conn,
			pm::types::User& user);

	}
}