#include "camera.hpp"

Camera::Camera(){
	m_position = new Vector(0,0,0);
	m_rotation = new Vector(0,0,0);
	m_canvas = new Canvas();
}
Camera::Camera(const Vector & pos, const Vector & rot){
	m_position = new Vector(pos);
	m_rotation = new Vector(rot);
	m_canvas = new Canvas();

}
Camera::~Camera(){
	if(m_position != nullptr){
		delete m_position;
		m_position = nullptr;
	}
	if(m_rotation != nullptr){
		delete m_rotation;
		m_rotation = nullptr;
	}
	if(m_canvas != nullptr){
		delete m_canvas;
		m_canvas = nullptr;
	}
}

void Camera::move(const Vector & m){
	m_position->add(m);
}
void Camera::rotate(const Vector & rot){
	m_rotation->add(rot);
}

Vector Camera::get_rel(){
	return Vector(m_canvas->get_screen_width(), m_canvas->get_screen_height(), 0);
}
Vector & Camera::get_position(){
	return *m_position;
}
Vector & Camera::get_rotation(){
	return *m_rotation;
}

void Camera::add_lines(std::vector<Line> & container){
	std::vector<Point> points;
	Vector rotation(*m_rotation);
	Vector movement(*m_position);
	movement.mult(-1);
	for(auto line : container){
		
		line.move(movement);
		line.rotate_around(rotation, *m_position);
		Vector start = line.get_start_point();
		Vector end = line.get_end_point();

		if(start.z()-m_position->z() != 0){
			line.get_start_point().x() = start.x()*m_fx/(start.z()-m_position->z());
			line.get_start_point().y() = start.y()*m_fy/(start.z()-m_position->z());
		}
		if(end.z()-m_position->z() != 0){
			line.get_end_point().x() = end.x()*m_fx/(end.z()-m_position->z());
			line.get_end_point().y() = end.y()*m_fy/(end.z()-m_position->z());
		}
		
		/*
		Vector temp = line.get_start_point();
		temp.subtract(*m_position);
		Vector rot = *m_position;
		rot.mult(M_PI/180);
		rot.mult(-1);
		rot.z() = -temp.z();
		std::cout << "Before: " << line.get_start_point() << std::endl;
		line.get_start_point().x() = cos(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x()) - sin(rot.y())*temp.z();
		line.get_start_point().y() = sin(rot.x())*(cos(rot.y())*temp.z() + sin(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x())) + cos(rot.x())*(cos(rot.z())*temp.y() - sin(rot.z())*temp.x());
		line.get_start_point().y() = cos(rot.x())*(cos(rot.y())*temp.z() + sin(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x())) - sin(rot.x())*(cos(rot.z())*temp.y() - sin(rot.z())*temp.x());
		temp.set(line.get_end_point());
		std::cout << "After: " << line.get_start_point() << std::endl;
		break;
		temp.subtract(*m_position);
		line.get_end_point().x() = cos(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x()) - sin(rot.y())*temp.z();
		line.get_end_point().y() = sin(rot.x())*(cos(rot.y())*temp.z() + sin(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x())) + cos(rot.x())*(cos(rot.z())*temp.y() - sin(rot.x())*temp.x());
		line.get_end_point().y() = cos(rot.x())*(cos(rot.y())*temp.z() + sin(rot.y())*(sin(rot.z())*temp.y() + cos(rot.z())*temp.x())) - sin(rot.x())*(cos(rot.z())*temp.y() - sin(rot.x())*temp.x());
  */

		Vector diff = line.get_end_point();
		diff.subtract(line.get_start_point());

		if(diff.magnitude() < 100){
			if(is_in_front(line.get_end_point()) &&  is_in_front(line.get_start_point())){
				line.get_points(points);
			}
		}

	}
	add_points(points);
}



void Camera::add_points(std::vector<Point> & container){
	Vector rel = get_rel();
	Vector move = *m_position;
	rel.mult(0.5f);
	std::sort(container.begin(), container.end(),[](const Point& a, const Point& b)
	{
		return a.z() > b.z();
	} );
	for(auto point : container){
		//point.move(move);
		point.move(rel);
		point.paint(*m_canvas);
	}
}
void Camera::paint(){
	m_canvas->paint();
	m_canvas->clear_grid();
}

Vector Camera::forward(){
	Vector v(0, 0, 1);
	v.rotateYZ(m_rotation->x());
	v.rotateXZ(m_rotation->y());
	v.rotateXY(m_rotation->z());
	v.y() = -v.y();
	v.x() = -v.x();
	return v;	
}

Vector Camera::right(){
	Vector v(1, 0, 0);
	v.rotateYZ(m_rotation->x());
	v.rotateXZ(m_rotation->y());
	v.rotateXY(m_rotation->z());
	return v;	
}
bool Camera::is_in_front(const Vector & k){
	
	Vector p = k;
	Vector v = forward();
	Vector rel = Vector(0,0,2*m_fx);
	rel.mult(forward());
	p.subtract(*m_position);
	p.add(rel);
	std::cout << "forward " << v << "\n";
	std::cout << "point " << p << "\n";
	float val = p.x()*v.x() + p.y()*v.y() + p.z()*v.z();
	std::cout << "Result " << val << std::endl;
	return val > 0;
	//return p.z() > m_position->z();
	
}