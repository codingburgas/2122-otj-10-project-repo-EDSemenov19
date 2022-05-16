#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef void(*MenuHandler)();

struct MenuItem
{
	char key;
	string text;
	MenuHandler handler;
};

void MenuOption1()
{
	
}

void MenuOption2()
{
	
}

void displayFunction(std::vector<MenuItem>& menuItems)
{
	for (auto item : menuItems)
	{
		cout << item.key << ". " << item.text << endl;
	}
}

int main()
{
	vector<MenuItem> menuItems =
	{
		{'1', "Start", MenuOption1},
		{'2', "Help", MenuOption2},
		{'3', "Exit", nullptr},
	};

	displayFunction(menuItems);

	char choice;

	cin >> choice;

	if (const auto it = ranges::find_if(menuItems,
	                                    [&choice](const MenuItem& item) {return item.key == choice; }); it != menuItems.end())
	{
		if (const auto handler = (*it).handler; handler != nullptr)
		{
			handler();
		}
		else
		{
			cout << "Exit\n";
		}
	}
	else
	{
		cout << "Invalid option!\n";
	}
}