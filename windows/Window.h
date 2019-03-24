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
	Header(Point2d pos, x16 width, x16 height);
	virtual ~Header();

	void draw();
	void draw_title(Point2d pos);

protected:
	Color color;
	Color text_color;
	std::string title = "";
public:
	x16 height;
	x16 width;
	Point2d pos;
};

class Window : protected Drawable{
public:
	Window();
	Window(Point2d pos);
	Window(Point2d pos, x16 width, x16 height);
	virtual ~Window();

	virtual void draw();
	void draw_border();
	void draw_header();
	virtual void fill_background(Color c);
	virtual void fill_background();
	void set_thickness(x16 t);
	void set_pos(Point2d pos);
	virtual void set_size(x16 width, x16 height);
	void init();

protected:
	Header *head = nullptr;
	Point2d pos = Point2d(0,0);
	Color background_color = Color(29, 58, 29);

public:
	x16 width = 0;
	x16 height = 0;
	x16 thickness_border = 0;
};

#endif /* WINDOW_H_ */
