/*
 * Window.h
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: yura
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "lcd_log.h"
#include <string>

class Window {
public:
	Window();
	Window(const char* title);
	virtual ~Window();

	std::string get_title();
	uint16_t get_win_pos_x();
	uint16_t get_win_pos_y();
	uint16_t get_win_width();
	uint16_t get_win_height();
	uint16_t get_draw_pos_x();
	uint16_t get_draw_pos_y();

private:
	void __draw_field();
	void __draw_title();

 	uint8_t	thickness = 5;

private:
	std::string title = "window";
	uint16_t posx = 480;
	uint16_t posy = 80;
	uint16_t draw_posx = 700;  // Нулевая точка для рисоания х
	uint16_t draw_posy = 320;  // Нулевая точка для рисоания у
	uint16_t width = 1024 - 480;
	uint16_t height = 600 - 80;
};

#endif /* WINDOW_H_ */
