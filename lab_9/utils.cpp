#include <iostream>
#include "utils.h"
#include <cmath>
#include <algorithm>

using namespace std;

double degToRad(double deg) {
	return deg * (PI / 180.);
}
double radToDeg(double rad) {
	return rad * 57.3;
}

double Polygon::getArea() const {
	return 0.5 * n * side * getInnerR();
}
double Polygon::getPerimeter() const {
	return side * n;
}
double Polygon::getInnerR() const {
	return side / (2 * tan(PI / n));
}
double Polygon::getOuterR() const {
	return side / (2 * sin(PI / n));
}
void Polygon::print() {
	cout << "Polygon\n";
	cout << "Area: " << getArea() << "\n";
	cout << "Perimeter: " << getPerimeter() << "\n";
	cout << "Outer radius: " << getOuterR() << "\n";
	cout << "Inner radius: " << getInnerR() << "\n";
}

double Square::getArea() const {
	return side * side;
}
void Square::print() {
	cout << "Square\n";
	cout << "Area: " << getArea() << "\n";
	cout << "Perimeter: " << getPerimeter() << "\n";
	cout << "Outer radius: " << getOuterR() << "\n";
	cout << "Inner radius: " << getInnerR() << "\n";
}

double Triangle::getArea() const {
	const double p = getPerimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::getPerimeter() const {
	return a + b + c;
}
double Triangle::getInnerR() const {
	const double p = getPerimeter() / 2;
	return sqrt((p - a) * (p - b) * (p - c) / p);
}
double Triangle::getOuterR() const {
	return (a * b * c) / 4 * getArea();
}
string Triangle::type() {
	double t = c;
	c = max(max(a, b), c);
	if (a == c) a = t;
	if (b == c) b = t;

	if (c * c == a * a + b * b)
		return "rectangular triangle";
	else if (c * c < a * a + b * b)
		return "acute-angle triangle";
	else return "obtuse triangle";
}
void Triangle::print() {
	cout << "Trinagle\n";
	cout << "Type: " << type() << "\n";
	cout << "Area: " << getArea() << "\n";
	cout << "Perimeter: " << getPerimeter() << "\n";
	cout << "Outer radius: " << getOuterR() << "\n";
	cout << "Inner radius: " << getInnerR() << "\n";
}

bool lessArea(const Circled& f1, const Circled& f2) {
	return f1.getArea() < f2.getArea();
}
bool lessPerimeter(const Circled& f1, const Circled& f2) {
	return f1.getPerimeter() < f2.getPerimeter();
}
bool lessInnerR(const Circled& f1, const Circled& f2) {
	return f1.getInnerR() < f2.getInnerR();
}

void sort(Circled** arr, int len, compare func) {
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (func(*arr[j + 1], *arr[j]))
				swap(arr[j], arr[j + 1]);
		}
	}
}
void printArr(Circled** arr, int len) {
	for (auto item: arr)
		item->print();
}