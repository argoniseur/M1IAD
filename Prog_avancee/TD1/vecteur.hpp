#ifndef VECTEUR
#define VECTEUR

#include <iostream>
using namespace std;

class Vecteur3D {
	private:
		double x;
		double y;
		double z;

	public:

		void init(double x=0.0, double y=0.0, double z=0.0);

		inline void affiche() const{
			cout<<"Coordonnees : ("<<x<<", "<<y<<", "<<z<<")"<<endl;
		}

		double ProdScalaire(Vecteur3D v1, Vecteur3D v2);

		Vecteur3D Somme(Vecteur3D v1, Vecteur3D v2);
};
#endif