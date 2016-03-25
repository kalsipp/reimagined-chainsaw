#pragma once
#define SCALING_FACTOR 0.5f


#include <vector>
#include "point.hpp"
#include "vector.hpp"
#include "pixel.hpp"
class Line{

public:
	Line();
	Line(int startx, int endx, int starty, int endy, int startz, int endz);
	Line(Point & start, Point & end);
	void get_points(std::vector<Point> & container);
	Vector get_vector();
	Point & get_start_point();
	Point & get_end_point();
	Point get_middle();
	void rotate(float = 0, float = 0, float = 0, Point* = nullptr);
	void scale(float, float, float);
	void scale(Point);
	void set_pixel(Pixel &);
	void rotate(Point & rot, Point * = nullptr);
	void get_points_rel(std::vector<Point> & container,Point &, Point &);
	friend std::ostream & operator<<(std::ostream & stream, Line & p);
private:
	Point m_start;
	Point m_end;
	Pixel m_pixel_ref = Pixel(11);
	int m_start_x, m_start_y, m_start_z;
	int m_end_x, m_end_y, m_end_z;
};