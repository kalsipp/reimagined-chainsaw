#include "point.hpp"

Point::Point(float x, float y, float z){
 m_position = std::make_tuple(x, y, z);
 m_pixel = Pixel(100);
}
Point::Point(std::tuple<float, float, float> n){
  m_position = n;
  m_pixel = Pixel(100);
}
Point::Point(std::initializer_list<float> l){
  std::vector<float> v;
  v.insert(v.end(), l.begin(), l.end()); 
  m_position = std::make_tuple(v[0], v[1], v[2]);
}
const std::tuple<float, float, float> & Point::position()const{
  return m_position;
}

float & Point::x(){
  return  std::get<0>(m_position);
}

float & Point::y(){
  return  std::get<1>(m_position);
}
float & Point::z(){
  return  std::get<2>(m_position);
}
std::tuple<float, float, float> & Point::position(){
  return m_position;
}
void Point::paint(Canvas & canvas){
  int x = round(std::get<0>(m_position));
  int y = round(std::get<1>(m_position));
  canvas.add_pixel(m_pixel, x, y);
}

void Point::set_position(float x, float y, float z){
  m_position = std::make_tuple(x, y, z);
}
void Point::set_position(Point & other){
  m_position = other.position();
}

void Point::set_position(std::tuple<float, float, float> other){
  std::get<0>(m_position) -= std::get<0>(other);
  std::get<1>(m_position) -= std::get<1>(other);
  std::get<2>(m_position) -= std::get<2>(other);

}

void Point::set_pixel(Pixel & pixel){
  m_pixel = pixel;
}

Point Point::operator*(Point other){
  Point p(m_position);
  std::get<0>(p.position()) *= std::get<0>(other.position());
  std::get<1>(p.position()) *= std::get<1>(other.position());
  std::get<2>(p.position()) *= std::get<2>(other.position());
  return p;
}

Point Point::operator*(double num){
 std::tuple<float, float, float> t = std::make_tuple(std::get<0>(m_position)*num,
  std::get<1>(m_position)*num, 
  std::get<2>(m_position)*num);
 Point p(t);
 return p;
}

Point Point::operator-(){
  std::tuple<float, float, float> t(m_position);
  std::get<0>(t) = -std::get<0>(m_position);
  std::get<1>(t) = -std::get<1>(m_position);
  std::get<2>(t) = -std::get<2>(m_position);
  Point p(t);
  return p;

}

Vector Point::operator-(Point other){
  std::tuple<float, float, float> t(m_position);
  Vector p(t);
  p.subtract(other);
  return p;
  //p.subtract(other);
}

Point Point::operator+(Point other){
  std::tuple<float, float, float> t(m_position);
  Point p(t);
  p.add(other);
  return p;
  //return
}

bool Point::operator < ( const Point& str) const
{
  return (std::get<2>(m_position) < std::get<2>(str.position()));
}
void Point::subtract(Point & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());
}
void Point::subtract(Vector & other){
  std::get<0>(m_position) -= std::get<0>(other.position());
  std::get<1>(m_position) -= std::get<1>(other.position());
  std::get<2>(m_position) -= std::get<2>(other.position());

}


Point Point::sub(Point & other){
  Point p(m_position);
  p.subtract(other);
  return p;
}

void Point::add(Point & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}

void Point::add(Vector & other){
  std::get<0>(m_position) += std::get<0>(other.position());
  std::get<1>(m_position) += std::get<1>(other.position());
  std::get<2>(m_position) += std::get<2>(other.position());
}


std::ostream & operator<<(std::ostream & stream, Point & p){
  stream << "(" << std::get<0>(p.position()) << "," << std::get<1>(p.position()) << "," << std::get<2>(p.position()) << ")";
  return stream;
}