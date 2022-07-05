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
		size_t creatorId{};

		User() = default;

		User(size_t m_id, std::string m_firstName, std::string m_lastName,
			std::string m_username, std::string m_email, short int m_age,
			std::string m_passwordHash, bool m_isAdmin) :
			id(m_id), firstName(m_firstName), lastName(m_lastName),
			username(m_username), email(m_email), age(m_age),
			passwordHash(m_passwordHash), isAdmin(m_isAdmin)
		{}

		User(size_t m_id, std::string m_firstName, std::string m_lastName,
			std::string m_username, std::string m_email,
			const short int m_age, std::string m_password, time_t m_createdOn,
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
			std::string m_username, std::string m_email, short int m_age,
			std::string m_password, bool m_isAdmin, size_t m_creator_id) :
			firstName(std::move(m_firstName)),
			lastName(std::move(m_lastName)),
			username(std::move(m_username)),
			email(std::move(m_email)),
			age(m_age),
			passwordHash(std::move(m_password)),
			isAdmin(m_isAdmin),
			creatorId(m_creator_id)
		{}
	};
}