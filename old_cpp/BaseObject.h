/*
 * BaseObject.h
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include <stdint.h>
#include <string>

class BaseObject {
public:
	BaseObject();
	BaseObject(uint16_t posx, uint16_t posy, uint16_t posz);
	virtual ~BaseObject();

	void set_pos(uint16_t posx, uint16_t posy, uint16_t posz);
	void set_pos_x(uint16_t posx);
	uint16_t get_pos_x();
	uint16_t get_pos_y();
	uint16_t get_pos_z();
	void set_scale(uint16_t scale);

private:
	uint16_t posx;
	uint16_t posy;
	uint16_t posz;
	uint16_t scale;
};

#endif /* BASEOBJECT_H_ */
