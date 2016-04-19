#include "block.hpp"


Block::Block(const Vector & pos){
	m_position = new Vector(pos);
	m_lines = new std::vector<Line>();

	m_middle = new Vector();
	m_middle->set(Vector(-m_size.x()/4, -m_size.y()/4, -m_size.z()/4));
	m_middle->add(pos);
	
	redraw_lines();
	

}
Block::Block(const Block & other){
	m_position = new Vector(0,0,0);
	m_lines = new std::vector<Line>();
	m_middle = new Vector(other.get_middle());
	redraw_lines();
}


Block::~Block(){
	if(m_lines != nullptr){
		delete m_lines;
		m_lines = nullptr;
	}
	if(m_position != nullptr){
		delete m_position;
		m_position = nullptr;
	}

}
Vector Block::get_middle()const{
	return *m_middle;
}
const Vector & Block::get_size()const{
	return m_size;
}

void Block::rotate(const Vector & rot){
	rotate(rot.x(), rot.y(), rot.z());
} 
void Block::rotate(float x, float y, float z){
	for(auto i = m_lines->begin(); i != m_lines->end(); ++i){
		(*i).rotate_around(x,y,z, *m_middle);
	}
} 
void Block::rotate_around(const Vector & rot, const Vector & origin){
	rotate_around(rot.x(), rot.y(), rot.z(), origin);
}
void Block::rotate_around(float x, float y, float z, const Vector & origin){
	m_middle->rotate_around(x,y,z,origin);
	for(auto i = m_lines->begin(); i != m_lines->end(); ++i){
		(*i).rotate_around(x,y,z, origin);
	}
} 
void Block::redraw_lines(){
	m_lines->clear();
	float x = m_middle->x();
	float y = m_middle->y();
	float z = m_middle->z();
	float sx = m_size.x()*m_scale.x();
	float sz = m_size.y()*m_scale.y();
	float h = m_size.z()* m_scale.z();
		//North
	Vector start (x-sx, y+h, z-sz);
	Vector end (x+sx, y+h, z-sz);

	Line upper(start, end);
	Pixel pix(21);
	upper.set_pixel(pix);
	m_lines->push_back(upper);
	
	start.set(x-sx, y-h, z-sz);
	end.set(x+sx, y-h, z-sz);
	Line lower(start, end);
	lower.set_pixel(pix);
	m_lines->push_back(lower);
	//East
	start.set (x+sx, y+h, z-sz);
	end.set (x+sx, y+h, z+sz);

	upper = Line(start, end);
	upper.set_pixel(40);
	m_lines->push_back(upper);
	start.set(x+sx, y-h, z-sz);
	end.set(x+sx, y-h, z+sz);
	lower = Line(start, end);
	lower.set_pixel(40);
	m_lines->push_back(lower);

	//South
	start.set (x-sx, y+h, z+sz);
	end.set (x+sx, y+h, z+sz);

	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines->push_back(upper);

	start.set(x-sx, y-h, z+sz);
	end.set(x+sx, y-h, z+sz);
	lower = Line(start, end);
	lower.set_pixel(pix);

	m_lines->push_back(lower);
	//West
	start.set (x-sx, y+h, z+sz);
	end.set (x-sx, y+h, z-sz);

	upper = Line(start, end);
	upper.set_pixel(40);
	m_lines->push_back(upper);

	start.set(x-sx, y-h, z+sz);
	end.set(x-sx, y-h, z-sz);
	lower = Line(start, end);
	lower.set_pixel(40);
	m_lines->push_back(lower);

	start.set(x-sx,y-h,z-sz);
	end.set(x-sx,y+h,z-sz);
	upper = Line(start, end);
	pix = Pixel(21);
	upper.set_pixel(pix);
	m_lines->push_back(upper);


	start.set(x+sx,y-h,z-sz);
	end.set(x+sx,y+h,z-sz);
	upper = Line(start, end);
	upper.set_pixel(pix);

	m_lines->push_back(upper);

	start.set(x+sx,y-h,z+sz);
	end.set(x+sx,y+h,z+sz);
	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines->push_back(upper);

	start.set(x-sx,y-h,z+sz);
	end.set(x-sx,y+h,z+sz);
	upper = Line(start, end);
	upper.set_pixel(pix);
	m_lines->push_back(upper);
	/*
	//North
	Vector start (x, y+h, z);
	Vector end (x+sx, y+h, z);

	Line upper(start, end);
	Pixel pix(21);
	upper.set_pixel(pix);
	m_lines->push_back(upper);

	start.set(x, y, z);
	end.set(x+sx, y, z);
	Line lower(start, end);
	lower.set_pixel(pix);
	m_lines->push_back(lower);
	//East
	start.set (x+sx, y+h, z);
	end.set (x+sx, y+h, z+sz);

	upper = Line(start, end);
	upper.set_pixel(40);
	m_lines->push_back(upper);
	start.set(x+sx, y, z);
	end.set(x+sx, y, z+sz);
	lower = Line(start, end);
	lower.set_pixel(40);
	m_lines->push_back(lower);

	//South
	start.set (x, y+h, z+sz);
	end.set (x+sx, y+h, z+sz);

	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines->push_back(upper);

	start.set(x, y, z+sz);
	end.set(x+sx, y, z+sz);
	lower = Line(start, end);
	lower.set_pixel(pix);

	m_lines->push_back(lower);
	//West
	start.set (x, y+h, z+sz);
	end.set (x, y+h, z);

	upper = Line(start, end);
	upper.set_pixel(40);
	m_lines->push_back(upper);

	start.set(x, y, z+sz);
	end.set(x, y, z);
	lower = Line(start, end);
	lower.set_pixel(40);
	m_lines->push_back(lower);

	start.set(x,y,z);
	end.set(x,y+h,z);
	upper = Line(start, end);
	pix = Pixel(21);
	upper.set_pixel(pix);
	m_lines->push_back(upper);


	start.set(x+sx,y,z);
	end.set(x+sx,y+h,z);
	upper = Line(start, end);
	upper.set_pixel(pix);

	m_lines->push_back(upper);

	start.set(x+sx,y,z+sz);
	end.set(x+sx,y+h,z+sz);
	upper = Line(start, end);
	pix = Pixel(196);
	upper.set_pixel(pix);
	m_lines->push_back(upper);

	start.set(x,y,z+sz);
	end.set(x,y+h,z+sz);
	upper = Line(start, end);
	upper.set_pixel(pix);
	m_lines->push_back(upper);
	*/
	//std::cout << m_rotation << std::endl;
	for(auto i = m_lines->begin(); i != m_lines->end(); ++i){
		(*i).rotate_around(m_rotation,*m_middle);
		//std::cout << *i << std::endl;

	}	
	//rotate(m_rotation);
	/*
	*/
}
void Block::get_lines(std::vector<Line> & container){
	for(auto i = m_lines->begin(); i != m_lines->end(); ++i){
		container.push_back(*i);
	}
}
