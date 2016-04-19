#include "pixel.hpp"
#include <string>

Pixel::Pixel(){
	//m_string = "  \033[48m";
	m_value = 0;
}

Pixel::Pixel(int c){
	m_value = c;
} 

/*
Pixel::Pixel(std::string s){
	//m_string = s + "\033[0m";
}
*/

void Pixel::set(int val){
	m_value = val;
}
void Pixel::set(const Pixel & pix){
	m_value = pix.get_val();
}
Pixel & Pixel::operator=(const Pixel & pix){
	m_value = pix.get_val();
	return *this;
}

std::string Pixel::get_str()const{
	return "\033[48;5;" + std::to_string(m_value) + "m  " + "\033[0m";
}
int Pixel::get_val()const{
	return m_value;
}
