#pragma once
#include <utility>

#include "pch.h"

namespace pm::types
{
	class Task
	{
	public:
		size_t id{};
		std::string title{};
		std::string description{};
		time_t createdOn{};
		size_t creatorId{};
		time_t lastChange{};
		size_t lastChangerId{};

		Task() = default;

		Task(std::string m_title, std::string m_description,
			size_t m_creatorId, size_t m_lastChangerId) :
			title(std::move(m_title)),
			description(std::move(m_description)),
			creatorId(m_creatorId),
			lastChangerId(m_lastChangerId)
		{}

		Task(size_t m_id, std::string m_title, std::string m_description,
			time_t m_createdOn, size_t m_creatorId, time_t m_lastChange,
			size_t m_lastChangerId) :
			id(m_id),
			title(std::move(m_title)),
			description(std::move(m_description)),
			createdOn(m_createdOn),
			creatorId(m_creatorId),
			lastChange(m_lastChange),
			lastChangerId(m_lastChangerId)
		{}

	};
}