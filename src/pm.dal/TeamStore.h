#pragma once
#include "pch.h"
#include <iostream>
#include "../pm.types/User.h"
#include "../pm.types/Team.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::dal
{
	struct TeamStore
	{
		static void registerTeam(nanodbc::connection& conn, pm::types::User& user, pm::types::Team& team);
	};
}