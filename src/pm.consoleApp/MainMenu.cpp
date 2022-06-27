#include "MainMenu.h"
#include <conio.h>
#include <algorithm>
#include <iostream>

void* MainMenu::handleOption1(void*)
{
	return nullptr;
}

void MainMenu::displayMenu(nanodbc::connection& conn)
{
	std::cout << "Main menu! " << std::endl;

	std::cin.get();
}

void MainMenu::handle(nanodbc::connection& conn)
{
	system("cls");

	do
	{
		displayMenu(conn);
		char ch = _getch();

		std::cout << "Login: ";
		std::string login{};
		std::string password{};
		getline(std::cin, login);
		std::cout << '\n' << "Password: ";
		getline(std::cin, password);

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


void initAndShowMainMenu(nanodbc::connection& conn)
{
	MainMenu mainMenu;

	//mainMenu.items.push_back({ '1', "Item1",   });
	mainMenu.items.push_back({ '2', "Item2", nullptr});
	mainMenu.items.push_back({ '3', "Item3", nullptr});

	mainMenu.handle(conn);
}
