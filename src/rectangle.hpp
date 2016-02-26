#pragma once

#include <tuple>
#include <vector>
#include "point.hpp"
#include "line.hpp"
class Rectangle{
public:
	Rectangle();
	Rectangle(Line &, Line &, Line &, Line &);
	Rectangle(Point & pos, int size);
	void rotate(float x, float y, float z, Point * = nullptr);
	void get_points(std::vector<Point> & container);
private:
	Line m_l1;
	Line m_l2;
	Line m_l3;
	Line m_l4;
};