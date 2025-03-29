#pragma once
#include "Point.h"

namespace Math {
	class Circle : public Point
	{
	private:
		double radius;
	public:
		Circle();
		Circle(int, int, double);
		double getRadius() const;
		double Area() override;
		double Distance(Point) override;
	};
}
