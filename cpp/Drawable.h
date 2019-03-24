/*
 * Drawable.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include "3d_model/BaseObjects.h"
#include "lcd_log.h"
#include "3d_model/Color.h"
#include "fonts.h"

#define BUFFER0_ADDR 0xD0000000
#define BUFFER1_ADDR 0xD0200000

class Drawable {
public:
	Drawable();
	virtual ~Drawable();

	void draw_line(Point2d p1, Point2d p2);
	void draw_point(Point2d p);
	void draw_rect(Point2d p1, x16 width, x16 height);
	void draw_rect(x16 x, x16 y, x16 width, x16 height);
	void draw_fill_rect(Point2d p1, x16 width, x16 height);
	void draw_fill_rect(x16 x, x16 y, x16 width, x16 height);
	void draw_polygon(Polygon *p);
	void draw_fill_polygon(Polygon *p);
	void draw_text(unsigned char *text, Point2d pos);

	void clear_display();

	void swap_buffers();
	void set_active_layer(x8 layer);
	x8 get_active_layer();

	void init_font();

	void set_draw_color(Color c);
	Color *get_draw_color();
	Color *get_text_back_color();
	void set_text_back_color(Color c);

protected:
	Point *convert_to_point(Polygon *p);

private:
	Color color;
	Color text_back_color;
	x8 active_layer = 0;
	sFONT font = Font16;
	Color background_color = 0x1FFFF;
};

#endif /* DRAWABLE_H_ */
