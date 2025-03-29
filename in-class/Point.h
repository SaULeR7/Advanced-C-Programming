#pragma once
namespace Math {
	class Point
	{
	protected:
		int x;
		int y;
	public:
		Point();
		Point(int, int);
		void setPoint(int, int);
		int getX() const;
		int getY() const;
		virtual double Area();
		virtual double Distance(Point);
	};
}

