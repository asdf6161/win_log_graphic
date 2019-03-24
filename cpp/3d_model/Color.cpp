/*
 * Color.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/Color.h>

Color::Color() {
	// TODO Auto-generated constructor stub
	this->r = COLOR_MAX_R;
	this->g = COLOR_MAX_G;
	this->b = COLOR_MAX_B;
}

Color::Color(x8 r, x8 g, x8 b){
	this->set_color(r, g, b);
}

Color::Color(x32 c){
	set_color(c);
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

x32 Color::get_color(){
	return (r << 11) | (g << 5) | b;
}

x32 Color::get_color(x8 r, x8 g, x8 b){
	return (r << 11) | (g << 5) | b;
}

void Color::set_color(x32 color){
	b = color & COLOR_MAX_B;
	g = (color >> 5) & COLOR_MAX_G;
	r = (color >> 11) & COLOR_MAX_R;
}

void Color::set_color(x8 r, x8 g, x8 b){
	this->r = r;
	this->g = g;
	this->b = b;
}
