#include <iostream>
#include "utils.h" 

using namespace std;

int main() {
	Point a = Point(1, 3);
	double radius = get<0>(a.get_point(POLAR));
	double angle = get<1>(a.get_point(POLAR));
	double x = get<0>(a.get_point());
	double y = get<1>(a.get_point());
	cout << "Polar: " << radius << ", " << angle << "\n";
	cout << "Euclidian: " << x << ", " << y << "\n";

	return EXIT_SUCCESS;
}