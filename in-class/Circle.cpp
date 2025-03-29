#include "Circle.h"
#include <cmath>
const double PI = 3.14;
namespace Math {

	Circle::Circle() : Point(), radius(1.0) {}

	Circle::Circle(int x1, int y1, double r) : Point(x1, y1), radius(r) {}

	double Circle::getRadius() const
	{
		return radius;
	}

	double Circle::Area()
	{
		double result = 0.0;
		result = PI * pow(radius, 2);

		return result;
	}

	double Circle::Distance(Point b)
	{
		double result = 0.0;

		result = sqrt(pow((x - b.getX()), 2) + pow((y - b.getY()), 2));

		return result;
	}
}
