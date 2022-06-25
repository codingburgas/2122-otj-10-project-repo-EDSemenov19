#include "MainMenu.h"
#include <conio.h>
#include <algorithm>
#include <iostream>

void* MainMenu::handleOption1(void*)
{
	return nullptr;
}

void MainMenu::displayMenu()
{
	std::cout << "Main menu! " << std::endl;
}

void MainMenu::handle()
{
	system("cls");

	do
	{
		displayMenu();
		char ch = _getch();

		auto it = find_if(items.begin(), items.end(),
			[&](const pm::types::MenuItem item) { return item.key == ch; });

		if (it == items.end())
		{
			std::cout << "Invalid option!" << std::endl;
		}

		if ((*it).handler != nullptr)
		{
			(*it).handler(nullptr);
		}
		else 
		{
			break;
		}

	} while (true);

}


void initAndShowMainMenu()
{
	MainMenu mainMenu;

	mainMenu.items.push_back({ '1', "Item1",   });
	mainMenu.items.push_back({ '2', "Item2", nullptr});
	mainMenu.items.push_back({ '3', "Item3", nullptr});

	mainMenu.handle();
}
