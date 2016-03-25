#include "block.hpp"

/*
Block::Block(Point & pos){
	//std::cout << "Pos ("<<std::get<0>(pos.position()) << "," << std::get<1>(pos.position()) << "," << std::get<2>(pos.position()) << ")" << std::endl;

	//North
	float x = std::get<0> (pos.position());
	float y = std::get<1> (pos.position());
	float z = std::get<2> (pos.position());
	float s = m_size;
	float h = m_height;

	//North
	Point start (x, y+h, z);
	Point end (x+s, y+h, z);

	Line upper(start, end);
	m_lines.push_back(upper);
	start.set_position(x, y, z);
	end.set_position(x+s, y, z);
	Line lower(start, end);
	m_lines.push_back(lower);

	m_north = Rectangle(upper, lower);
	m_north.set_pixel(Pixel(17));
	std::cout << "North " << std::endl;
	std::cout << m_north << std::endl;
	//East
	start.set_position (x+s, y+h, z);
	end.set_position (x+s, y+h, z+s);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x+s, y, z);
	end.set_position(x+s, y, z+s);
	lower = Line(start, end);
	m_lines.push_back(lower);

	m_east = Rectangle(upper, lower);
	m_east.set_pixel(Pixel(160));
	std::cout << "East " << std::endl;
	std::cout << m_east << std::endl;

	//South
	start.set_position (x, y+h, z+s);
	end.set_position (x+s, y+h, z+s);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x, y, z+s);
	end.set_position(x+s, y, z+s);
	lower = Line(start, end);
	m_lines.push_back(lower);

	m_south = Rectangle(upper, lower);
	m_south.set_pixel(Pixel(46));

	std::cout << "South " << std::endl;
	std::cout << m_south << std::endl;

	//West
	start.set_position (x, y+h, z+s);
	end.set_position (x, y+h, z);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x, y, z+s);
	end.set_position(x, y, z);
	lower = Line(start, end);
	m_lines.push_back(lower);

	m_west = Rectangle(upper, lower);

	std::cout << "West " << std::endl;
	std::cout << m_west << std::endl;


	m_middle = Point(m_size/2, m_height/2, m_size/2);
	m_middle.add(pos);

	//set_middle();
 
	std::cout << m_middle << std::endl;
	
}
*/

Block::Block(Point pos){
	//std::cout << "Pos ("<<std::get<0>(pos.position()) << "," << std::get<1>(pos.position()) << "," << std::get<2>(pos.position()) << ")" << std::endl;

	//North
	m_position = pos;
	redraw_lines();
	/*
	float x = std::get<0> (pos.position());
	float y = std::get<1> (pos.position());
	float z = std::get<2> (pos.position());
	float s = m_size;
	float h = m_height;

	//North
	Point start (x, y+h, z);
	Point end (x+s, y+h, z);

	Line upper(start, end);
	Pixel pix(21);
	upper.set_pixel(pix);
	m_lines.push_back(upper);
	start.set_position(x, y, z);
	end.set_position(x+s, y, z);
	Line lower(start, end);
	lower.set_pixel(pix);
	m_lines.push_back(lower);
	//East
	start.set_position (x+s, y+h, z);
	end.set_position (x+s, y+h, z+s);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x+s, y, z);
	end.set_position(x+s, y, z+s);
	lower = Line(start, end);

	m_lines.push_back(lower);

	//South
	start.set_position (x, y+h, z+s);
	end.set_position (x+s, y+h, z+s);

	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines.push_back(upper);

	start.set_position(x, y, z+s);
	end.set_position(x+s, y, z+s);
	lower = Line(start, end);
	lower.set_pixel(pix);

	m_lines.push_back(lower);
	//West
	start.set_position (x, y+h, z+s);
	end.set_position (x, y+h, z);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x, y, z+s);
	end.set_position(x, y, z);
	lower = Line(start, end);
	m_lines.push_back(lower);

	start.set_position(x,y,z);
	end.set_position(x,y+h,z);
	upper = Line(start, end);
	pix = Pixel(21);
	upper.set_pixel(pix);
	m_lines.push_back(upper);


	start.set_position(x+s,y,z);
	end.set_position(x+s,y+h,z);
	upper = Line(start, end);
	upper.set_pixel(pix);

	m_lines.push_back(upper);

	start.set_position(x+s,y,z+s);
	end.set_position(x+s,y+h,z+s);
	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines.push_back(upper);

	start.set_position(x,y,z+s);
	end.set_position(x,y+h,z+s);
	upper = Line(start, end);
	upper.set_pixel(pix);
	m_lines.push_back(upper);
*/
	m_middle = Point(std::get<0>(m_size.position())/2, std::get<1>(m_size.position())/2, std::get<2>(m_size.position())/2);
	m_middle.add(pos);

	//set_middle();

	//std::cout << m_middle << std::endl;
}

void Block::redraw_lines(){
	m_lines.clear();
	float x = std::get<0> (m_position.position());
	float y = std::get<1> (m_position.position());
	float z = std::get<2> (m_position.position());
	float sx = std::get<0>(m_size.position())*std::get<0>(m_scale.position());
	float sz = std::get<2>(m_size.position())*std::get<2>(m_scale.position());
	float h = std::get<1>(m_size.position())*std::get<1>(m_scale.position());

	//North
	Point start (x, y+h, z);
	Point end (x+sx, y+h, z);

	Line upper(start, end);
	Pixel pix(21);
	upper.set_pixel(pix);
	m_lines.push_back(upper);
	start.set_position(x, y, z);
	end.set_position(x+sx, y, z);
	Line lower(start, end);
	lower.set_pixel(pix);
	m_lines.push_back(lower);
	//East
	start.set_position (x+sx, y+h, z);
	end.set_position (x+sx, y+h, z+sz);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x+sx, y, z);
	end.set_position(x+sx, y, z+sz);
	lower = Line(start, end);

	m_lines.push_back(lower);

	//South
	start.set_position (x, y+h, z+sz);
	end.set_position (x+sx, y+h, z+sz);

	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines.push_back(upper);

	start.set_position(x, y, z+sz);
	end.set_position(x+sx, y, z+sz);
	lower = Line(start, end);
	lower.set_pixel(pix);

	m_lines.push_back(lower);
	//West
	start.set_position (x, y+h, z+sz);
	end.set_position (x, y+h, z);

	upper = Line(start, end);
	m_lines.push_back(upper);

	start.set_position(x, y, z+sz);
	end.set_position(x, y, z);
	lower = Line(start, end);
	m_lines.push_back(lower);

	start.set_position(x,y,z);
	end.set_position(x,y+h,z);
	upper = Line(start, end);
	pix = Pixel(21);
	upper.set_pixel(pix);
	m_lines.push_back(upper);


	start.set_position(x+sx,y,z);
	end.set_position(x+sx,y+h,z);
	upper = Line(start, end);
	upper.set_pixel(pix);

	m_lines.push_back(upper);

	start.set_position(x+sx,y,z+sz);
	end.set_position(x+sx,y+h,z+sz);
	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines.push_back(upper);

	start.set_position(x,y,z+sz);
	end.set_position(x,y+h,z+sz);
	upper = Line(start, end);
	upper.set_pixel(pix);
	m_lines.push_back(upper);
	//std::cout << m_rotation << std::endl;
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).rotate(m_rotation,&m_middle);
		std::cout << *i << std::endl;

	}	
	//rotate(m_rotation);
}
void Block::rotate(Point pos, Point * origin){
	//m_rotation.add(pos);
	rotate(std::get<0>(pos.position()), std::get<1>(pos.position()), std::get<2>(pos.position()), origin);
}
Point Block::get_size(){
	return m_size;
}
void Block::rotate(float x, float y, float z, Point * origin){
	if(origin == nullptr){
		origin = &m_middle;
	}
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).rotate(x,y,z,origin);
	}/*
	m_north.rotate(x,y,z, origin);
	m_south.rotate(x,y,z, origin);
	m_east.rotate(x,y,z, origin);
	m_west.rotate(x,y,z, origin);
*/
} 


void Block::get_points(std::vector<Point> & container){
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).get_points(container);
	}
	/*
	m_north.get_points(container);
	m_south.get_points(container);
	m_east.get_points(container);
	m_west.get_points(container);
	*/

}

Point Block::get_middle(){
	return m_middle;
}

void Block::move(Point & diff){
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).get_start_point().add(diff);
		(*i).get_end_point().add(diff);

	}
	m_position.add(diff);
	m_middle = Point(std::get<0>(m_size.position())/2, std::get<1>(m_size.position())/2, std::get<2>(m_size.position())/2);
	m_middle.add(m_position);

	//redraw_lines();
}

std::tuple<float, float, float> & Block::position(){
	return m_position.position();
}

void Block::scale(Point p){
	m_scale = p;
	redraw_lines();
	/*
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).scale(p);
	}
	*/
}
void Block::scale(float a, float b, float c){
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		(*i).scale(a,b,c);
	}
}

void Block::get_lines(std::vector<Line> & container){
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		container.push_back(*i);
	}
}
void Block::get_points_rel(std::vector<Point> & container,Point & rotation, Point & position){
	
	for(auto i = m_lines.begin(); i != m_lines.end(); ++i){
		Line tmp = *i;
		tmp.rotate(rotation, &position);
		tmp.get_points(container);
	}
/*
	Rectangle temp = m_north;
	temp.rotate(rotation, &position);
	temp.get_points(container);

	temp = Rectangle(m_south);
	temp.rotate(rotation, &position);
	temp.get_points(container);

	temp = Rectangle(m_west);
	temp.rotate(rotation, &position);
	temp.get_points(container);

	temp = Rectangle(m_east);
	temp.rotate(rotation, &position);
	temp.get_points(container);
	*/
}
