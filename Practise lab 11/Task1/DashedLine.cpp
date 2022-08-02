#ifndef DASHEDLINE
#define DASHEDLINE
#include <iostream>

using namespace std;

class DashedLine:public Line{
	public:
	DashedLine(int size) : Line(size){
	}
	
	void draw(){
		for(int i=0;i<size;i++)
			cout << "-";
	}
};

#endif
