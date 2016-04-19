#include "vector.hpp"


Vector::Vector(){
	m_position = new std::tuple<float, float, float>(0,0,0);

}
Vector::Vector(float x, float y , float z){
	m_position = new std::tuple<float, float, float>(x,y,z);

}
Vector::Vector(const Vector & other){
	m_position = new std::tuple<float, float, float>(other.x(),other.y(),other.z());
}

Vector::~Vector(){
	if(m_position != nullptr){
		delete m_position;
		m_position = nullptr;
	}
}
Vector & Vector::operator=(const Vector & other){
	x() = other.x();
	y() = other.y();
	z() = other.z();
	return *this;
}

float & Vector::x(){
	return std::get<0>(*m_position);
}
float & Vector::y(){
	return std::get<1>(*m_position);

}
float & Vector::z(){
	return std::get<2>(*m_position);
}
float & Vector::x()const{
	return std::get<0>(*m_position);
}
float & Vector::y()const{
	return std::get<1>(*m_position);

}
float & Vector::z()const{
	return std::get<2>(*m_position);
}
void Vector::subtract(const Vector & other){
	x() -= other.x();
	y() -= other.y();
	z() -= other.z();
}
void Vector::add(const Vector & other){
	x() += other.x();
	y() += other.y();
	z() += other.z();
}
void Vector::add(float i, float j, float k){
	x() += i;
	y() += j;
	z() += k;
}

void Vector::mult(float val){
	x() *= val;
	y() *= val;
	z() *= val;
}

void Vector::mult(const Vector & other){
	x() *= other.x();
	y() *= other.y();
	z() *= other.z();
}

float Vector::dot(const Vector & other){
	float val = 0;
	val += 	x() * other.x();
	val += 	y() * other.y();
	val += 	z() * other.z();
	return val;
}
void Vector::set(const Vector & other){
	m_position = new std::tuple<float, float, float>(other.x(),other.y(),other.z());
}
void Vector::set(float x, float y, float z){
	m_position = new std::tuple<float, float, float>(x,y,z);
}

void Vector::rotate(float x, float y, float z){
	rotateYZ(x);
	rotateXZ(y);
	rotateXY(z);
}
void Vector::rotate(const Vector & rot){
	rotate(rot.x(), rot.y(), rot.z());
}
void Vector::rotate_around(float yz, float xz, float xy, const Vector & origin){
	Vector tempVector(*this);
	tempVector.subtract(origin);
	//m_start->set(origin);
	x() = origin.x();
	y() = origin.y();
	z() = origin.z();
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	//m_start->add(tempVector);
	x() += tempVector.x();
	y() += tempVector.y();
	z() += tempVector.z();
}
void Vector::rotate_around(const Vector & rot, const Vector & origin){
	rotate_around(rot.x(), rot.y(), rot.z(), origin);
}
void Vector::rotateXY(float degrees){
	float radians = degrees*to_rad;
	float old_x = x();
	float old_y = y();
	x() = (old_x*cos(radians)) - (old_y*sin(radians));
	y() = (old_x*sin(radians)) + (old_y*cos(radians));

}
void Vector::rotateXZ(float degrees){
	float radians = degrees*to_rad;
	float old_x = x();
	float old_z = z();

	x() = (old_x*cos(radians)) + (old_z*sin(radians));
	z() = -(old_x*sin(radians)) + (old_z*cos(radians));

}
void Vector::rotateYZ(float degrees){
	float radians = degrees*to_rad;
	float old_y = y();
	float old_z = z();

	y() = (old_y*cos(radians)) + (old_z*sin(radians));
	z() = -(old_y*sin(radians)) + (old_z*cos(radians));

}
void Vector::cross(const Vector & other){
	x() = y()*other.z() - z()*other.y();
	y() = z()*other.x() - x()*other.z();
	z() = x()*other.y() - y()*other.x();
}

float Vector::magnitude(){
	return sqrt(x()*x() + y()*y() + z()*z());
}
void Vector::normalize(){
	float mag = magnitude();
	x() /= mag;
	y() /= mag;
	z() /= mag;
}

std::ostream & operator<<(std::ostream & stream, const Vector & p){
	stream << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
	return stream;
}	
