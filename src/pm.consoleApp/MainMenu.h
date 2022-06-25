#pragma once
#include "../pm.types/MenuItem.h"
#include <string>
#include <vector>

struct MainMenu
{
	std::vector<pm::types::MenuItem> items;

	static void* handleOption1(void*);
	static void displayMenu();
	void handle();
	static void handleOption1();
};

void initAndShowMainMenu();