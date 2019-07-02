/*
 * DrawableField.h
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: yura
 */

#ifndef DRAWABLEFIELD_H_
#define DRAWABLEFIELD_H_

#include <3d_model/BaseElem3D.h>
#include "Window.h"
#include <vector>

class DrawableField : Window {
public:
	DrawableField();
	virtual ~DrawableField();

	void init();

	void draw_line(Point3D *p1, Point3D *p2);
	void draw_polygon(Polygon *p_vec);
	void draw_line_fill();
	void draw_ret_fill();
	void draw_point(Point3D *p);

	void set_color(uint8_t r, uint8_t g, uint8_t b);
	void set_back_color(uint8_t r, uint8_t g, uint8_t b);
	void clear_background();
	uint32_t get_color();
	uint32_t get_back_color();


private:
	uint8_t r = 0x1F;
	uint8_t g = 0x1F;
	uint8_t b = 0x1F;

	uint8_t r_b = 0x1F;
	uint8_t g_b = 0x1F;
	uint8_t b_b = 0x1F;

private:
	Window *win = nullptr;
	void __draw_background();
	void __draw_title();
};

#endif /* DRAWABLEFIELD_H_ */
