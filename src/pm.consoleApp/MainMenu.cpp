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
}

void MainMenu::handle()
{
	system("cls");
	char ch;

	do
	{
		displayMenu();
		ch = _getch();

		auto it = find_if(items.begin(), items.end(),
			[&](pm::types::MenuItem item) { return item.key == ch; });

		if (it == items.end())
		{
			std::cout << "Invalid option!" << std::endl;
		}

		if ((*it).handler != NULL)
		{
			(*it).handler(NULL);
		}
		else 
		{
			break;
		}

	} while (true);

}

/*void* handleOption1(void*)
{

}
*/

void initAndShowMainMenu()
{
	MainMenu mainMenu;

	//mainMenu.items.push_back({ '1', "Item1", handleOption1 });
	mainMenu.items.push_back({ '2', "Item2", NULL});
	mainMenu.items.push_back({ '3', "Item3", NULL});

	mainMenu.handle();
}
