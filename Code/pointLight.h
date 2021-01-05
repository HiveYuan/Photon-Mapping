#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light.h" 

class PointLight : public Light {
	Vector3 O;
public:
	PointLight() : Light() {}
	~PointLight() {}
	
	Vector3 GetO() { return O; }
	void Input( std::string , std::stringstream& );
	LightCollider Collide( Vector3 ray_O , Vector3 ray_V );
	Color GetIrradiance( Collider* collider , Primitive* primitive_head , int shade_quality , int* hash );
	Photon EmitPhoton();
};

#endif
