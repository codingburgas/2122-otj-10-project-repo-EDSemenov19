#pragma once
#include "pch.h"
#include "../pm.dal/UserStore.h"

namespace pm::bll
{
	struct UserManager
	{
		pm::dal::UserStore m_userStore;
		static std::string hashString(const std::string& str);

		void registerUser(std::string firstName, std::string lastName, uint8_t age, 
			std::string email, std::string password);
		bool checkForNoUsers(nanodbc::connection& conn) const;
		pm::types::User loginUser(const std::string& username, std::string& password);
		std::vector<pm::types::User> getRegisteredUsers();

		void seedDatabase();

		void removeUser(size_t id);

		void updateUser(pm::types::User);
	};
}