#pragma once

#include <tuple>
#include <math.h>
#include <vector>
#include <iostream>

/*
   General class to hold a 3 coordinate position and to perform different transformations
*/

class Vector{
public: 
	Vector();
	Vector(float, float, float);
	Vector(const Vector &);
	~Vector();
	Vector & operator=(const Vector &);
	float & x();
	float & y();
	float & z();
	float & x()const;
	float & y()const;
	float & z()const;
	void subtract(const Vector &);
	void add(const Vector &);
	void add(float, float, float);
	void mult(float);
	void mult(const Vector &);
	float dot(const Vector &);
	void set(const Vector &);
	void set(float, float, float);
	void rotate(float, float, float);
	void rotate(const Vector &);
	void rotate_around(float, float, float, const Vector &);
	void rotate_around(const Vector &, const Vector &);
	void rotateXY(float degrees);
	void rotateXZ(float degrees);
	void rotateYZ(float degrees);
	void cross(const Vector & other);
	float magnitude();
	void normalize();

	friend std::ostream & operator<<(std::ostream & stream, const Vector & p);

private:
	std::tuple<float, float, float> * m_position = nullptr;
	float to_rad = M_PI/180;
};