/*
 * ObjectLoader.cpp
 *
 *  Created on: 17 мар. 2019 г.
 *      Author: yura
 */

#include <ObjectLoader.h>

ObjectLoader::ObjectLoader() {
	// TODO Auto-generated constructor stub

}

ObjectLoader::~ObjectLoader() {
	// TODO Auto-generated destructor stub
}


Object3D *ObjectLoader::read_obj(const char *filename){
	Object3D *obj = new Object3D();
 	if (readFile.open(filename, FA_READ) != FR_OK){
 		return obj;
 	}

	string line1;			// readed line
	vector<string> res;  	// split res
	while(!readFile.file_is_end()){
		line1 = readFile.read_line();

		// split line
		res = split(&line1, ' ');

		if (res[0] == "vn"){  // normal
			/*obj->add_normal(std::stof(s_arr[1]),
							  std::stof(s_arr[2]),
							  std::stof(s_arr[3]));*/
		}
		else if (res[0] == "vt"){

		}
		else if (res[0] == "v"){  // vertex
			obj->add_vertex(std::stof(res[1]),
							 std::stof(res[2]),
							 std::stof(res[3]));
		}
		else if (res[0] == "f"){  // faces
			uint32_t vertex_arr[res.size()-1];
			for (uint8_t i = 0; i < res.size()-1; ++i) {
				vertex_arr[i] = std::stof(res[i + 1]);
			}
			obj->add_polygon(vertex_arr, res.size()-1);
		}
	}
	return obj;
}

vector<string> ObjectLoader::split(string *str, unsigned char delim){
	vector<string> res = vector<string>();
	string tmp = "";
	for(const auto &ch: *str){
		if (ch == '\n'){
			continue;
		}
		if (ch == delim){
			res.push_back(tmp);
			tmp = "";
		} else {
			tmp += ch;
		}
	}
	res.push_back(tmp);
	return res;
}
