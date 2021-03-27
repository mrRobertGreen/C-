#include <iostream>
#include <fstream>
#include <string>
#include "utils.h" 

using namespace std;

int main() {
	int m;
	string data;
	const string filename = "data.txt"; // файл был создан вручную
	cout << "Enter count of objects: ";
	cin >> m;
	ifstream fin(filename);
	string word;
	for (int i = 0; i < m; i++)
	{
		fin >> word;
		if (word == "Cone")
		{
			double r, h;
			fin >> r;
			fin >> h;
			Cone a(r, h);
			cout << "Cone was created\n";
			cout << "r = " << r << "\n";
			cout << "h = " << h << "\n";
			cout << "volume = " << a.volume() << "\n";
		}
		else if (word == "Circle")
		{
			double r;
			fin >> r;
			Circle a(r);
			cout << "Circle was created\n";
			cout << "r = " << r << "\n";
			cout << "square = " << a.square() << "\n";
		}
		else if (word == "Sphere")
		{
			double r, h;
			fin >> r;
			Sphere a(r);
			cout << "Sphere was created\n";
			cout << "r = " << r << "\n";
			cout << "volume = " << a.volume() << "\n";
		}
		else if (word == "Cylinder")
		{
			double r, h;
			fin >> r;
			fin >> h;
			Cylinder a(r, h);
			cout << "Cylinder was created\n";
			cout << "r = " << r << "\n";
			cout << "h = " << h << "\n";
			cout << "volume = " << a.volume() << "\n";
		}
		else {
			cout << "Undefined figure name\n";
		}
	}
	fin.close();

	return EXIT_SUCCESS;
}