/*
 * BaseObject.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <3d_model/BaseObject.h>

BaseObject::BaseObject() {
	set_pos(0, 0, 0);
	set_scale(1);
}

BaseObject::BaseObject(uint16_t posx, uint16_t posy, uint16_t posz){
	set_pos(posx, posy, posz);
	set_scale(1);
}

BaseObject::~BaseObject() {
	// TODO Auto-generated destructor stub
}


void BaseObject::set_pos(uint16_t posx, uint16_t posy, uint16_t posz){
	this->posx = posx;
	this->posy = posy;
	this->posz = posz;
}

void BaseObject::set_pos_x(uint16_t posx){
	this->posx = posx;
}

void BaseObject::set_scale(uint16_t scale){
	this->scale = scale;
}

uint16_t BaseObject::get_pos_x(){
	return posx;
}

uint16_t BaseObject::get_pos_y(){
	return posy;
}

uint16_t BaseObject::get_pos_z(){
	return posz;
}
