/*
 * plot.cpp
 *
 *  Created on: 25 мар. 2019 г.
 *      Author: yura
 */

#include <plot.h>

Axes::Axes(Point2d start_pos, x16 horizontal_len, x16 vertical_len){
	this->start_pos = start_pos;
	this->vertical_len = vertical_len;
	this->horizontal_len = horizontal_len;
}

Axes::~Axes(){

}

void Axes::draw(){
	Color *b_color = Drawable::get_draw_color();
	Drawable::set_draw_color(this->color);

	// draw first line
	Drawable::draw_line(this->start_pos,
			Point2d(this->start_pos.x + this->horizontal_len, this->start_pos.y));

	// draw second line
	Drawable::draw_line(this->start_pos,
			Point2d(this->start_pos.x, this->start_pos.y - this->vertical_len));

	// restore draw color
	Drawable::set_draw_color(*b_color);
}


void Axes::set_pos(Point2d start_pos){
	this->start_pos = start_pos;
}

void Axes::set_ver_horiz_len(x16 horizontal_len, x16 vertical_len){
	this->vertical_len = vertical_len;
	this->horizontal_len = horizontal_len;
}

plot::plot(x16 *arr, x32 *arr_size) {
	this->init();
}

plot::plot() {
	this->init();
}

void plot::init(){
	this->fill_background();
	init_axes();
}

void plot::init_axes(){
	Point2d p;
	p.x = this->get_plot_x() + indent_axes;
	p.y = this->get_plot_y() - indent_axes + this->get_plot_height();
	this->axes = new Axes(	p,
							this->get_plot_width() - 2 * indent_axes,
							this->get_plot_height() - 2 * indent_axes);
}

void plot::update_axes(){
	Point2d p;
	p.x = this->get_plot_x() + indent_axes;
	p.y = this->get_plot_y() - indent_axes + this->get_plot_height();
	this->axes->set_pos(p);
	this->axes->set_ver_horiz_len(	this->get_plot_width() - 2 * indent_axes,
									this->get_plot_height() - 2 * indent_axes);
}

plot::~plot() {
	delete this->back_color;
	delete this->axes;
}

void plot::fill_background(Color c){
	Color *b_color = Drawable::get_draw_color();
	Drawable::set_draw_color(c);


	Drawable::draw_fill_rect(	this->get_plot_x(),
								this->get_plot_y(),
								this->get_plot_width(),
								this->get_plot_height());
	// restore draw color
	Drawable::set_draw_color(*b_color);
}

void plot::fill_background(){
	Color *b_color = Drawable::get_draw_color();
	Drawable::set_draw_color(*this->back_color);

	Drawable::draw_fill_rect(	this->get_plot_x(),
								this->get_plot_y(),
								this->get_plot_width(),
								this->get_plot_height());

	// restore draw color
	Drawable::set_draw_color(*b_color);
}

x16 plot::get_plot_width(){
	return Window::width - indent_right - indent_left;
}

x16 plot::get_plot_height(){
	return Window::height - indent_down - + Window::head->height - indent_up;
}

x16 plot::get_plot_x(){
	return Window::pos.x + indent_left;
}

x16 plot::get_plot_y(){
	return Window::pos.y + Window::head->height + indent_up;
}

void plot::draw(){
	Window::draw();
	this->fill_background();
	this->update_axes();
	this->axes->draw();
}

void plot::set_size(x16 width, x16 height){
	Window::set_size(width, height);
}
