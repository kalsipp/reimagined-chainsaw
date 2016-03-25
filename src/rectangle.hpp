#pragma once

#include <tuple>
#include <vector>
#include "point.hpp"
#include "line.hpp"
#include "pixel.hpp"
class Rectangle{
public:
	Rectangle();
	Rectangle(Line &, Line &);
	Rectangle(Point & pos, int size);
	Line & get_line(int nr);
	void rotate(float x, float y, float z, Point * = nullptr);
	void rotate(Point & rot, Point * = nullptr);
	void get_points(std::vector<Point> & container);
	void get_rotated(std::vector<Point> & container,Point &, Point &);
	void set_pixel(Pixel);
	friend std::ostream & operator<<(std::ostream & stream, Rectangle & p);
	Point & get_middle();
private:
	Line m_l1;
	Line m_l2;
	Pixel m_pixel_ref = Pixel(100);
	void set_middle();
	Point m_middle;
};