#pragma once
#include <utility>

#include "pch.h"

namespace pm::types
{
	class Project
	{
	public:
		size_t id{};
		std::string title{};
		std::string description{};
		time_t createdOn{};
		size_t idOfCreator{};
		time_t lastChanged{};
		size_t idOfLastChanger{};

		Project() = default;

		Project(std::string m_title, std::string m_description,
			size_t m_idOfCreator, size_t m_idOfLastChanger) :
			title(std::move(m_title)),
			description(std::move(m_description)),
			idOfCreator(m_idOfCreator), idOfLastChanger(m_idOfLastChanger)
		{}

		Project(size_t m_id, std::string m_title, std::string m_description,
			time_t m_createdOn, size_t m_idOfCreator,
			time_t m_lastChanged, size_t m_idOfLastChanger) :
			id(m_id),
			title(std::move(m_title)),
			description(std::move(m_description)),
			createdOn(m_createdOn), idOfCreator(m_idOfCreator),
			lastChanged(m_lastChanged), idOfLastChanger(m_idOfLastChanger)
		{}
	};
}