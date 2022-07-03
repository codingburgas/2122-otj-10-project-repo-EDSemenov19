#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include "../pm.types/User.h"
#include <string>
#include <vector>

struct MainMenu
{
	std::vector<pm::types::MenuItem> items;

	 void* handleOption1(void*);
	 static void displayMenu(nanodbc::connection& conn, pm::types::User& user);
	static void displayUserMenu(nanodbc::connection& conn, pm::types::User& user);
	static void displayAdminMenu(nanodbc::connection& conn, pm::types::User& user);
	static void handle(nanodbc::connection& conn, pm::types::User& user, unsigned short int option);
	 void handleOption1();
};

void initAndShowMainMenu();