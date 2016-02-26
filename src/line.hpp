#pragma once

#include <vector>
#include "point.hpp"
class Line{


public:
	Line();
	Line(int startx, int endx, int starty, int endy, int startz, int endz);
	Line(Point & start, Point & end);
	void get_points(std::vector<Point> & container);
	void rotate(float = 0, float = 0, float = 0, Point* = nullptr);
private:
	Point m_start;
	Point m_end;
	int m_start_x, m_start_y, m_start_z;
	int m_end_x, m_end_y, m_end_z;
};