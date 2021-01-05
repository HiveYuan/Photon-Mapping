#include "pointLight.h"
#include<algorithm>
void PointLight::Input( std::string var , std::stringstream& fin ) {
	if ( var == "O=" ) O.Input( fin );
	Light::Input( var , fin );
}

LightCollider PointLight::Collide( Vector3 ray_O , Vector3 ray_V ) {
	LightCollider ret;
	ret.SetLight(this);
	return ret;
}

Photon PointLight::EmitPhoton() {
	Photon ret;
	ret.power = color / color.Power();
	ret.pos = O;
	ret.dir.AssRandomVector();
	return ret;
}

Color PointLight::GetIrradiance( Collider* collider , Primitive* primitive_head , int shade_quality , int* hash ) {
	Primitive* pri = collider->GetPrimitive();
	Vector3 V = O - collider->C;
	double dist = V.Module();

	for ( Primitive* now = primitive_head ; now != NULL ; now = now->GetNext() ) {
		Collider thisCollider = now->Collide(collider->C, V);
		if ( thisCollider.crash && thisCollider.dist < dist ) return Color();
	}

	return CalnIrradiance( collider , V , hash );
}
