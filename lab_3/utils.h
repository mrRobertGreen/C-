#pragma once
#include <iostream>

class Fract {
private:
	int numen, denom;

public:
	Fract() : numen(0), denom(1) {}
	Fract(int a, int b = 1) :numen(a) {
		denom = (b != 0) ? b : 1;
	}
	Fract operator+(const Fract& other);
	friend std::ostream& operator << (std::ostream&, const Fract&);
};
