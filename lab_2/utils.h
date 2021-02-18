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

		tuple<double, double> convert_to_polar() const;

	public:
		Point();
		Point(double x, double y);

		void add(Point& p);
		void set_point(double x, double y);
		std::tuple<double, double> get_point(CoordinatesType type = CoordinatesType::EUCLIDIAN) const;
		void shift_X(double dx);
		void shift_Y(double dy);
		bool is_equal(const Point& p);
		void print();
		double distance_to(Point& point);
		~Point() {
			std::cout << "Point has been destructed\n";
		}
};

Point add1(Point a, Point b);
Point add2(Point& a, Point& b);