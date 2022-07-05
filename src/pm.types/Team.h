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
		time_t createdOn{};
		size_t creatorId{};
		time_t lastChange{};
		size_t lastChangerId{};

		Team() = default;

		Team(size_t m_id, std::string m_title,
			time_t m_createdOn, size_t m_creatorId,
			time_t m_lastChange, size_t m_lastChangerId)
			: id(m_id), title(std::move(m_title)),
			createdOn(m_createdOn), creatorId(m_creatorId),
			lastChange(m_lastChange), lastChangerId(m_lastChangerId)
		{}

		Team(std::string m_title, size_t m_creatorId)
			: title(std::move(m_title)), creatorId(m_creatorId)
		{}

		Team(size_t m_id, std::string m_title)
			: id(m_id), title(std::move(m_title))
		{}



	};
}