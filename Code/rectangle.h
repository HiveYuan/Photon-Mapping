#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "primitive.h"

class Rectangle : public Primitive {
	Vector3 N , Dx , Dy;
	double R;

public:
	Rectangle();
	~Rectangle() {}

	void Input( std::string , std::stringstream& );
	Collider Collide( Vector3 ray_O , Vector3 ray_V );
	Color GetTexture(Vector3 C);
};

#endif
