#pragma once
#include <vector>

#include "vector.hpp"
#include "point.hpp"
#include "pixel.hpp"

/*
Class defining a line. Contains two points with arbritary names. Generates line from these.
*/

class Line{
public:
	Line();
	Line(const Vector & start, const Vector & end);
	Line(const Vector & start, const Vector & end, const Pixel &);
	Line(const Line &);
	~Line();
	Line & operator= (const Line & other);

	void get_points(std::vector<Point> & container)const;
	//void get_points_rel(std::vector<Vector> & container, const Vector &, const Vector &);
	Vector get_vector()const; //return endpoint-startpoint
	Vector & get_start_point(); 
	Vector & get_end_point();
	Vector & get_start_point()const; 
	Vector & get_end_point()const;
	Vector get_middle()const;
	void move(const Vector &);
	void rotate_around(const Vector &, const Vector &);
	void rotate_around(float, float, float, const Vector &);
	void rotate(float, float, float);
	void rotate(const Vector &);
	float magnitude()const;
	void scale(float, float, float);
	void scale(const Vector &);
	void set_pixel(const Pixel &);
	Pixel & get_pixel()const;
private:
	Vector * m_start = nullptr;
	Vector * m_end = nullptr;
	Pixel * m_pixel_ref = nullptr;

};