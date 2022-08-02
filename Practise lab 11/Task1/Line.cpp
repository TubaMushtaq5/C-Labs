#ifndef LINE
#define LINE

#include <iostream>

using namespace std;

class Line{
	protected:
	int size;
	
	public:
	Line(int size){
		setsize(size);
	}
	
	void setsize(int size){
		this->size=size;
	}
	
	virtual void draw(){}
};

#endif
