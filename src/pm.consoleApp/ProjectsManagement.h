#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include <iostream>
#include <string>
#include <vector>

void displayProjectsManagement(nanodbc::connection& conn, pm::types::User user);