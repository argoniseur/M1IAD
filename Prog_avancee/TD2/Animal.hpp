#ifndef ANIMAL__H
#define ANIMAL__H

#include <iostream>
#include <string>
using namespace std;

 class Animal{
	private:
		string cri;
		int age;

	public:
		Animal();
		Animal(int, string);
		virtual ~Animal();

		int getAge() const;
		string getCri() const;
		void setAge(int);
		void setCri(string);
		void vieillir();
		void presenter() const;

};
#endif