#include "pch.h"
#include "CppUnitTest.h"
#include <tuple>
#include "../lab_2/utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2tests
{
	TEST_CLASS(lab2tests)
	{
	public:
		
		TEST_METHOD(set_point_test)
		{
			Point a = Point(3, 5);
			double res_x1 = 7, res_y1 = 8;
			a.set_point(res_x1, res_y1);
			double x1, y1;
			tie(x1, y1) = a.get_point();
			Assert::AreEqual(x1, res_x1);
			Assert::AreEqual(y1, res_y1);

			double res_x2 = 7.3, res_y2 = 8.5;
			a.set_point(res_x2, res_y2);
			double x2, y2;
			tie(x2, y2) = a.get_point();
			Assert::AreEqual(x2, res_x2);
			Assert::AreEqual(y2, res_y2);
		}
		TEST_METHOD(shift_X_Y_test)
		{
			Point a = Point(3, 5);
			double res_x1 = 7, res_y1 = 3;
			a.shift_X(4);
			a.shift_Y(-2);
			double x1, y1;
			tie(x1, y1) = a.get_point();
			Assert::AreEqual(x1, res_x1);
			Assert::AreEqual(y1, res_y1);

			Point b = Point(3.3, 5.5);
			double res_x2 = 3.4, res_y2 = 5.4;
			b.shift_X(0.1);
			b.shift_Y(-0.1);
			double x2, y2;
			tie(x2, y2) = b.get_point();
			Assert::AreEqual(x2, res_x2);
			Assert::AreEqual(y2, res_y2);
		}
		TEST_METHOD(is_equal_test)
		{
			Point a = Point(3, 5);
			Point b = Point(3, 5);
			Assert::IsTrue(a.is_equal(b));

			Point c = Point(3.1, 5.1);
			Point d = Point(3.1, 5.1);
			Assert::IsTrue(c.is_equal(d));
		}
		TEST_METHOD(distance_to_test)
		{
			Point a = Point(0, 0);
			Point b = Point(0, 5);
			double res_1 = 5;
			Assert::AreEqual(a.distance_to(b), res_1);

			a.set_point(0, 0);
			b.set_point(4, 3);
			double res_2 = 5;
			Assert::AreEqual(a.distance_to(b), res_2);

			a.set_point(3, 3);
			b.set_point(3, 3);
			double res_3 = 0;
			Assert::AreEqual(a.distance_to(b), res_3);
		}
		TEST_METHOD(add_test)
		{
			Point a = Point(0, 0);
			double res_x1 = 3, res_y1 = 5;
			Point b = Point(res_x1, res_y1);
			a.add(b);
			double x1, y1;
			tie(x1, y1) = a.get_point();
			Assert::AreEqual(res_x1, x1);
			Assert::AreEqual(res_y1, y1);

			a.set_point(0, 0);
			double res_x2 = 3.1, res_y2 = 5.1;
			b.set_point(res_x2, res_y2);
			a.add(b);
			double x2, y2;
			tie(x2, y2) = a.get_point();
			Assert::AreEqual(res_x2, x2);
			Assert::AreEqual(res_y2, y2);
		}
	};
}
