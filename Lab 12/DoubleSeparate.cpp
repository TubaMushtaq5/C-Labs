#include<iostream>
#include"Room.cpp"
#ifndef DOUBLESEPARATE
#define DOUBLESEPARATE

using namespace std;

class DoubleSeparate: public Room{
	public:
	void print(){
		cout << " has two medium rooms of size 12 X 12 and separate kitchen of size 8 x 12. ";
	}
};
#endif
