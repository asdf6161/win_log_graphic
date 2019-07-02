/*
 * ObjectsDrawable.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef OBJECTSDRAWABLE_H_
#define OBJECTSDRAWABLE_H_

#include "3d_model/DrawableField.h"
#include "3d_model/Object3D.h"
#include <vector>

class ObjectsDrawable : public DrawableField{
public:
	ObjectsDrawable();
	virtual ~ObjectsDrawable();

	void add(Object3D *obj);
	void draw();
	void draw_vertexs(Object3D *obj);
	void draw_edges(Object3D *obj);
	void draw_polygons(Object3D *obj);

private:
	vector<Object3D *> objects;
};

#endif /* OBJECTSDRAWABLE_H_ */
