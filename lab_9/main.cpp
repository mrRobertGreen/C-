#include <iostream>
#include <fstream>
#include <cmath>
#include "utils.h"

using namespace std;

int main() {
	int m;
	string data;
	const string filename = "data.txt"; // файл был создан вручную
	cout << "Enter count of objects: ";
	cin >> m;
	Circled** arr = new Circled *[m];
	int j = 0;
	ifstream fin(filename);
	string word;
	for (int i = 0; i < m; i++)
	{
		fin >> word;
		if (word == "Polygon")
		{
			double side, n;
			fin >> side;
			fin >> n;
			Polygon *a = new Polygon(side, n);
			cout << "Polygon was created\n";
			cout << "side = " << side << "\n";
			cout << "n = " << n << "\n";
			a->print();
			arr[j] = a;
			++j;
		}
		else if (word == "Triangle")
		{
			double a, b, c;
			fin >> a;
			fin >> b;
			fin >> c;
			Triangle *A = new Triangle(a, b, c);
			cout << "Triangle was created\n";
			cout << "a = " << a << "\n";
			cout << "b = " << b << "\n";
			cout << "c = " << c << "\n";
			A->print();
			arr[j] = A;
			++j;
		}
		else if (word == "Square")
		{
			double a;
			fin >> a;
			Square *A = new Square(a);
			cout << "Square was created\n";
			cout << "a = " << a << "\n";
			A->print();
			arr[j] = A;
			++j;
		}
		else {
			cout << "Undefined figure name\n";
		}
	}
	fin.close();

	cout << "BEFORE AREA SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getArea() << "\n";
	sort(arr, m, lessArea);
	cout << "AFTER AREA SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getArea() << "\n";

	cout << "BEFORE INNER RADIUS SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getInnerR() << "\n";
	sort(arr, m, lessInnerR);
	cout << "AFTER INNER RADIUS SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getInnerR() << "\n";

	cout << "BEFORE PERIMETER SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getPerimeter() << "\n";
	sort(arr, m, lessPerimeter);
	cout << "AFTER PERIMETER SORT\n";
	for (int i = 0; i < m; i++)
		cout << "arr[" << i << "]: " << arr[i]->getPerimeter() << "\n";

	return EXIT_SUCCESS;
}