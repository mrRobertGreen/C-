#pragma once

const double PI = 3.14;

class Circle {
protected:
	double radius;	
public:
	Circle(double r) : radius(r) {};
	Circle() : radius(1) {};
	void setR(double r);
	double getR() const;
	double square() const;
};

class Cone : public Circle {
private:
	double height;
public:
	Cone(double r, double h) : Circle(r), height(h) {};
	Cone() : Circle(), height(1) {};
	void setHeight(double h);
	double getHeight() const;
	double volume() const;
};

class Sphere : public Circle {
public:
	Sphere(double r) : Circle(r) {};
	Sphere() : Circle() {};
	double volume() const;
};

class Cylinder : public Circle {
private:
	double height;
public:
	Cylinder(double r, double h) : Circle(r), height(h) {};
	Cylinder() : Circle(), height(1) {};
	void setHeight(double h);
	double getHeight() const;
	double volume() const;
};	