#include "Point.h"
#include <cmath>

namespace Math {

	Point::Point() : x(0), y(0) {}

	Point::Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}

	void Point::setPoint(const int x1, const int y1)
	{
		x = x1;
		y = y1;
	}

	int Point::getX() const
	{
		return x;
	}

	int Point::getY() const
	{
		return y;
	}

	double Point::Area()
	{
		return 0;
	}

	double Point::Distance(Point b)
	{
		double result = 0.0;

		result = sqrt(pow((x - b.x), 2) + pow((y - b.y), 2));

		return result;
	}
}
