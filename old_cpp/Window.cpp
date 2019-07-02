/*
 * Window.cpp
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/Window.h>

Window::Window() {
	this->__draw_field();
}

Window::Window(const char* title) {
	this->title = title;
	this->__draw_title();
}

Window::~Window() {
	// TODO Auto-generated destructor stub
}

void Window::__draw_field(){
	uint8_t color_inc = 0x1F / thickness;
	for (uint8_t i = 0; i < thickness; ++i) {
		uint8_t color = color_inc * i;
		BSP_LCD_SetTextColor((color << 11) | (color << 5) | (color));
		BSP_LCD_DrawRect(	this->posx - i - thickness,
							this->posy - i - thickness,
							this->width + (i<<1),
							this->height + (i<<1));
	}
}


std::string Window::get_title(){
	return title;
}

uint16_t Window::get_win_pos_x(){
	return posx;
}

uint16_t Window::get_win_pos_y(){
	return posy;
}

uint16_t Window::get_win_width(){
	return width;
}

uint16_t Window::get_win_height(){
	return height;
}

uint16_t Window::get_draw_pos_x(){
	return draw_posx;
}

uint16_t Window::get_draw_pos_y(){
	return draw_posy;
}
