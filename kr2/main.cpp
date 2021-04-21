#include <iostream>
#include "header.h"

int main() {

	int len = 3;
	Student* arr = new Student[len];

	Student s1 = Student("Ivan", 5, 1);
	Student s2 = Student("Vasiliy", 3, 2);
	Student s3 = Student("Alex", 5, 5);

	arr[0] = s1;
	arr[1] = s2;
	arr[2] = s3;

	Student from_the_highest_course = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i].print();
		if (less_course(from_the_highest_course, arr[i]))
		{
			from_the_highest_course = arr[i];
		}
	}
	std::cout << "Student from the highest course:\n";
	from_the_highest_course.print();

	return EXIT_SUCCESS;
}