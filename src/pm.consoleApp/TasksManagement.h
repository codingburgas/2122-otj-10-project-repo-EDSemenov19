#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include <string>
#include <vector>
#include <iostream>

namespace pm::pl
{
	struct TasksManagement
	{
		static void displayTasksManagement(nanodbc::connection& conn, pm::types::User user);
	};
}