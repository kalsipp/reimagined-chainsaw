#pragma once

#include "pixel.hpp"
#include "vector.hpp"
#include "canvas.hpp"
/*
A container class for a point and a vector
*/

class Point{
public:
	Point();
	Point(float, float, float, const Pixel &);
	Point(const Vector &, const Pixel &);
	Point(float, float, float, int);
	Point(const Vector &, int);
	Point(const Point &);
	Point & operator=(const Point &);
	~Point();
	float & x();
	float & y();
	float & z();
	float & x()const;
	float & y()const;
	float & z()const;
	Pixel & get_pixel();
	Pixel & get_pixel()const;
	Vector & get_position();
	Vector & get_position()const;
	void move(float, float, float);
	void move(const Vector &);
	void set_position(float, float, float);
	void set_position(const Vector &);
	void set_pixel(const Pixel &);
	void set_pixel(int);

	void paint(Canvas & canvas);

private:
	Pixel * m_pixel = nullptr;
	Vector * m_position = nullptr;
};