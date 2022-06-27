#pragma once
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include "../../lib/nanodbc/nanodbc.h"

struct Application
{
	void run(nanodbc::connection& conn);
};