#ifndef DISTANTDASHEDLINE
#define DISTANTDASHEDLINE

#include <iostream>

using namespace std;

class DistantDashedLine:public Line{
	public:
	DistantDashedLine(int size) : Line(size){
	}
	
	void draw(){
		for(int i=0;i<size;i++)
			cout << "- ";
	}
};

#endif
