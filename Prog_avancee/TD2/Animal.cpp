#include "Animal.hpp"
using namespace std;

Animal::Animal(){
	int age;
	string cri;
	cout << "Age: " << endl;
	cin >> age;
	cout << "Cri :" << endl;
	cin >> cri;
	this->age = age;
	this->cri = cri;
	cout << "Création d'un animal sans paramètres" << endl;
}

Animal::Animal(int age, string cri):age(age), cri(cri){
	cout << "Création d'un animal avec paramètres" << endl;
}

Animal::~Animal(){

}

void Animal::setAge(int age){
	this->age = age;
}

void Animal::setCri(string age){
	this->cri = cri;
}

int Animal::getAge() const{
	return this->age;
}

string Animal::getCri() const{
	return this->cri;
}

void Animal::vieillir(){
	this->age++;
}

void Animal::presenter() const{
	cout << "L'animal a " << this->age << " ans et son cri est " << this->cri << endl;
}