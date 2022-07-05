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
	};
}