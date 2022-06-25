#pragma once
#include "../pm.types/MenuItem.h"
#include <string>
#include <vector>

struct MainMenu
{
	std::vector<pm::types::MenuItem> items;

	void* handleOption1(void*);
	void displayMenu();
	void handle();
};

void initAndShowMainMenu();