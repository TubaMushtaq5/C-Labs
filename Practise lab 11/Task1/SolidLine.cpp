#ifndef SOLIDLINE
#define SOLIDLINE
#include <iostream>

using namespace std;

class SolidLine:public Line{
	public:
	SolidLine(int size) : Line(size){
	}
	
	void draw(){
		for(int i=0;i<size;i++)
			cout << "_";
	}
};

#endif
