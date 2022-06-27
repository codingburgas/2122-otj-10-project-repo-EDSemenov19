#pragma once
#include "../pm.types/MenuItem.h"
#include "../../lib/nanodbc/nanodbc.h"
#include <string>
#include <vector>

struct MainMenu
{
	std::vector<pm::types::MenuItem> items;

	 void* handleOption1(void*);
	 void displayMenu(nanodbc::connection& conn);
	void handle(nanodbc::connection& conn);
	 void handleOption1();
};

void initAndShowMainMenu();