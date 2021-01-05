#include "rectangle.h"
#include <cmath>
#include<algorithm>
Rectangle::Rectangle() : Primitive() {
	
}

void Rectangle::Input( std::string var , std::stringstream& fin ) {
	if ( var == "N=" ) N.Input( fin );
	if ( var == "R=" ) fin >> R;
	if ( var == "Dx=" ) Dx.Input( fin );
	if ( var == "Dy=" ) Dy.Input( fin );
	Primitive::Input( var , fin );
}

Collider Rectangle::Collide( Vector3 ray_O , Vector3 ray_V ) {
	Collider collider;
	ray_V = ray_V.GetUnitVector();
	N = N.GetUnitVector();
	double d = N.Dot( ray_V );
	if ( fabs( d ) < EPS ) return collider;
	double l = ( N * R - ray_O ).Dot( N ) / d;
	if ( l < EPS ) return collider;

	collider.dist = l;
	collider.front = ( d < 0 );
	collider.C = ray_O + ray_V * collider.dist;
	collider.N = ( collider.front ) ? N : -N;
	double u = collider.C.Dot( Dx ) / Dx.Module2();
	double v = collider.C.Dot( Dy ) / Dy.Module2();
	collider.crash = (0 <= u && u <= 1 && 0 <= v && v <= 1);
	collider.I = ray_V;
	collider.SetPrimitive(this);
	return collider;
}

Color Rectangle::GetTexture(Vector3 C) {
	double u = C.Dot( Dx ) / Dx.Module2();
	double v = C.Dot( Dy ) / Dy.Module2();
	return material->texture->GetSmoothColor( u , v );
}
