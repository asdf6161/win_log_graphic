/*
 * plot.h
 *
 *  Created on: 25 мар. 2019 г.
 *      Author: yura
 */

#ifndef PLOT_H_
#define PLOT_H_

#include <Window.h>
#include "3d_model/Color.h"
#include "3d_model/BaseObjects.h"

class Axes: private Drawable{
public:
	Axes(Point2d start_pos, x16 horizontal_len, x16 vertical_len);
	virtual ~Axes();

	void draw();
	void set_pos(Point2d start_pos);
	void set_ver_horiz_len(x16 horizontal_len, x16 vertical_len);

private:
	Point2d start_pos;  	// pos of left down cornor
	x16 vertical_len;		//
	x16 horizontal_len;		//
	x16 start_val_x = 0;
	x16 end_val_x = 0;
	x16 start_val_y = 0;
	x16 end_val_y = 0;
	x16 step_x = 10;		// number of x axis reads
	x16 step_y = 10;		// number of y axis reads
	Color color = Color(31, 63, 0);
};

class plot: public Window {
public:
	plot(x16 *arr, x32 *arr_size);
	plot();
	virtual ~plot();

	void draw();
	void set_size(x16 width, x16 height);
	void init();
	void init_axes();
	void update_axes();

private:
	void fill_background();
	void fill_background(Color c);
	x16 get_plot_width();
	x16 get_plot_height();
	x16 get_plot_x();			// left up corner
	x16 get_plot_y();			// left up corner

protected:
	Color *back_color = new Color(2,4,2);
	x16 indent_left = 0;   	// pixels
	x16 indent_right = 0;  	// pixels
	x16 indent_up = 0;     	// pixels
	x16 indent_down = 0;  	// pixels
	x16 indent_axes = 30;
	Axes *axes = nullptr;
};

#endif /* PLOT_H_ */
