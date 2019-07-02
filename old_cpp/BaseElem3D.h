/*
 * Vector3D.h
 *
 *  Created on: 16 ���. 2019 �.
 *      Author: yura
 */

#ifndef BASEELEM3D_H_
#define BASEELEM3D_H_

#include "stdint.h"

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////											/////////////////////
/////////////////////////////////////////////////////////////////////////////////////
// Todo - ����������� � ������������
class Point3D {
public:
	Point3D();
	Point3D(float x, float y, float z);
	Point3D(Point3D *p);
	virtual ~Point3D();

	void set_coor(float x, float y, float z);
	void scale(uint16_t scale);

public:
	float x = 0;
	float y = 0;
	float z = 0;
};

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////											/////////////////////
/////////////////////////////////////////////////////////////////////////////////////
class Vector3D {
public:
	Vector3D(Point3D *point_1, Point3D *point_2);
	virtual ~Vector3D();

public:
	Point3D *point_1;
	Point3D *point_2;
};

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////											/////////////////////
/////////////////////////////////////////////////////////////////////////////////////
class Polygon {
public:
	Polygon(Point3D **points, uint8_t p_cnt);

	virtual ~Polygon();

	uint8_t size();

public:
	Point3D **points = nullptr;
	uint8_t p_cnt;
};

#endif /* BASEELEM3D_H_ */
