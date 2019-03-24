/*
 * Color.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "stdint.h"

typedef uint32_t x32;
typedef uint8_t x8;

#define COLOR_MAX_R 0x1F
#define COLOR_MAX_G 0x3F
#define COLOR_MAX_B 0x1F

class Color {
public:
	Color();
	Color(x32 c);
	Color(x8 r, x8 g, x8 b);
	virtual ~Color();

	x32 get_color();
	static x32 get_color(x8 r, x8 g, x8 b);
	void set_color(x32 color);
	void set_color(x8 r, x8 g, x8 b);

public:
	x8 r = 0;
	x8 g = 0;
	x8 b = 0;
};

#endif /* COLOR_H_ */
