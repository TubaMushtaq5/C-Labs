#include<iostream>
#include"Room.cpp"
#ifndef SEPARATEKITCHEN
#define SEPARATEKITCHEN

using namespace std;

class  SeparateKitchen: public Room{
	public:
	void print(){
		cout << "has one large room of size 15 x 15 and separate kitchen of size 6 x 10. ";
	}
};

#endif
