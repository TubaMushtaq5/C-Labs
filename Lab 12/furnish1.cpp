
#include<iostream>
#include<cstdlib>
#include"Furnish.cpp" 
#ifndef FURNISH1
#define FURNISH1


using namespace std;

class Nof: public Furnish{
	public:
	void print(){
		cout << "The room has no furnishing.";
	}
};
#endif
