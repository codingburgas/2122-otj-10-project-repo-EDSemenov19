#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "AdminsManagement.h"
#include "../pm.bll/UserManager.h"
#include "User.h"
#include <string>
#include <vector>
#include <iostream>

namespace pm::pl
{
	struct TasksManagement
	{
		static void displayTasksManagement(nanodbc::connection& conn, pm::types::User user);
		static void handleTaskManagement(nanodbc::connection& conn, pm::types::User user, unsigned short int option);
	};
}