#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using UgaBugaPtr = bool(*)(int, int);


namespace bg::burgas::pgkpi
{
	class string
	{
	};
}

double* foo_bar(const int item_count)
{
	const auto arr = new double[item_count];

	return arr;
}

void sort_ascending(vector<int>& items)
{
	/*for(auto item = items.begin(); item != items.end(); ++item)
	{
		cout << *item;
	}*/

	for (size_t i = 0; i < items.size(); ++i)
	{
		for (size_t k = 0; k < items.size(); k++)
		{
			if (items[i] > items[k])
			{
				std::swap(items[k], items[i]);
			}
		}
	}
}

bool uga_buga_ascending(int a, int b)
{
	return a > b;
}

bool uga_buga_descending(int a, int b)
{
	return a < b;
}

void sort_descending(vector<int>& items, UgaBugaPtr pred)
{
	for (size_t i = 0; i < items.size(); ++i)
	{
		for (size_t k = i + 1; k < items.size(); k++)
		{
			if (pred(items[i], items[k]))
			{
				std::swap(items[k], items[i]);
			}
		}
	}
}

void show_vector(const vector<int>& items)
{
	for (const auto num : items)
	{
		cout << num << ' ';
	}
	cout << '\n';
}

struct Student
{
	string name;
	uint8_t age;
};

int main()
{
	vector<Student> students{{"S1", 16}, {"S2", 17}};

	std::sort(students.begin(), students.end(),
	          [](const Student& s1, const Student& s2) { return s1.age > s2.age; });


	/*const UgaBugaPtr fn = uga_buga_ascending;

	cout << fn(5, 6);

	vector<int> numbers{4, 6, 2, 8, 9, 1};

	show_vector(numbers);*/

	// C++20
	/*std::ranges::sort(numbers,
		[](const int a, const int b) { return a > b; });

	std::sort(numbers.begin(), numbers.end(),
		[](const int a, const int b) {return a > b; });

	show_vector(numbers);

	int c = 3;

	auto lambda2 = [&c](const int a) { return a + c++; };

	int d = lambda2(10);

	sort_ascending(numbers);

	show_vector(numbers);

	sort_descending(numbers, [](const int a, const int b) { return a > b; });

	show_vector(numbers);
	string str1;
	bg::burgas::pgkpi::string str2;
	const double* tmp = foo_bar(10);

	delete[] tmp;*/
}