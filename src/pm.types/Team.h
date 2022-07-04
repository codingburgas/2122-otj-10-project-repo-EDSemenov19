#pragma once
#include <utility>

#include "pch.h"

namespace pm::types
{
	class Team
	{
	public:
		size_t id{};
		std::string title{};
		std::string description{};
		time_t createdOn{};
		size_t idOfCreator{};
		time_t lastChange{};
		std::vector<std::string> usersEmail{};

		Team() = default;

		Team(std::string m_title, std::string m_description)
		: title(std::move(m_title)), description(std::move(m_description))
		{}
			

		Team(size_t m_id, std::string m_title, std::string m_description, time_t m_createdOn, time_t m_lastChange, std::vector<std::string> m_usersEmail)
			: id(m_id), title(std::move(m_title)), description(std::move(m_description)), createdOn(m_createdOn), lastChange(m_lastChange), usersEmail(
				  std::move(m_usersEmail))
		{
		}

	};
}