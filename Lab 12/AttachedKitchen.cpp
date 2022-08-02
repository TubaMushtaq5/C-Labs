#include<iostream>
#include"Room.cpp"
#ifndef ATTACHEDKITCHEN
#define ATTACHEDKITCHEN

using namespace std;

class AttachedKitchen: public Room{
	public:
	void print(){
		cout << "has one very large room of size 15 x 18 with attached kitchen. ";
	}
};

#endif
