/*
 * ObjectLoader.h
 *
 *  Created on: 17 ���. 2019 �.
 *      Author: yura
 */

#ifndef OBJECTLOADER_H_
#define OBJECTLOADER_H_

#include "Object3D.h"
#include "ReadFile.h"
#include <vector>

class ObjectLoader {
public:
	ObjectLoader();
	virtual ~ObjectLoader();

	Object3D *read_obj(const char *filename);
	vector<string> split(string *str, unsigned char delim);

private:
	ReadFile readFile;

};

#endif /* OBJECTLOADER_H_ */
