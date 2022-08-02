#include<iostream>
#include"Room.cpp"
#ifndef DOUBLEATTACHED
#define DOUBLEATTACHED

using namespace std;

class DoubleAttached: public Room{
	public:
	void print(){
		cout << "has two large room of size 15 x 15 with attached kitchen and one medium room of size 12 x 12.  ";
	}
};

#endif
