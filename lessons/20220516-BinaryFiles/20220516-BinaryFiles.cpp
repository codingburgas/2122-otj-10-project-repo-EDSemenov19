#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct User
{
	int i;
	bool cond;
};

//#pragma pack(1);

int main()
{
	// cout << __cplusplus << endl;
	// fstream file("file1.bin", ios::in | ios::binary);
	// fopen
	// fclose
	// fread
	// fwrite
	// fseek
	// I/O operations

	fstream file("file1.bin", ios::in | ios::binary);

	int a = 65;
	int arr[] = { 65, 66, 67 };
	User u1{ 65, true };
	vector <User> users{
		{65, true},
		{66, false},
		{67, true}
	};

	if (file.is_open())
	{
		// file.write(reinterpret_cast<char*>(&arr), sizeof(arr));
		file.write(reinterpret_cast<char*>(users.data()), users.size() * sizeof(User));
		file.close();
	}
}