#pragma once
#include <iostream>
#include <tuple>

using namespace std;

enum CoordinatesType {
	EUCLIDIAN,
	POLAR
};

class Point {
	private:
		double x, y;

		tuple<double, double> convert_to_polar();

	public:
		Point();
		Point(double x, double y);

		void add(const Point& p);
		void set_point(double x, double y);
		std::tuple<double, double> get_point(CoordinatesType type = CoordinatesType::EUCLIDIAN);
		void shift_X(double dx);
		void shift_Y(double dy);
		bool isEqual(const Point& p);
		~Point() {
			std::cout << "Point has been destructed\n";
		}
};

Point add1(Point a, Point b);
Point add2(const Point& a, const Point& b);