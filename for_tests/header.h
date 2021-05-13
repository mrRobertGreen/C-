#pragma once
#include <iostream>

using namespace std;

template<typename InIt1, typename InIt2>
bool my_equal(InIt1 first, InIt1 last, InIt2 first2) {
	while (first != last) {
		if (*first != *first2)
			return false;
		++first;
		++first2;
	}
	return true;
}
