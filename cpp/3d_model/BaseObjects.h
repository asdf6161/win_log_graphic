/*
 * BaseObjects.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef BASEOBJECTS_H_
#define BASEOBJECTS_H_

#include "stdint.h"

typedef uint16_t x16;
typedef uint8_t x8;




class Point2d {
public:
	Point2d();
	Point2d(x16 x, x16 y);
	virtual ~Point2d();

public:
	x16 x;
	x16 y;
};





class Point3d : public Point2d{
public:
	Point3d();
	virtual ~Point3d();

public:
	x16 z;
};





class Polygon{
public:
	Polygon();
	virtual ~Polygon();

public:
	Point3d *points;
	x8 p_cnt;
};

#endif /* BASEOBJECTS_H_ */
