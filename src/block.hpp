#pragma once

#include <tuple>
#include <vector>
#include "line.hpp"

class Block{
public:
	Block(const Vector &);
	Block(const Block &);
	~Block();
	Block & operator=(const Block &);
	void get_points(std::vector<Point> & container);
	void move(const Vector &);
	void rotate(float x, float y, float z);
	void rotate(const Vector &);
	void rotate_around(float, float, float, const Vector &);
	void rotate_around(const Vector &, const Vector &);
	const Vector & get_size()const;
	void scale(const Vector&);
	void scale(float, float, float);
	Vector & position();
	Vector & position()const;
	Vector get_middle()const;
	//void get_points_rel(std::vector<Point> & container,Point & rotation, Point & position);
	void get_lines(std::vector<Line> & container);
private:
	void redraw_lines();
	std::vector<Line> * m_lines = nullptr;
	Vector m_size = {10, 10, 10};
	Vector m_rotation = {0,0,0};
	Vector m_scale = {1,1,1};
	Vector * m_middle = nullptr;
	Vector * m_position = nullptr;

};