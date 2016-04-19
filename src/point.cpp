#include "point.hpp"
Point::Point(){
	m_position = new Vector(0,0,0);
	m_pixel = new Pixel(0);
}

Point::Point(const Point & other){
	m_position = new Vector(other.x(), other.y(), other.z());
	m_pixel = new Pixel(other.get_pixel());
}

Point::Point(float x, float y, float z, const Pixel & pix){
	m_position = new Vector(x,y,z);
	m_pixel = new Pixel(pix);
}
Point::Point(const Vector & other, const Pixel & pix){
	m_position = new Vector(other);
	m_pixel = new Pixel(pix);
}

Point::Point(float x, float y, float z, int val) {
	m_position = new Vector(x,y,z);
	m_pixel = new Pixel(val);
}
Point::Point(const Vector & other, int val){
	m_position = new Vector(other);
	m_pixel = new Pixel(val);
}

Point::~Point(){
	if(m_position != nullptr){
		delete m_position;
		m_position = nullptr;
	}
	if(m_pixel != nullptr){
		delete m_pixel;
		m_pixel = nullptr;
	}
}

Point & Point::operator=(const Point & other){
	m_position->set(other.x(), other.y(), other.z());
	m_pixel->set(other.get_pixel());
	return *this;
}

float & Point::x(){
	return m_position->x();
}
float & Point::y(){
	return m_position->y();
}
float & Point::z(){
	return m_position->z();
}
float & Point::x()const{
	return m_position->x();
}
float & Point::y()const{
	return m_position->y();
}
float & Point::z()const{
	return m_position->z();
}
Pixel & Point::get_pixel(){
	return *m_pixel;
}
Pixel & Point::get_pixel()const{
	return *m_pixel;
}
Vector & Point::get_position(){
	return *m_position;
}
Vector & Point::get_position()const{
	return *m_position;
}
void Point::move(float x, float y, float z){
	m_position->add(x,y,z);
}
void Point::move(const Vector & other){
	m_position->add( other);
}
void Point::set_position(float x, float y, float z){
	m_position->set(x,y,z);
}
void Point::set_position(const Vector & other){
	m_position->set(other);
}
void Point::set_pixel(const Pixel & pix){
	m_pixel->set(pix);
}
void Point::set_pixel(int val){
	m_pixel->set(val);
}


void Point::paint(Canvas & canvas){
	int i = round(x());
	int j = round(y());
	//std::cout << "Painting at (" << i << ","<< j << ")." << std::endl;
	canvas.add_pixel(*m_pixel, i, j);
}