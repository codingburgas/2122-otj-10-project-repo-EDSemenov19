#pragma once
#include <utility>

#include "pch.h"

namespace pm::types
{
	class User
	{
	public:
		size_t id{};
		std::string firstName{};
		std::string lastName{};
		std::string username{};
		std::string email{};
		short int age{};
		std::string passwordHash{};
		time_t createdOn{};
		time_t lastChange{};
		bool isAdmin{};

		User() = default;

		User(size_t m_id, std::string m_firstName, std::string m_lastName,
			std::string m_username, std::string m_email,
			const short int m_age, std::string m_password,time_t m_createdOn,
			time_t m_lastChange, const bool m_isAdmin) :
			id(m_id),
			firstName(std::move(m_firstName)),
			lastName(std::move(m_lastName)),
			username(std::move(m_username)),
			email(std::move(m_email)),
			age(m_age),
			passwordHash(std::move(m_password)),
			createdOn(m_createdOn),
			lastChange(m_lastChange),
			isAdmin(m_isAdmin)
		{}

		User(std::string m_firstName, std::string m_lastName,
			std::string m_email, const short int m_age,
			std::string m_password, const bool m_isAdmin) :
			firstName(std::move(m_firstName)),
			lastName(std::move(m_lastName)),
			email(std::move(m_email)),
			age(m_age),
			passwordHash(std::move(m_password)),
			isAdmin(m_isAdmin)
		{}


	};
}