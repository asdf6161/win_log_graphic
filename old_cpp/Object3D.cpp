/*
 * Object3D.cpp
 *
 *  Created on: 15 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/Object3D.h>

Object3D::Object3D(uint16_t posx, uint16_t posy ,uint16_t posz):BaseObject(posx, posy, posz) {
}

Object3D::Object3D():BaseObject(){

}

Object3D::~Object3D() {
	// TODO Auto-generated destructor stub
	delete tmp;
	delete tmp_polygon;
}

void Object3D::add_vertex(float x, float y, float z){
	this->tmp = new Point3D(x,y,z);
	this->vertex3d.push_back(*this->tmp);
}

void Object3D::add_normal(float x, float y, float z){
	this->tmp = new Point3D(x,y,z);
	this->normal3d.push_back(*this->tmp);
}

void Object3D::add_polygon(uint32_t *vertexs, uint16_t size){
	Point3D **points = new Point3D*[size];
	for (uint8_t i = 0; i < size; ++i) {
		Point3D *p = this->get_vertex(vertexs[i]);
		points[i] = p;
	}
	this->polygons.push_back(Polygon (points, size));
	// Todo - разобраться с указателями
}

Point3D *Object3D::get_vertex(unsigned long num){
	return &(this->vertex3d[num-1]);
}

vector<Polygon> *Object3D::get_polygons(){
	return &this->polygons;
}

vector<Point3D> *Object3D::get_vertex(){
	return &vertex3d;
}

void Object3D::scale(uint16_t scale){
	this->set_scale(scale);
	for(auto it=vertex3d.begin(); it != vertex3d.end(); it++){
		(*it).scale(scale);
	}
}







