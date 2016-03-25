#include "vector.hpp"
#include <cassert>

Vector::Vector(float x, float y, float z){
 m_position = std::make_tuple(x, y, z);
}
Vector::Vector(std::tuple<float, float, float> n){
  m_position = n;
}
Vector::~Vector(){
}
std::tuple<float, float, float> & Vector::position(){
  return m_position;
}
float & Vector::x(){
  return  std::get<0>(m_position);
}

float & Vector::y(){
  return  std::get<1>(m_position);
}
float & Vector::z(){
  return  std::get<2>(m_position);
}
Vector Vector::operator-(Vector & other){
  std::tuple<float, float, float> t(m_position);
  Vector p(t);
  p.subtract(other);
  return p;
}
Vector Vector::operator+(Vector & other){
  std::tuple<float, float, float> t(m_position);
  Vector p(t);
  p.add(other);
  return p;
}


Vector Vector::operator*(double num){
 std::tuple<float, float, float> t = std::make_tuple(std::get<0>(m_position)*num,
  std::get<1>(m_position)*num, 
  std::get<2>(m_position)*num);
 Vector p(t);
 return p;
}

Vector Vector::cross(Vector other){
  float i = y()*other.z() - z()*other.y();
  float j = z()*other.x() - x()*other.z();
  float k = x()*other.y() - y()*other.x();
  Vector v (i,j,k);
  return v;
}
void Vector::normalize(){
  float k = x()*x() + y()*y() + z()*z();
  if(k != 0){
    std::get<0>(m_position) = std::get<0>(m_position)/k;
    std::get<1>(m_position) = std::get<1>(m_position) /k;
    std::get<2>(m_position) = std::get<2>(m_position) /k;
  }

}

Vector Vector::operator*(Vector other){
  std::tuple<float, float, float> t(m_position);
  std::get<0>(t) *= std::get<0>(other.position());
  std::get<1>(t) *= std::get<1>(other.position());
  std::get<2>(t) *= std::get<2>(other.position());
  Vector p(t);
  return p;
}


void Vector::subtract(Vector & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}

void Vector::subtract(Point & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}

void Vector::add(Vector & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}


void Vector::set_position(float x, float y, float z){
  m_position = std::make_tuple(x, y, z);
}
float Vector::magnitude(){
  float el1 = std::get<0>(m_position)*std::get<0>(m_position);
  float el2 = std::get<1>(m_position)*std::get<1>(m_position);
  float el3 = std::get<2>(m_position)*std::get<2>(m_position);
  return fabs(el1)+fabs(el2)+fabs(el3);
}

void Vector::scale(float x, float y, float z){
  std::get<0>(m_position) *= x;
  std::get<1>(m_position) *= y;
  std::get<2>(m_position) *= z;
}


void Vector::rotateXY(float degrees){
  float radians = M_PI*degrees/180;
  float old_x = std::get<0>(m_position);
  float old_y = std::get<1>(m_position);
  std::get<0>(m_position) = (old_x*cos(radians)) - (old_y*sin(radians));
  std::get<1>(m_position) = (old_x*sin(radians)) + (old_y*cos(radians));
}

void Vector::rotateXZ(float degrees){
  float radians = M_PI*degrees/180;
  float old_x = std::get<0>(m_position);
  float old_z = std::get<2>(m_position);
  std::get<0>(m_position) = (old_x*cos(radians)) + (old_z*sin(radians));
  std::get<2>(m_position) = -(old_x*sin(radians)) + (old_z*cos(radians));
}
void Vector::rotateYZ(float degrees){
  float radians = M_PI*degrees/180;
  float old_y = std::get<1>(m_position);
  float old_z = std::get<2>(m_position);
  std::get<1>(m_position) = (old_y*cos(radians)) + (old_z*sin(radians));
  std::get<2>(m_position) = -(old_y*sin(radians)) + (old_z*cos(radians));
}

std::ostream & operator<<(std::ostream & stream, Vector & p){
  stream << "(" << std::get<0>(p.position()) << "," << std::get<1>(p.position()) << "," << std::get<2>(p.position()) << ")";
  return stream;
}