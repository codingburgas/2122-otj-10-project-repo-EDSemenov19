#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "MainMenu.h"
#include "login.h"
#include "Application.h"
#include "User.h"
#include "../pm.bll/UserManager.h"
#include <string>
#include <vector>
#include <iostream>

void displayUsersManagement(nanodbc::connection& conn, pm::types::User& user);
void handleUsersManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int& option);