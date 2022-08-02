#ifndef DOUBLEDASHEDLINE
#define DOUBLEDASHEDLINE

#include <iostream>

using namespace std;

class DoubleDashedLine:public Line{
	public:
	DoubleDashedLine(int size) : Line(size){
	}
	
	void draw(){
		for(int i=0;i<size;i++)
			cout << "=";
	}
};

#endif
