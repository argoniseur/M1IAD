#include "vecteur.hpp"
using namespace std;

int main(){
	Vecteur3D a, b, c;
	a.init();
	a.affiche();

	b.init(12.5, 3.8, 4.5);
	b.affiche();

	c.init(13.7, 5, 0);
	c.affiche();

	
}