#pragma once

#include <tuple>
#include <vector>
#include "line.hpp"
#include "rectangle.hpp"

class Block{
public:
	Block(Point );
	void get_points(std::vector<Point> & container);
	void move(Point &);
	void rotate(float x, float y, float z, Point * origin = nullptr);
	void rotate(Point, Point * origin = nullptr);
	Point get_size();
	void scale(Point);
	void scale(float, float, float);
	std::tuple<float, float, float> & position();
	Point get_middle();
	void get_points_rel(std::vector<Point> & container,Point & rotation, Point & position);
	void get_lines(std::vector<Line> & container);
private:
	void redraw_lines();
	Rectangle m_north;
	Rectangle m_south;
	Rectangle m_east;
	Rectangle m_west;
	std::vector<Line> m_lines;
	Point m_size = {60, 60, 60};
	Point m_rotation = {0,0,0};
	Point m_scale = {1,1,1};
	Point m_middle;
	Point m_position;

};