/*
 * ObjectsDrawable.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/ObjectsDrawable.h>

ObjectsDrawable::ObjectsDrawable() {
	// TODO Auto-generated constructor stub

}

ObjectsDrawable::~ObjectsDrawable() {
	// TODO Auto-generated destructor stub
}

void ObjectsDrawable::add(Object3D *obj){
	this->objects.push_back(obj);
}

void ObjectsDrawable::draw(){
	for(const auto &obj : this->objects){
//		this->draw_vertexs(obj);
		this->draw_edges(obj);
	}
}

void ObjectsDrawable::draw_vertexs(Object3D *obj){
	for(auto it=obj->get_vertex()->begin(); it != obj->get_vertex()->end(); it++){
		this->draw_point(&(*it));
	}
}

void ObjectsDrawable::draw_edges(Object3D *obj){
	uint8_t i;
	for(auto &pol : *obj->get_polygons()){
		for (i = 0; i < pol.p_cnt-1; ++i) {
			this->draw_line(pol.points[i], pol.points[i + 1]);
		}
		this->draw_line(pol.points[i], pol.points[0]);
	}
}

void ObjectsDrawable::draw_polygons(Object3D *obj){
	for(auto it=obj->get_polygons()->begin(); it != obj->get_polygons()->end(); it++){
		this->draw_polygon(&(*it));
	}
}
