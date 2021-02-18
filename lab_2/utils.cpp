#include <exception>
#include <cmath>
#include "utils.h"

using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
	cout << "Point has been constructed\n";
}
Point::Point(double x, double y) : x(x), y(y) {
	cout << "Point has been constructed\n";
}
void Point::set_point(double x, double y) {
	this->x = x;
	this->y = y;
}
tuple<double, double> Point::convert_to_polar() const {
	double r = sqrt(x * x + y * y);
	double tan = tanh(y / x);
	double angle = atanh(tan);
	return tuple<double, double>(r, angle);
}
tuple<double, double> Point::get_point(CoordinatesType type) const {
	switch (type)
	{
	case EUCLIDIAN:
		return tuple<double, double>(x, y);
	case POLAR:
		return convert_to_polar();
	default:
		throw exception("type is not defined");
	}
}
void Point::shift_X(double dx) {
	x += dx;
}
void Point::shift_Y(double dy) {
	y += dy;
}
bool Point::is_equal(const Point& p) {
	return p.x == x && p.y == y;
}
Point add1(Point a, Point b) {
	double x1, x2, y1, y2;
	tie(x1, y1) = a.get_point();
	tie(x2, y2) = b.get_point();
	double resX = x1 + x2;
	double resY = y1 + y2;
	return Point(resX, resY);
}
Point add2(const Point& a, const Point& b) {
	double x1, x2, y1, y2;
	tie(x1, y1) = a.get_point();
	tie(x2, y2) = b.get_point();
	double resX = x1 + x2;
	double resY = y1 + y2;
	return Point(resX, resY);
}
void Point::print() {
	cout << "Point coordinates:\n";
	cout << "x = " << x << "\n";
	cout << "y = " << y << "\n";
}
double Point::distance_to(Point& point) {
	double x, y;
	tie(x, y) = point.get_point();
	double distance = sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
	return distance;
}
void Point::add(Point& p) {
	double x, y;
	tie(x, y) = p.get_point();
	this->x += x;
	this->y += y;
}