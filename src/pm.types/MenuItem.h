#pragma once
#include "pch.h"
#include <string>

namespace pm::types
{
	typedef void* (*MENU_ITEM_HANDLER)(void*);

	struct MenuItem
	{
		char key;
		std::string text;
		MENU_ITEM_HANDLER handler;
	};

}