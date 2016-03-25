

#include "line.hpp"


Line::Line() {

}
Line::Line(int startx, int endx, int starty, int endy, int startz, int endz){
	m_start_x = startx;
	m_start_y = starty;
	m_end_x = endx;
	m_end_y = endy;
	m_start_z = startz;
	m_end_z = endz;

}

Line::Line(Point & start, Point & end){
	m_start = start;
	m_end = end;
}

void Line::set_pixel(Pixel & ref){
	m_pixel_ref = ref;
}

Vector Line::get_vector(){
	Vector v = m_end-m_start;
	return v;
}

Point & Line::get_start_point(){
	return m_start;
}
Point Line::get_middle(){
	Vector diff = (m_end-m_start)*0.5f;
	Point origin = m_start;
	origin.add(diff);
	return origin;

}
Point & Line::get_end_point(){
	return m_end;
}

void Line::get_points_rel(std::vector<Point> & container,Point & rotation, Point & position){
	Line temp(m_start, m_end);
	temp.rotate(rotation, &position);
	temp.get_points(container);
}

void Line::scale(Point p){
	scale(std::get<0>(p.position()), std::get<1>(p.position()), std::get<2>(p.position()));
}
void Line::scale(float a, float b, float c){
	std::cout << "start " << m_start << std::endl;
	std::cout << "end " << m_end << std::endl;

	Vector diff = (m_end-m_start)*0.5f;
	Point origin = m_start;
	origin.add(diff);
	std::cout << "origin " << origin << std::endl;
	std::cout << "diff " << diff << std::endl;

	Vector mult(a, b, c);
	std::cout << "mult " << mult << std::endl;

	diff = diff*mult;
	std::cout << "diff " << diff << std::endl;

	m_start.subtract(diff);
	m_end.add(diff);
	std::cout << "start after " << m_start << std::endl;
	std::cout << "end after " << m_end << "\n"<< std::endl;


}
void Line::rotate(Point & rotation, Point * origin){
	rotate(std::get<0>(rotation.position()),
		std::get<1>(rotation.position()), 
		std::get<2>(rotation.position()), origin);
}

void Line::rotate(float xy, float xz, float yz, Point * origp){
	Point origin;
	if(origp == nullptr){
		origin = (m_start);
		Vector origvec = (m_end-m_start)*0.5f;
		origin.subtract(origvec);
	}else{
		origin = *origp;
	}

	
	Vector tempVector = m_start-(origin);
                //reset the point so that the scaled vector can be added
	m_start.set_position(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_start.add(tempVector);
	
	tempVector = m_end-(origin);
                //reset the point so that the scaled vector can be added
	m_end.set_position(origin);
                //scale the vector and set the point to its new, scaled location
	tempVector.rotateXY(xy);
	tempVector.rotateXZ(xz);
	tempVector.rotateYZ(yz);
	m_end.add(tempVector);
}

void Line::get_points(std::vector<Point> & container){

	float x1 = (std::get<0>(m_start.position()));
	float y1 = (std::get<1>(m_start.position()));
	float z1 = (std::get<2>(m_start.position()));
	float x2 = (std::get<0>(m_end.position()));
	float y2 = (std::get<1>(m_end.position()));
	float z2 = (std::get<2>(m_end.position()));
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
			Point p (point[0], point[1], point[2]);
			p.set_pixel(m_pixel_ref);
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
			Point p (point[0], point[1], point[2]);
			p.set_pixel(m_pixel_ref);
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
			Point p (point[0], point[1], point[2]);
			p.set_pixel(m_pixel_ref);
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
	Point p (point[0], point[1], point[2]);
	p.set_pixel(m_pixel_ref);
	container.push_back(p);
	//output->getTileAt(point[0], point[1], point[2])->setSymbol(symbol);
}




std::ostream & operator<<(std::ostream & stream, Line & p){
	stream << "from (" << std::get<0>(p.get_start_point().position()) << "," << std::get<1>(p.get_start_point().position()) << "," << std::get<2>(p.get_start_point().position()) << ") ";
	stream << " to (" << std::get<0>(p.get_end_point().position()) << "," << std::get<1>(p.get_end_point().position()) << "," << std::get<2>(p.get_end_point().position()) << ") ";

	return stream;
}