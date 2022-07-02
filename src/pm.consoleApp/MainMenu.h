#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "User.h"
#include <string>
#include <vector>

struct MainMenu
{
	std::vector<pm::types::MenuItem> items;

	 void* handleOption1(void*);
	 void displayMenu(nanodbc::connection& conn, pm::types::User& user);
	 void displayUserMenu(nanodbc::connection& conn, pm::types::User& user);
	static void displayAdminMenu(nanodbc::connection& conn, pm::types::User& user);
	static void handle(nanodbc::connection& conn, pm::types::User& user, unsigned short option);
	 void handleOption1();
};

void initAndShowMainMenu();