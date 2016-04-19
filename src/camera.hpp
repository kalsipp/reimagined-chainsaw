#pragma once
#include <vector>
#include <algorithm>
#include "vector.hpp"
#include "point.hpp"
#include "line.hpp"
#include "canvas.hpp"
class Camera{
public:
	Camera();
	Camera(const Vector & pos, const Vector & rot);
	~Camera();
	Vector get_rel();
	Vector & get_position();
	Vector & get_rotation();
	void move(const Vector &);
	void rotate(const Vector &);
	void add_lines(std::vector<Line> &);
	void add_point(const Point &);
	void paint();
	Vector forward();
	Vector right();
	bool is_in_front(const Vector &);
private:
	void add_points(std::vector<Point> &);
	Vector * m_position = nullptr;
	Vector * m_rotation = nullptr;
	Canvas * m_canvas = nullptr;
	int m_fx = 20;
	int m_fy = 20;
	int m_s = 0;
};