#include "vecteur.hpp"


void Vecteur3D::init(double x, double y, double z){
	Vecteur3D::x = x;
	Vecteur3D::y = y;
	Vecteur3D::z = z;
}

double Vecteur3D::ProdScalaire(Vecteur3D v1, Vecteur3D v2){
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vecteur3D Vecteur3D::Somme(Vecteur3D v1, Vecteur3D v2){
	Vecteur3D x;
	x.init(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
	return x;
}