#include "Animal.hpp"

int main(){
	Animal a(0, "TA GUEULE");
	Animal b;
	b = a;
	a.presenter();
	b.presenter();
	return 0;
}