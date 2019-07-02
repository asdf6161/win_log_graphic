/*
 * Object3D.h
 *
 *  Created on: 15 мар. 2019 г.
 *      Author: yura
 */

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "vector"
#include "main.h"
#include "ReadFile.h"
#include "DrawableField.h"
#include "3d_model/BaseElem3D.h"
#include "3d_model/BaseObject.h"

using namespace std;

class Object3D : BaseObject{
public:
	Object3D(uint16_t posx, uint16_t posy ,uint16_t posz);
	Object3D();
	virtual ~Object3D();

	bool open_from_file(const char* filename);

	void add_vertex(float x, float y, float z);
	void add_normal(float x, float y, float z);
	void add_polygon(uint32_t *vertexs, uint16_t size);
	void scale(uint16_t scale);

	Point3D *get_vertex(unsigned long num);
	vector<Point3D> *get_vertex();
	vector<Polygon> *get_polygons();

private:
	vector<Point3D> vertex3d;
	vector<Point3D> normal3d;
	vector<Polygon> polygons;
	Point3D *tmp = nullptr;
	Polygon *tmp_polygon = nullptr;
};

#endif /* OBJECT3D_H_ */
