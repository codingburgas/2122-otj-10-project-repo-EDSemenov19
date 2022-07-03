#pragma once
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/MenuItem.h"
#include "../pm.bll/UserManager.h"
#include "../pm.consoleApp/MainMenu.h"
#include <iostream>
#include "../../lib/nanodbc/nanodbc.h"
#include "MainMenu.h"
#include "login.h"
#include "Application.h"
#include "../pm.types/User.h"
#include "../pm.bll/UserManager.h"
#include <string>
#include <vector>
#include <iostream>

void displayUsersManagement(nanodbc::connection& conn, pm::types::User& user);
//void displayUsers(nanodbc::connection& conn, pm::types::User& user);
void handleUsersManagement(nanodbc::connection& conn, pm::types::User& user, unsigned short int& option);
void logout(nanodbc::connection& conn, pm::types::User& user);