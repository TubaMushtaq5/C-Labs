#ifndef DOTTEDLINE
#define DOTTEDLINE

#include <iostream>

using namespace std;

class DottedLine:public Line{
	public:
	DottedLine(int size) : Line(size){
	}
	
	void draw(){
		for(int i=0;i<size;i++)
			cout << "-  ";
	}
};

#endif
