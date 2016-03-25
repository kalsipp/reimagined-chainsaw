#include "camera.hpp"

Camera::Camera(){
	m_position = Point(0,0,0);
	m_rotation = Point(0,0,0);
}

Camera::Camera(Point & pos, Point & rot){
	m_position = pos;
	m_rotation = rot;
}

Vector Camera::forward(){
	Vector v(0, 0, -1);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());
	return v;
}
Vector Camera::backwards(){
	Vector v(0,0,1);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());

	return v;
}
Vector Camera::right(){
	Vector v(1,0,0);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());

	return v;
}
Vector Camera::left(){
	Vector v(-1,0,0);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());

	return v;
}
Vector Camera::up(){
	Vector v(0,1,0);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());

	return v;

}
Vector Camera::down(){
	Vector v(0,-1,0);
	v.rotateXY(m_rotation.x());
	v.rotateXZ(m_rotation.y());
	v.rotateYZ(m_rotation.z());

	return v;

}


Point Camera::get_ref(){
	return Point(static_cast<float>(m_canvas.get_screen_width()/2), static_cast<float>(m_canvas.get_screen_height()/2), 0.0f);
}
void Camera::add_points(std::vector<Point> container){
	std::sort(container.begin(), container.end());
	float meanz = 0;
	for(auto i = container.begin(); i != container.end(); ++i){
		//meanz += i->z();
		if(i->z() +30 < m_position.z()){
			add_pixel(*i);
		}
	}
	//meanz = meanz/container.size();
}

void Camera::add_lines(std::vector<Line> container){
	std::vector<Point> points;
	float fx = 70;
	float fy = fx;
	float s = 0;
	for(auto i = container.begin(); i != container.end(); ++i){

		Point rot = m_rotation*(-1);
		i->rotate(rot, &m_position);
		Point p = i->get_start_point();
		Point a = i->get_start_point();

		p = i->get_start_point();
		if(p.z()-m_position.z() != 0){
			i->get_start_point().x() = p.x()*fx/(p.z()-m_position.z());
			i->get_start_point().y() = p.y()*fy/(p.z()-m_position.z());
		}
		
		p = i->get_end_point();

		if(p.z()-m_position.z() != 0){

			i->get_end_point().x() = p.x()*fx/(p.z()-m_position.z());
			i->get_end_point().y() = p.y()*fy/(p.z()-m_position.z());
		}
		if(!is_behind(i->get_end_point()) && !is_behind(i->get_start_point())){
			i->get_points(points);
		}
	}
	add_points(points);

}
void Camera::add_pixel(Point p){


	p.paint(m_canvas);
	

}

bool Camera::is_behind(Point p) { 
	Vector v = forward();
	float val = p.x()*v.x() + p.y()*v.y() + p.z()*v.z();
	return val < 0;

}

void Camera::paint(){
	m_canvas.paint();
	m_canvas.clear_grid();
}
Point & Camera::get_rotation(){
	return m_rotation;
}
Point & Camera::get_position(){
	return m_position;
}
Point & Camera::get_max_view(){
	return m_max_view;
}
Point & Camera::get_min_view(){
	return m_min_view;
}
void Camera::set_rotation(Point & rot){
	m_rotation = rot;
}

void Camera::set_position(Point & pos){
	m_position = pos;
}