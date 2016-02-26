#include "rectangle.hpp"
/*
Rectangle::Rectangle(float sx, float sy, float sz, float ex, float ey, float ez){
	m_position_first = std::make_tuple(sx,sy,sz);
	m_position_second = std::make_tuple(ex,ey,ez);
}
Rectangle::Rectangle(std::vector<std::tuple<float, float, float>> & points){
	std::tuple<float, float, float> top_left = points[0];
	std::tuple<float, float, float> top_right = points[1];
	std::tuple<float, float, float> bot_left = points[2];
	std::tuple<float, float, float> bot_right = points[3];
}
*/
Rectangle::Rectangle(){
	
}

Rectangle::Rectangle(Point & pos, int size){

}

Rectangle::Rectangle(Line & l1, Line & l2, Line & l3, Line & l4){
	m_l1 = l1;
	m_l2 = l2;
	m_l3 = l3;
	m_l4 = l4;
}

void Rectangle::rotate(float x, float y, float z, Point * origin){
	m_l1.rotate(x,y,z, origin);
	m_l4.rotate(x,y,z, origin);
}

void Rectangle::get_points(std::vector<Point> & container){

	std::vector<Point> upper;
	std::vector<Point> lower;
	m_l1.get_points(upper);
	m_l4.get_points(lower);
	for(float i = 0; i < upper.size(); ++i){
		Line l(upper[i], lower[i]);
		l.get_points(container);
	}
	/*
	m_l1.get_points(container);
	m_l2.get_points(container);
	m_l3.get_points(container);
	m_l4.get_points(container);
	*/
}
