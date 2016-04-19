#pragma once
#include <string>
#include <iostream>
class Pixel{
public:
	Pixel();
	Pixel(int c);
	Pixel(std::string s);
	Pixel & operator=(const Pixel &);
	void set(int);
	void set(const Pixel & pix);
	std::string get_str() const;
	int get_val() const;
private:
	int m_value;
	std::string m_string;
};

