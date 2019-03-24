/*
 * Window.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

/*
 * How to use
 *
	Window *win = new Window(Point2d(100, 100));
	win->draw();
	after need use Drawvable object for swap buffer
 * */

#include <Window.h>


Header::Header(Point2d pos, x16 width, x16 height){
	this->height = height;
	this->width = width;
	this->pos = pos;
	title = "Window";
	color = Color(0x04DF);
	text_color = Color(0xFFFF);
}

Header::~Header(){

}

void Header::draw(){
	Color *b_color = Drawable::get_draw_color();
	Color *back_color = Drawable::get_text_back_color();

	// draw header rect
	Drawable::set_draw_color(color);
	Drawable::draw_fill_rect(this->pos, this->width, height);

	// draw title
	Drawable::set_text_back_color(color);
	Drawable::set_draw_color(text_color);
	draw_title(this->pos);

	// return colors
	Drawable::set_text_back_color(*back_color);
	Drawable::set_draw_color(*b_color);
}

void Header::draw_title(Point2d pos){
	pos.y += 10;
	pos.x += 6;
	Drawable::draw_text((unsigned char *)title.data(), pos);
}



Window::Window() {
	init();
}

Window::Window(Point2d pos){
	init();
	set_pos(pos);
}

Window::Window(Point2d pos, x16 width, x16 height){
	init();
	set_pos(pos);
	set_size(width, height);
}

Window::~Window() {

}

void Window::init(){
	pos.x = 0;
	pos.y = 0;
	width = 320;
	height = 240;
	thickness_border = 5;
	this->head = new Header(pos, width, 30);
}

void Window::draw(){
	fill_background();
	draw_border();
	draw_header();
}

void Window::draw_border(){
	float color_inc_RB = (float)(COLOR_MAX_R - 20) / thickness_border;
	float color_inc_G = (float)(COLOR_MAX_G - 40) / thickness_border;
	Color *b_color = Drawable::get_draw_color();
	for (uint8_t i = 0; i < thickness_border; ++i) {
		x8 color_RB = color_inc_RB * i + 20;
		x8 color_G = color_inc_G * i + 40;
		Drawable::set_draw_color(Color(Color::get_color(color_RB, color_G, color_RB)));
		Drawable::draw_rect(pos.x - i - 1,
							pos.y - i - 1,
							width + (i << 1),
							height + (i << 1));
	}
	Drawable::set_draw_color(*b_color);
}

void Window::draw_header(){
	head->pos = this->pos;
	head->width = this->width;
	head->draw();
}

void Window::set_thickness(x16 t){
	thickness_border = t;
}

void Window::set_pos(Point2d pos){
	this->pos = pos;
}

void Window::set_size(x16 width, x16 height){
	this->width = width;
	this->height = height;
}

void Window::fill_background(Color c){
	Color *b_color = Drawable::get_draw_color();
	Drawable::set_draw_color(c);
	Drawable::draw_fill_rect(pos, width, height);
	Drawable::set_draw_color(*b_color);
}

void Window::fill_background(){
	Color *b_color = Drawable::get_draw_color();
	Drawable::set_draw_color(background_color);
	Drawable::draw_fill_rect(pos, width, height);
	Drawable::set_draw_color(*b_color);
}
