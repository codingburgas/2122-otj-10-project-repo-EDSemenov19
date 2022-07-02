#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include <string>
#include <vector>
#include <iostream>

void displayTasksManagement(nanodbc::connection& conn, pm::types::User user);