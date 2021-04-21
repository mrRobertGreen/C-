#pragma once
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926535;

class Shape {
public:
	virtual void print() = 0; // выдать информацию о типе фигуры
	virtual double getArea() const = 0; // найти площадь фигуры
	virtual double getPerimeter() const = 0; // найти периметр
};

class Circled : public Shape {
public:
	virtual double getInnerR() const = 0; // радиус вписанной окружности
	virtual double getOuterR() const = 0; // радиус описанной окружности
};

class Polygon : public Circled {
protected:
	double side;
	int n;
public:
	Polygon(double side, int n) {
		this->n = n < 3 ? 3 : n;
		this->side = side <= 0 ? 1 : side;
	};
	Polygon() : side(1), n(4) {};
	double getArea() const override;
	double getPerimeter() const override;
	double getInnerR() const override;
	double getOuterR() const override;
	void print() override;
};

class Square : public Polygon {
public:
	Square(double side) {
		this->side = side <= 0 ? 1 : side;
		n = 4;
	};
	Square() : Polygon(1, 4) {};
	double getArea() const override;
	void print() override;
};

class Triangle : public Circled {
private:
	double a;
	double b;
	double c;
public:
	Triangle(double a, double b, double c) {
		if ((a > 0 && b > 0 && c > 0) && (a + b > c && b + c > a && a + c > b)) {
			this->a = a;
			this->b = b;
			this->c = c;
		}
		else {
			cout << "Incorrect sides values. Fields were filled by default value (1)\n";
			this->a = 1;
			this->b = 1;
			this->c = 1;
		}
	};
	Triangle(double a) {
		this->a = a <= 0 ? 1 : a;
		this->b = a <= 0 ? 1 : a;
		this->c = a <= 0 ? 1 : a;
	};
	Triangle() : a(1), b(1), c(1) {}
	double getArea() const override;
	double getPerimeter() const override;
	double getInnerR() const override;
	double getOuterR() const override;
	string type();
	void print() override;
};

bool lessArea(const Circled& f1, const Circled& f2);
bool lessPerimeter(const Circled& f1, const Circled& f2);
bool lessInnerR(const Circled& f1, const Circled& f2);
double degToRad(double deg);
double radToDeg(double rad);

typedef bool (*compare) (const Circled& f1, const Circled& f2);

void sort(Circled** arr, int len, compare func);

void printArr(Circled** arr, int len);

