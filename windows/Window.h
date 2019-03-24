/*
 * Window.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Drawable.h"
#include "string"

class Header : private Drawable{
public:
	Header(x16 height);
	virtual ~Header();

	void draw(Point2d pos, x16 width);
	void draw_title(Point2d pos);

private:
	Color color;
	Color text_color;
	std::string title = "";
	x16 height;
};

class Window : protected Drawable{
public:
	Window();
	Window(Point2d pos);
	virtual ~Window();

	void draw();
	void draw_border();
	void draw_header();
	void fill_background(Color c);
	void fill_background();
	void set_thickness(x16 t);
	void set_pos(Point2d pos);
	void init();

private:
	Header head = Header(30);
	Point2d pos = Point2d(0,0);
	Color background_color = Color(29, 58, 29);

public:
	x16 width = 0;
	x16 height = 0;
	x16 thickness_border = 0;
};

#endif /* WINDOW_H_ */
