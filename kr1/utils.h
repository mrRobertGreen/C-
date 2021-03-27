#pragma once
#include <iostream>

using namespace std;

class Measurer {
private:
	int m;
	int cm;

	Measurer& to_normal();
public:
	Measurer() : m(0), cm(0) {};
	Measurer(int m, int cm);
	
	int to_centimetres() const;
	bool operator<(const Measurer& other);
	bool operator==(const Measurer& other);
	Measurer& operator+=(int cm);
	Measurer operator-(const Measurer& size);

	friend ostream& operator << (ostream& out, const Measurer& size);
	friend istream& operator >> (istream& in, Measurer& size);
};