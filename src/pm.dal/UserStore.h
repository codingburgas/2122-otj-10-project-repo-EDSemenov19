#pragma once
#include "pch.h"
#include "../pm.types/User.h"

namespace pm::dal
{
	// CRUD - CREATE, READ, UPDATE, DELETE

	struct UserStore
	{
		void create(pm::types::User& user);
		pm::types::User getById(size_t id);
		pm::types::User getByEmail(std::string email);
		static std::vector<pm::types::User> get_all();
		void remove(size_t id) const;
		void update(pm::types::User user) const;
	};
}
