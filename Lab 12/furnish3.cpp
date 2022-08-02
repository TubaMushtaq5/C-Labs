#include"Furnish.cpp" 
#ifndef FURNISH3
#define FURNISH3

#include<iostream>

using namespace std;

class furnish3: public Furnish{
	public:
	void print(){
		cout << "The room has bed, sofa and table furnishing";
	}
};

#endif
