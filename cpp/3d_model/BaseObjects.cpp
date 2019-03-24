/*
 * BaseObjects.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/BaseObjects.h>

Point2d::Point2d() {
	x = 0;
	y = 0;
}

Point2d::~Point2d() {
	// TODO Auto-generated destructor stub
}


Point2d::Point2d(x16 x, x16 y){
	this->x = x;
	this->y = y;
}


Point3d::Point3d() {
	z = 0;
}

Point3d::~Point3d() {
	// TODO Auto-generated destructor stub
}





Polygon::Polygon() {
	points = nullptr;
	p_cnt = 0;
}

Polygon::~Polygon() {
	delete []points;
}
