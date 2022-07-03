#pragma once
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "../../lib/nanodbc/nanodbc.h"

namespace pm::pl
{
	struct Application
	{
		void run(nanodbc::connection& conn);
	};
}