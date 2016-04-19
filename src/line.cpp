#include "line.hpp"

Line::Line(){
	m_start = new Vector(0,0,0);
	m_end = new Vector(1,0,0);
	m_pixel_ref = new Pixel(0);
}

Line::Line(const Vector & start, const Vector & end){
	m_start = new Vector(start);
	m_end = new Vector(end);
	m_pixel_ref = new Pixel(0);
}
Line::Line(const Vector & start, const Vector & end, const Pixel & pix){
	m_start = new Vector(start);
	m_end = new Vector(end);
	m_pixel_ref = new Pixel(pix);
}
Line::Line(const Line & other){
	m_start = new Vector(other.get_start_point());
	m_end = new Vector(other.get_end_point());
	m_pixel_ref = new Pixel(other.get_pixel());
}

Line & Line::operator= (const Line & other){
	m_start->set(other.get_start_point());
	m_end->set(other.get_end_point());
	m_pixel_ref->set(other.get_pixel());
	return *this;
} 
Line::~Line(){
	if(m_start != nullptr){
		delete m_start;
		m_start = nullptr;
	}

	if(m_end != nullptr){
		delete m_end;
		m_end = nullptr;
	}

	if(m_pixel_ref != nullptr){
		delete m_pixel_ref;
		m_pixel_ref = nullptr;
	}

}
	//void get_points_rel(std::vector<Vector> & container, const Vector &, const Vector &);
Vector Line::get_vector()const{
	Vector v(*m_end);
	v.subtract(*m_start);
	return v;
}
Vector & Line::get_start_point(){
	return *m_start;
}
Vector & Line::get_end_point(){
	return *m_end;
}
Vector & Line::get_start_point()const{
	return *m_start;
}
Vector & Line::get_end_point()const{
	return *m_end;
}
Vector Line::get_middle()const{
	Vector diff(*m_end);
	diff.subtract(*m_start);
	diff.mult(0.5f);
	Vector origin(*m_start);
	origin.add(diff);
	return origin;

}

void Line::move(const Vector & mov){
	m_start->add(mov);
	m_end->add(mov);
}
void Line::rotate_around(const Vector & rot, const Vector & origin){
	rotate_around(rot.x(), rot.y(), rot.z(), origin);
}
void Line::rotate_around(float yz, float xz, float xy, const Vector & origin){

	Vector tempVector(*m_start);
	tempVector.subtract(origin);
                //reset the point so that the scaled vector can be added
	m_start->set(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_start->add(tempVector);

	tempVector.set(*m_end);
	tempVector.subtract(origin);
                //reset the point so that the scaled vector can be added
	m_end->set(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_end->add(tempVector);
}
void Line::rotate(float yz, float xz, float xy){
	Vector origin = get_middle();

	Vector tempVector(*m_start);
	tempVector.subtract(origin);
                //reset the point so that the scaled vector can be added
	m_start->set(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_start->add(tempVector);

	tempVector.set(*m_end);
	tempVector.subtract(origin);
                //reset the point so that the scaled vector can be added
	m_end->set(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_end->add(tempVector);/*
	origin = (m_start);
	Vector origvec = (m_end-m_start)*0.5f;
	origin.subtract(origvec);
	*/

}
void Line::rotate(const Vector & rot){
	rotate(rot.x(), rot.y(), rot.z());
}
float Line::magnitude()const{
	return get_vector().magnitude();
}

void Line::scale(float x, float y, float z){

	Vector diff(*m_end);
	diff.subtract(*m_start);
	diff.mult(0.5f);
	Vector origin = *m_start;
	origin.add(diff);
	Vector mult(x, y, z);
	diff.mult(diff);
	m_start->subtract(diff);
	m_end->add(diff);
}
void Line::scale(const Vector & s){
	scale(s.x(), s.y(), s.z());
}
void Line::set_pixel(const Pixel & pix){
	m_pixel_ref->set(pix);
}
Pixel & Line::get_pixel()const{
	return *m_pixel_ref;
}

void Line::get_points(std::vector<Point> & container)const{

	float x1 = (m_start->x());
	float y1 = (m_start->y());
	float z1 = (m_start->z());
	float x2 = (m_end->x());
	float y2 = (m_end->y());
	float z2 = (m_end->z());
	float i, dx, dy, dz, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;
	int l, m, n;
	float point[3];

	point[0] = x1;
	point[1] = y1;
	point[2] = z1;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	x_inc = (dx < 0) ? -1 : 1;
	l = abs(dx);
	y_inc = (dy < 0) ? -1 : 1;
	m = abs(dy);
	z_inc = (dz < 0) ? -1 : 1;
	n = abs(dz);
	dx2 = l << 1;
	dy2 = m << 1;
	dz2 = n << 1;

	if ((l >= m) && (l >= n)) {
		err_1 = dy2 - l;
		err_2 = dz2 - l;
		for (i = 0; i < l; i++) {
			//std::cout << "this" << std::endl;
			Point p (point[0], point[1], point[2], *m_pixel_ref);
			//p.set_pixel(*m_pixel_ref);
			container.push_back(p);
			//output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
			if (err_1 > 0) {
				point[1] += y_inc;
				err_1 -= dx2;
			}
			if (err_2 > 0) {
				point[2] += z_inc;
				err_2 -= dx2;
			}
			err_1 += dy2;
			err_2 += dz2;
			point[0] += x_inc;
		}
	} else if ((m >= l) && (m >= n)) {
		err_1 = dx2 - m;
		err_2 = dz2 - m;
		for (i = 0; i < m; i++) {
			Point p (point[0], point[1], point[2], *m_pixel_ref);
			//p.set_pixel(*m_pixel_ref);
			container.push_back(p);
			//output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
			if (err_1 > 0) {
				point[0] += x_inc;
				err_1 -= dy2;
			}
			if (err_2 > 0) {
				point[2] += z_inc;
				err_2 -= dy2;
			}
			err_1 += dx2;
			err_2 += dz2;
			point[1] += y_inc;
		}
	} else {
		err_1 = dy2 - n;
		err_2 = dx2 - n;
		for (i = 0; i < n; i++) {
			Point p (point[0], point[1], point[2], *m_pixel_ref);
			//p.set_pixel(*m_pixel_ref);
			container.push_back(p);

			//output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
			if (err_1 > 0) {
				point[1] += y_inc;
				err_1 -= dz2;
			}
			if (err_2 > 0) {
				point[0] += x_inc;
				err_2 -= dz2;
			}
			err_1 += dy2;
			err_2 += dx2;
			point[2] += z_inc;
		}
	}
	Point p (point[0], point[1], point[2], *m_pixel_ref);
	//p.set_pixel(*m_pixel_ref);
	container.push_back(p);
}