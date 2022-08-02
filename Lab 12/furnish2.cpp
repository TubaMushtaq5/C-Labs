

#include<iostream>
#include<cstdlib>
#include"Furnish.cpp" 
#ifndef FURNISH2
#define FURNISH2


using namespace std;

class furnish2: public Furnish{
	public:
	void print(){
		cout << "The room has bed and table furnishing";
	}
};

#endif
