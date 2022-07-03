#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include <string>
#include <iostream>
#include <vector>

namespace pm::pl
{
	struct TeamsManagement
	{
		static void displayTeamsManagement(nanodbc::connection& conn, pm::types::User user);
	};
}