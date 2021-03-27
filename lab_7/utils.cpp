#include <iostream>
#include <exception>
#include "utils.h"

using namespace std;

void Circle::setR(double r) {
	this->radius = r;
}
double Circle::getR() const {
	return radius;
}	
double Circle::square() const {
	return PI * radius * radius;
}
void Cone::setHeight(double h) {
	this->height = h;
}
double Cone::getHeight() const {
	return height;
}
double Cone::volume() const {
	return (1./3.) * PI * radius * radius * height;
}
double Sphere::volume() const {
	return (1./3.) * PI * radius * radius * radius;
}
void Cylinder::setHeight(double h) {
	this->height = h;
}
double Cylinder::getHeight() const {
	return height;
}
double Cylinder::volume() const {
	return PI * radius * radius * height;
}