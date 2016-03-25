#include "rectangle.hpp"


Rectangle::Rectangle(){
	
}

Rectangle::Rectangle(Point & pos, int size){

}

Rectangle::Rectangle(Line & l1, Line & l2){
	m_l1 = l1;
	m_l2 = l2;
	set_middle();
}

void Rectangle::set_pixel(Pixel ref){
	m_pixel_ref = ref;
}

void Rectangle::set_middle(){
	//std::cout << "l1 " << m_l1 << std::endl;
	//std::cout << "l2 " << m_l2 << std::endl;
	Vector v1 = m_l1.get_vector()*0.5;
	Vector v2 = (m_l2.get_start_point() -m_l1.get_start_point())*0.5;
	Point p = m_l1.get_start_point();
	p.add(v1);
	p.add(v2);
	m_middle = p;
/*
	Vector v1 = m_l1.get_vector()*0.5;
	Vector v2 = m_l2.get_vector()*0.5;
	Point p1(m_l1.get_start_point());
	Point p2(m_l2.get_start_point());
	p1.add(v1);
	p2.add(v2);
	Vector mid = (p2-p1)*0.5;
	p1.add(mid);
	m_middle = p1;
	*/
	//std::cout << m_middle << std::endl;
}

Line & Rectangle::get_line(int nr){
	if(nr == 1 ) {
		return m_l1;
	}else{
		return m_l2;
	}
}

void Rectangle::rotate(float x, float y, float z, Point * origin){
	if(origin == nullptr){
		origin = &m_middle;
	}

	m_l1.rotate(x,y,z, origin);
	m_l2.rotate(x,y,z, origin);
}

void Rectangle::rotate(Point & rotation, Point * origin){
	rotate(std::get<0>(rotation.position()),
		std::get<1>(rotation.position()), 
		std::get<2>(rotation.position()), origin);
}

void Rectangle::get_rotated(std::vector<Point> & container,Point & rotation, Point & position){
	Rectangle * temp = new Rectangle(m_l1, m_l2);
	temp->rotate(rotation, &position);
	temp->get_points(container);
	delete temp;
}

void Rectangle::get_points(std::vector<Point> & container){	
	m_l1.set_pixel(m_pixel_ref);
	m_l1.get_points(container);
	m_l2.set_pixel(m_pixel_ref);
	m_l2.get_points(container);
	Line l3(m_l1.get_start_point(), m_l2.get_start_point());
	l3.set_pixel(m_pixel_ref);
	l3.get_points(container);
	Line l4(m_l1.get_end_point(), m_l2.get_end_point());
	l4.set_pixel(m_pixel_ref);
	l4.get_points(container);
	
	
}

Point & Rectangle::get_middle(){
	return m_middle;
}

std::ostream & operator<<(std::ostream & stream, Rectangle & p){
	stream << "Rectangle\n";
	stream << "Upper " << p.get_line(1) << "\n";
	stream << "Lower " << p.get_line(2) << "\n";
  //stream << "from (" << std::get<0>(p.get_start_point().position()) << "," << std::get<1>(p.get_start_point().position()) << "," << std::get<2>(p.get_start_point().position()) << ") ";
  //stream << " to (" << std::get<0>(p.get_end_point().position()) << "," << std::get<1>(p.get_end_point().position()) << "," << std::get<2>(p.get_end_point().position()) << ") ";

	return stream;
}